import re
def password_strength(password):
    if len(password)<8:
        return "weak: password is too short"
    
    has_lowercase = any(char.islower() for char in password)
    has_uppercase = any(char.isupper() for char in password)
    has_digit = any(char.isdigit() for char in password)
    has_special = any(char in '!@#$,.:<>?' for char in password)

    complexity = sum([has_lowercase,has_uppercase,has_digit,has_special])

    if complexity<3:
        return "weak:password lacks complexity"
    
    common_patterns = [r'123',r'abc',r'111']

    for pattern in common_patterns:
        if re.search(pattern,password,re.IGNORECASE):
            return "weak password contains common patterns"
        return "strong password"
    
password = input("Enter the password\n")
print(password_strength(password))