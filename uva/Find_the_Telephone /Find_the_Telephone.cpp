#include <iostream>
using namespace std;

int main() {
    string str;

    while (cin >> str) {
        string phone = "";
        
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '-' || str[i] == '1' || str[i] == '0') {
                phone += str[i];
            } else if (str[i] == 'A' || str[i] == 'B' || str[i] == 'C') {
                phone += '2';
            } else if (str[i] == 'D' || str[i] == 'E' || str[i] == 'F') {
                phone += '3';
            } else if (str[i] == 'G' || str[i] == 'H' || str[i] == 'I') {
                phone += '4';
            } else if (str[i] == 'J' || str[i] == 'K' || str[i] == 'L') {
                phone += '5';
            } else if (str[i] == 'M' || str[i] == 'N' || str[i] == 'O') {
                phone += '6';
            } else if (str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S') {
                phone += '7';
            } else if (str[i] == 'T' || str[i] == 'U' || str[i] == 'V') {
                phone += '8';
            } else {
                phone += '9';
            }
        }
        cout << phone << endl;
    }
    return 0;
}