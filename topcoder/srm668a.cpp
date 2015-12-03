#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VerySecureEncryption {
public:
    string encrypt(string message, vector <int> key, int K) {
        for (int i = 0; i < K; ++i) {
            string message2(message.size(), ' ');
            for (int j = 0; j < message.size(); ++j) {
                message2[key[j]] = message[j];
            }
            message = message2;
        }
        return message;
    }
};