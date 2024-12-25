def xor_encrypt_decrypt(input_string, key):
    input_bytes = bytearray(input_string, 'utf-8')
    print("input bytes :",input_bytes) 
    
    output_bytes = bytearray([byte ^ key for byte in input_bytes])
    return output_bytes.decode('utf-8', 'ignore')

key = 123 # XOR key (any integer value)
original_text = input("Enter the message\n")
encrypted_text = xor_encrypt_decrypt(original_text, key)
print(f"Encrypted: {encrypted_text}")
decrypted_text = xor_encrypt_decrypt(encrypted_text, key)
print(f"Decrypted: {decrypted_text}")