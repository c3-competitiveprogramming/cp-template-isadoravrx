#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int m;


bool correctsum(string a, string b){
    ll sum = stoll(a);

    for(int i = 0; i < b.size(); i++){
        sum += b[i] - '0';
    }

    string sumstring = to_string(sum);
    sum = 0;

    for(int i = 0; i < sumstring.size(); i++){
        sum += sumstring[i] - '0';
    }

    if(sum <= m){
        return true;
    }

    return false;
}   

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

int main(){
    int n; 
    cin >> n >> m;

    string a = to_string(n);
    string b = a;


    while(!correctsum(a,b)){
        b = increment_string(b);
    }

    cout << a << endl;
    cout << b << endl;
}