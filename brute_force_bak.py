from itertools import product

def gen_pswd_combos(knwn, lngt):
    """
    Generate possible pswds with given known char(s) and length.

    :param known: any known part of the pswd (e.g., '555' for '555-XXXX').
    :param length: The total length of the pswd.
    :return: Generator of possible pswd.
    """
    unknwn_lngt = lngt - len(knwn)
    digits = '0123456789'

    for combinations in product(digits, repeat=unknwn_lngt):
        yield knwn + ''.join(combinations)

def main():
    knwn = "555"  # Known prefix of the password
    lngt = 7      # Total length of the password (e.g., 7 for '555-XXXX')

    def is_rl_pswd(pswd, rl_pswd):

        knwn = input("Enter the known prefix of the phone number: ")
        lngt = int(input("Enter the total length of the phone number: "))
        rl_pswd = input("Enter the correct phone number for the script to find: ")
    
        return pswd == rl_pswd


    rl_pswd = "5551234"  # The correct password for the script to find
    lngt = 7      # Total length of the phone number (e.g., 7 for '555-XXXX')
    combos = gen_pswd_combos(knwn, lngt)

    for pswd in combos:
        print(f"Trying pswd: {pswd}")
        # Here, you can add your own logic to check the password
        # For example, send a test login or check in a database
        if is_rl_pswd(pswd, rl_pswd):
            print(f"Correct password found: {rl_pswd}. Pretending to accept the login.")
            break
        if __name__ == "__main__":
            main()
