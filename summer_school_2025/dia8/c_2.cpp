#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int n,m;
string increment_string(string s){
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '9'){
        s[i] = '0';
        i--;
    }

    if(i < 0){
        s.insert(0,1,'1');
    }else{
        s[i]++;
    }

    return s;
}

ll sumIsolated(string s){
    ll sum = 0;

    for(int i = 0; i < s.size(); i++){
        sum += s[i] - '0';
    }

    return sum;
}


int main(){
    
    cin >> n >> m;

    string s = to_string(n);

    while(true){
        ll sum = sumIsolated(s);
        if(sum >= n && sumIsolated(to_string(2*sum))){
            break;
        }   
        s = increment_string(s);
    }
    cout << s << endl;
    cout << s << endl;
}