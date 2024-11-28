#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<long long,int>mp;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        if(mp.find(num) != mp.end()){
            if(mp[num] == -1){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }else{

            long long raiz = sqrt(num);
            double raizdoub = sqrt(num);

            bool isprime = true;
            for(int j = 2; j * j <= raiz; j++){
                if(raiz % j == 0){
                    isprime = false;
                    break;
                }
            }

            if(isprime && num != 1 && raiz == raizdoub){
                cout << "YES" << endl;
                mp[num] = 1;
            }else{
                cout << "NO" << endl;
                mp[num] = -1;
            }

        }
    }
}
