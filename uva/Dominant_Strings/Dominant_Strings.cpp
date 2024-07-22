#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isdominatedfunc(string s1, string s2){
    
    int i = 0;
    int j = 0;
    while(i < s1.size() && j < s2.size()){
        if(s2[j] == s1[i]){
            i++;
            j++;
        }else if(s2[j] > s1[i]){
            return false;
        }else{
            j++;
        }
    }

    if(i == s1.size()){
        return true;
    }

    return false;
}

bool comp(string s1, string s2){
    if(s1.size() > s2.size()){
        return false;
    }else if(s1.size() < s2.size()){
        return true;
    }else{
        int i = 0;
        int j = 0;

        while(i < s1.size()){
            if(s1[i] > s2[j]){
                return false;
            }
            if(s1[i] < s2[j]){
                return true;
            }

            i++;
            j++;
        }
    }


}

int main(){
    string s;
    vector<string> v;
    map<string,string> mp;

    map<string,bool>isdominant;
    while(cin >> s){
        string temp = s;
        sort(temp.begin(), temp.end());
        mp[temp] = s;
        isdominant[temp] = true;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(),comp);

    map<string,string>ans;
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            if(isdominatedfunc(v[i], v[j])){
                isdominant[v[i]] = false;
                break;
            }
        }

        if(isdominant[v[i]]){
            ans[mp[v[i]]] = mp[v[i]];
        }
    }

    for(auto it : ans){
        cout << it.first << endl;
    }
}