#include <iostream>
#include <string>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    string n;
    int c = 0;
    while(true){
        cin >> n;

        if(n == "0"){
            break;
        }
        
        cout << "Original number was " << stoi(n) << endl;
       
        map<ll,ll>mp;
        int cont = 0;
        int ans = stoi(n);
        
        bool primeiro = true;
        while(mp.find(ans) == mp.end()){
            cont++;
            
            if(!primeiro){
                mp[ans] = 1;
            }
            
            primeiro = false;
            string temp = to_string(ans);
            sort(temp.begin(),temp.end());
            
            string temp2 = temp;
            reverse(temp2.begin(),temp2.end());
            

            int a = stoi(temp2);
            int b = stoi(temp);
            ans = a  - b;
            cout << a <<" - " << b << " = " << ans << endl;
        }


        cout << "Chain length " << cont << endl; 
        cout << endl;
    }
}
