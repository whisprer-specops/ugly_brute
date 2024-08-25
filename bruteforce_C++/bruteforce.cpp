S#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

// List of top 50 most common passwords
std::vector<std::string> common_passwords = {
    "123456", "password", "12345678", "qwerty", "123456789", "12345", "1234", "111111",
    "1234567", "dragon", "123123", "baseball", "abc123", "football", "monkey", "letmein",
    "696969", "shadow", "master", "666666", "qwertyuiop", "123321", "mustang", "1234567890",
    "michael", "654321", "superman", "1qaz2wsx", "7777777", "121212", "000000", "qazwsx",
    "123qwe", "killer", "trustno1", "jordan", "jennifer", "zxcvbnm", "asdfgh", "hunter",
    "buster", "soccer", "harley", "batman", "andrew", "tigger", "sunshine", "iloveyou", "2000"
};

void gen_pswd_combos(const std::string& knwn, int lngt, std::vector<std::string>& combos) {
    int unknwn_lngt = lngt - knwn.size();
    std::string characters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+[]{}|;:,.<>?/~`";
    
    int total_combinations = std::pow(characters.size(), unknwn_lngt);

    for (int i = 0; i < total_combinations; ++i) {
        std::string combo = knwn;
        int num = i;
        for (int j = 0; j < unknwn_lngt; ++j) {
            combo += characters[num % characters.size()];
            num /= characters.size();
        }
        combos.push_back(combo);
    }
}

bool is_rl_pswd(const std::string& pswd, const std::string& rl_pswd) {
    return pswd == rl_pswd;
}

int main() {
    std::string knwn;
    int lngt;
    std::string rl_pswd;
    
    std::cout << "Enter the known prefix of the password: ";
    std::cin >> knwn;
    std::cout << "Enter the total length of the password: ";
    std::cin >> lngt;
    std::cout << "Enter the real password for the script to find: ";
    std::cin >> rl_pswd;
    
    std::cout << "Known part of password: " << knwn << std::endl;
    std::cout << "Total length of password: " << lngt << std::endl;
    std::cout << "Actual real password to work from: " << rl_pswd << std::endl;
    
    auto start_time = std::chrono::high_resolution_clock::now();  // Start timing
    
    // First, try the common passwords from the wordlist
    for (size_t i = 0; i < common_passwords.size(); ++i) {
        std::cout << "Trying common password " << i << ": " << common_passwords[i] << std::endl;
        if (is_rl_pswd(common_passwords[i], rl_pswd)) {
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time;
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time);
            std::cout << "Correct password found: " << common_passwords[i] << ". Pretending to accept the login." << std::endl;
            std::cout << "Elapsed time: " << duration.count() / 1000.0 << " seconds" << std::endl;
            return 0;
        }
    }

    // If not found in common passwords, try the generated combinations
    std::vector<std::string> combos;
    gen_pswd_combos(knwn, lngt, combos);
    for (size_t i = 0; i < combos.size(); ++i) {
        std::cout << "Combo " << i << ": " << combos[i] << std::endl;
        std::cout << "Trying password: " << combos[i] << std::endl;
        if (is_rl_pswd(combos[i], rl_pswd)) {
            auto elapsed_time = std::chrono::high_resolution_clock::now() - start_time;
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time);
            std::cout << "Correct password found: " << rl_pswd << ". Pretending to accept the login." << std::endl;
            std::cout << "Elapsed time: " << duration.count() / 1000.0 << " seconds" << std::endl;
            break;
        }
    }

    return 0;
}