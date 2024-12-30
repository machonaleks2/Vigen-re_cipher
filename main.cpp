#include <iostream>
#include <string>

int main() {
    std::string message = "gwox{RgqssihYspOntqpxs}";
    std::string key = "blorpy";
    int key_len = key.length();
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    int not_used = 0;

    for (size_t i = 0; i < message.length(); i++) {
        char char_message = tolower(message[i]);

        if (alphabet.find(char_message) != std::string::npos) {
            int col = alphabet.find(tolower(key[(i - not_used) % key_len]));
            int distance = 0;

            while (alphabet[(col + distance) % 26] != char_message) {
                distance++;
            }

            result += alphabet[distance];
        } else {
            result += message[i];
            not_used++;
        }
    }

    std::cout << result << std::endl;
    return 0;
}




