#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int num;
    
    
    map<int,int>mp;
    vector<int>v;
    while(cin >> num){
        if(mp[num] == 0){
            v.push_back(num);
        }
        mp[num]++;
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " " << mp[v[i]] << endl;
    }
}
