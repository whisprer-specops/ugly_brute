# curious as to ho secure your pswd realy is?

import time
from itertools import product

# List of top 50 most common passwords
common_passwords = [
    "123456", "password", "12345678", "qwerty", "123456789", "12345", "1234", "111111",
    "1234567", "dragon", "123123", "baseball", "abc123", "football", "monkey", "letmein",
    "696969", "shadow", "master", "666666", "qwertyuiop", "123321", "mustang", "1234567890",
    "michael", "654321", "superman", "1qaz2wsx", "7777777", "121212", "000000", "qazwsx",
    "123qwe", "killer", "trustno1", "jordan", "jennifer", "zxcvbnm", "asdfgh", "hunter",
    "buster", "soccer", "harley", "batman", "andrew", "tigger", "sunshine", "iloveyou", "2000"
]

def gen_pswd_combos(knwn, lngt):
    
    unknwn_lngt = lngt - len(knwn)
    digits = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+[]{}|;:,.<>?/~`'
    print(f"unknown length: {unknwn_lngt},")

    for combos in product(digits, repeat=unknwn_lngt):
        yield knwn + ''.join(combos)

def is_rl_pswd(pswd, rl_pswd):
    return pswd == rl_pswd

def main():
    knwn = input("Enter the knwn prefix of the password: ")
    lngt = int(input("Enter the total lngt of the password: "))
    rl_pswd = input("Enter the rl_pswd for the script to find: ")
    
    print(f"Known part of password: {knwn}")
    print(f"Total length of password: {lngt}")
    print(f"Actual real password to work from: {rl_pswd}")
    
    start_time = time.time()  # Start timing

# First, try the common passwords from the wordlist
    for i, common_pswd in enumerate(common_passwords):
        print(f"Trying common password {i}: {common_pswd}")
        if is_rl_pswd(common_pswd, rl_pswd):
            elapsed_time = time.time() - start_time  # Calculate elapsed time
            print(f"Correct password found: {common_pswd}. Pretending to accept the login.")
            print(f"Elapsed time: {elapsed_time:.2f} seconds")
            return
        

   # If not found in common passwords, try the generated combinations
    combos = gen_pswd_combos(knwn, lngt)
    for i, combo in enumerate(combos):
        print(f"Combo {i}: {combo}\n")
        print(f"Trying pswd: {combo}")
        if is_rl_pswd(combo, rl_pswd):
            elapsed_time = time.time() - start_time  # Calculate elapsed time
            print(f"Correct password found: {rl_pswd}. Pretending to accept the login.")
            print(f"Elapsed time: {elapsed_time:.2f} seconds")
            break

if __name__ == "__main__":
    main()