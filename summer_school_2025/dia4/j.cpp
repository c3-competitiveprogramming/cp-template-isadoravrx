#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;

    cin >> n;
    string s;

    map<char,string>mp;    
    vector<string>v;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
        mp[s[0]] = s;
    }

    bool b = true;
    int index = 0;
    for(int i = 0; i < n; i++){
        b = true;
        for(int j = 0; j < v[i].size(); j++){
            if(mp.find(v[i][j]) == mp.end()){
                b = false;
            }
        }

        if(b){
            index = i;
            break;
        }
    }

    if(b){
        cout << v[index].size() << endl;
        for(int i = 0; i < v[index].size(); i++){
            cout << mp[v[index][i]] << " ";
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    
}