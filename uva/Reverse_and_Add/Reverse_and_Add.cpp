#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

bool isPalindrome(ll n){
    string s = to_string(n);
    int i = 0;
    int j = s.size() - 1;

    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}



ll reverseNumber(ll n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    ll reversedN = stoll(s);
    return reversedN;
}

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        
        int cont = 0;
        while(!isPalindrome(n)){
            ll reverse = reverseNumber(n);
            cont++;
            n += reverse;
        }


        cout << cont << " " << n << endl;
    }
}