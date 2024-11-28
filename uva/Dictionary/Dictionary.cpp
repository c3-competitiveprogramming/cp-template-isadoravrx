#include <iostream>
#include <string>
using namespace std;

int main() {
    string lastword, s;
    int leadingspaces, i, t;

        while (getline(cin, s)) {
            if (s[0] != lastword[0]) {
                lastword = s;
                cout << s << endl;
                leadingspaces = 0;
                i = 0;
            } else {
                leadingspaces++;

                if (i < s.size() && i < lastword.size() && s[i] == lastword[i]) {
                    i++;
                } else if (i >= lastword.size()) {
                    leadingspaces--;
                } else {
                    leadingspaces -= i;
                    i = leadingspaces;
                }

                cout << string(leadingspaces, '.') << s << endl;
                lastword = s;
            }
        }

    return 0;
}