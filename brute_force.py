from itertools import product

def gen_pswd_combos(knwn, lngt):
    
#
#   Generate possible pswds with given known char(s) and length.
#
#   :param known: any known part of the pswd (e.g., '555' for '555-XXXX').
#   :param length: The total length of the pswd.
#   :return: Generator of possible pswd.
#
    
    unknwn_lngt = lngt - len(knwn)
    digits = '0123456789'
    print(f"unknown length: {unknwn_lngt},")

    for combos in product(digits, repeat=unknwn_lngt):
        yield knwn + ''.join(combos)


def main():
 knwn = (int(input("Enter the knwn prefix of the password: ")))
 lngt = (int(input("Enter the total lngt of the password: ")))
 rl_pswd = (int(input("Enter the rl_pswd for the script to find: ")))
print(f"Known part of password: {knwn}")
print(f"Total length of password: {lngt}")
print(f"Actual real password to work from: {rl_pswd}")

gen_pswd_combos = (knwn, lngt)
    # knwn = "555"  # Known prefix of the password
    # lngt = 7      # Total length of the password (e.g., 7 for '555-XXXX')
    
    # rl_pswd = "5551234"  # The correct password for the script to find
    # lngt = 7      # Total length of the phone number (e.g., 7 for '555-XXXX')
combos = gen_pswd_combos(knwn, lngt)
for i, combo in combos:
    print(f"Combo {i}: {combo}\n")

def is_rl_pswd(pswd, rl_pswd):

        return pswd == rl_pswd

for pswd in combos:
        print(f"Trying pswd: {pswd}")
        # Here, you can add your own logic to check the password
        # For example, send a test login or check in a database
        if is_rl_pswd(pswd, rl_pswd):
            print(f"Correct password found: {rl_pswd}. Pretending to accept the login.")
            break
if __name__ == "__main__":
    main()
