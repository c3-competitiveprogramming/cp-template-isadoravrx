#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool todosMaiorIgual(vector<int>&v1, vector<int>&v2, string s1){
    
    for(int i = 0; i < s1.size(); i++){
        if(v2[s1[i] - 'a'] < v1[s1[i] - 'a']){
            return false;
        }
    }

    return true;
}


int main(){
    string s;
    vector<string>v;
    map<string,vector<int> >mp;
    
    while(cin >> s){
        v.push_back(s);
        vector<int>alf(26);

        string temp = s;
        for(int j = 0; j < temp.size(); j++){
            alf[temp[j] - 'a']++;
        }

        mp[temp] = alf;
    }

    vector<string>ans;
    for(int i = 0; i < v.size(); i++){
        bool b = true;
        for(int j = 0; j < v.size(); j++){
            if(i == j || v[i].size() > v[j].size()){
                continue;
            }
            if(todosMaiorIgual(mp[v[i]], mp[v[j]], v[i])){
                b = false;
                break; 
            }
        }

        if(b){
            ans.push_back(v[i]);
        }
    }
    
    sort(ans.begin(), ans.end());
    for(auto it : ans){
        cout << it << endl;
    }
}
