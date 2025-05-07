//salem
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
string s = "";

void to_binary(ll num){
    if(num == 1){
        s.push_back('1');
        return;
    }

    to_binary(num/2);
    string temp = to_string(num % 2);
    s += temp;
}

int main(){
    ll t;
    cin >> t;

    map<ll,string>conversion;
    for(int i = 1; i<= 10000; i++){
        s = "";
        to_binary(i);
        while(s.size() < 14){
            string temp = "0";
            s = temp + s;
        }
        conversion[i] = s;
    }
    while (t--){
        ll n;
        cin >> n;

        vector<string>v(n);
        ll num;
        for(ll i = 0; i < n;  i++){
            cin >> num;
            v[i] = conversion[num];
        }

        int maxh = 0;
        for(int i = 0; i < n ; i++){
            for(int j = i+1; j < n; j++){
                int index = 0;
                int cont = 0;
               
                while(index < v[i].size()){
                    if(v[i][index] != v[j][index]){
                        cont++;
                    }
                    index++;
                }

                maxh = max(maxh,cont);
            }
        }

        cout << maxh << endl;

    }
    
}