#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;

    map<string,long long>mp;
    while(n--){
        string s;
        cin >> s;
        string t;
        getline(cin,t);

        mp[s]++;
    }

    vector<string>v;
    for(auto i : mp){
        v.push_back(i.first);
    }

    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " " << mp[v[i]] << endl;
    }
}