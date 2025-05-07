#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ll t, n, s, num, currsum;
    bool exists;
    
    cin >> t;

    while (t--) {
        currsum = 0;
        vector<ll> a;
        exists = false;

        cin >> n >> s;
        
        for (ll i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);

            if (s == 0 && num == 0) {
                exists = true;
            } else if (s == 0 && num != 0) {
                continue;
            }
            if (!exists) {
                currsum += num;
                if (currsum > s) {
                    while (currsum > s) {
                        currsum -= a[0];
                        a.erase(a.begin());
                    }
                }
                if (currsum == s) {
                    exists = true;
                }
            }
        }
        if (exists) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}