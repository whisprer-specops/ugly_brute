#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;
using namespace std::chrono;

// List of top 50 most common passwords
vector<string> common_passwords = {
    "123456", "password", "12345678", "qwerty", "123456789", "12345", "1234", "111111",
    "1234567", "dragon", "123123", "baseball", "abc123", "football", "monkey", "letmein",
    "696969", "shadow", "master", "666666", "qwertyuiop", "123321", "mustang", "1234567890",
    "michael", "654321", "superman", "1qaz2wsx", "7777777", "121212", "000000", "qazwsx",
    "123qwe", "killer", "trustno1", "jordan", "jennifer", "zxcvbnm", "asdfgh", "hunter",
    "buster", "soccer", "harley", "batman", "andrew", "tigger", "sunshine", "iloveyou", "2000"
};

vector<string> gen_pswd_combos(const string &knwn, int lngt) {
    int unknwn_lngt = lngt - knwn.length();
    string digits = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+[]{}|;:,.<>?/~`";
    vector<string> combos;

    int num_combos = pow(digits.length(), unknwn_lngt);
    combos.reserve(num_combos);

    for (int i = 0; i < num_combos; ++i) {
        string combo = knwn;
        int num = i;
        for (int j = 0; j < unknwn_lngt; ++j) {
            combo += digits[num % digits.length()];
            num /= digits.length();
        }
        combos.push_back(combo);
    }
    return combos;
}

bool is_rl_pswd(const string &pswd, const string &rl_pswd) {
    return pswd == rl_pswd;
}

int main() {
    string knwn, rl_pswd;
    int lngt;

    cout << "Enter the known prefix of the password: ";
    cin >> knwn;
    cout << "Enter the total length of the password: ";
    cin >> lngt;
    cout << "Enter the real password for the script to find: ";
    cin >> rl_pswd;

    cout << "Known part of password: " << knwn << endl;
    cout << "Total length of password: " << lngt << endl;
    cout << "Actual real password to work from: " << rl_pswd << endl;

    auto start_time = high_resolution_clock::now();

    // First, try the common passwords from the wordlist
    for (size_t i = 0; i < common_passwords.size(); ++i) {
        cout << "Trying common password " << i << ": " << common_passwords[i] << endl;
        if (is_rl_pswd(common_passwords[i], rl_pswd)) {
            auto elapsed_time = duration_cast<seconds>(high_resolution_clock::now() - start_time).count();
            cout << "Correct password found: " << common_passwords[i] << ". Pretending to accept the login." << endl;
            cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
            return 0;
        }
    }

    // If not found in common passwords, try the generated combinations
    vector<string> combos = gen_pswd_combos(knwn, lngt);
    for (size_t i = 0; i < combos.size(); ++i) {
        cout << "Combo " << i << ": " << combos[i] << endl;
        cout << "Trying password: " << combos[i] << endl;
        if (is_rl_pswd(combos[i], rl_pswd)) {
            auto elapsed_time = duration_cast<seconds>(high_resolution_clock::now() - start_time).count();
            cout << "Correct password found: " << rl_pswd << ". Pretending to accept the login." << endl;
            cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
            break;
        }
    }

    return 0;
}
