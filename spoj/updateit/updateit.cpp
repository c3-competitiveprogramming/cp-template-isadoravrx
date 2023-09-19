#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, u;
        cin >> n >> u;

        vector<int>v;
        v.assign(n,0);

        for(int i = 0; i < u; i++){
            int l, r, d;
            cin >> l >> r >> d;
            v[l] += d;
            if(r + 1 < n){
                v[r+1] -= d;
            }
        }
        
        for(int i = 1; i < n; i++ ){
            v[i] = v[i-1] + v[i];
        }
        
        int c;
        cin >> c;
        for(int i = 0; i < c; i++){
            int req;
            cin >> req;
            if(i == u -1){
                cout << v[req] << endl;
                break;
            }

            cout << v[req] << " ";
        }
    }
}
