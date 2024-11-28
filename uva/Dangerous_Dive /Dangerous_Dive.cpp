#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, r, pessoa;
   

    while (cin >> n >> r) {
        map<int, int> mp;
        for (int i = 0; i < r; i++){
            cin >> pessoa;
            mp[pessoa] = 1;
        }

        if (n == r){
            cout << "*" << endl;
            continue;
        }

        for (int i = 1; i <= n; i++){
            if (mp.find(i) == mp.end()){ 
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}