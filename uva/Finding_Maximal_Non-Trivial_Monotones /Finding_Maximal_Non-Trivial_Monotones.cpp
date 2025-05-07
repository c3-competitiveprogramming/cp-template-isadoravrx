#include <iostream>
using namespace std;

int i = 0, cont = 0, n;

void temA (string s) {
    if (i == n-1 || (i != n-1 && s[i+1] != 'a')) {
        i++;
        return;
    }
    while (s[i] == 'a') {
        cont++;
        i++;
    }
} 

int main() {
    cin >> n;
    string s;
    cin >> s;

    while (i < n) {
        if (s[i] == 'a') {
            temA(s);
        } else {
            i++;
        }
    }
     
    cout << cont << endl;

    return 0;
}