#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, s, r, maxsum = 0, cont = 0;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> s >> r;
        if (maxsum < s+r) {
            maxsum = s+r;
            cont++;
            mp[i] = cont;
        } else if (maxsum == s+r) {
            mp[i] = cont;
        }
    }

    int espaco = 0;
    for (auto it : mp) {
        if (it.second == cont) {
            if(espaco != 0){
                cout << " ";
            }
            cout << it.first;
            espaco++;
        }
    }
    cout << endl;

    return 0;
}