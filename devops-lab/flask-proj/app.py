import os
from flask import Flask
from dotenv import load_dotenv
from flask import request

load_dotenv()

app = Flask(__name__)

@app.route('/')
def home():
    return "Hello devops"

@app.route('/health')
def health_route():
    return{"status":"running properly","code":200}

@app.route('/test', methods=['POST'])
def test():
    data = request.get_json()
    name = data.get('name', '')
    return {"message": f"your name is {name}"}

if __name__ == "__main__":
    port = int(os.getenv("FLASK_PORT",5002))
    app.run(host='0.0.0.0', port=port)