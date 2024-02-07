#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;

int main(){
    cin >> s;
    
    string aux = s;
    string ans;
    
    reverse(aux.begin(),aux.end());
    if(aux == s){
        cout << s << endl;
        return 0;
    }

    for(int i = s.size() -1; i >= 0; i++){
        string temp = s.substr(0,i+1);
        aux = s + temp;

        string aux2 = aux;
        reverse(aux2.begin(),aux2.end());

        if(aux == aux2){
            ans = aux;
        }
    }
    

    cout << ans << endl;
}
