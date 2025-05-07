#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int l, u;
        cin >> l >> u;

        int lastprime = -1;
        map<int,int>mp;
        
        int mx = 0, ans;
        for(int i = l; i <= u; i++){
            bool b = true;
            
            if(i == 0 || i == 1) {
                b = false;
            }

            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    b = false;
                    break;
                }
            }

            if(b){
                if(lastprime == -1){
                    lastprime = i;
                    continue;
                   
                }else{
                    mp[i-lastprime]++;
                    if(mp[i-lastprime] > mx){
                        mx = mp[i-lastprime];
                        ans = i-lastprime;
                    }
                    lastprime = i;
                }
            }
        }
        

        bool repetiu = false;
        for(auto i  : mp){
            if(i.second == mx && i.first != ans){
                repetiu = true;
                break;
            }
        }

        if(repetiu || mx == 0){
            cout << "No jumping champion" << endl;
        }else{
            cout << "The jumping champion is " << ans << endl;
        }
    }
}
