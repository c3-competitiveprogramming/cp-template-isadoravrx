#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        map<char,int>mp;
        vector<char>v;
       

        v.push_back(s[0]); 
        mp[s[0]] = 0;
        bool b = false;

        for(int i = 0; i < s.size()-1; i++){
            int myposition = mp[s[i]];
            char next = s[i+1];

            if(mp.find(next) != mp.end()){
                if(myposition > 0){
                    if(myposition == v.size()-1){
                        if(v[myposition-1] != next){
                            b = true;
                        }
                    }else{
                       if(v[myposition+1] != next && v[myposition-1] != next){
                            b = true;
                        }
                    }
                }else{
                    if(v[myposition+1] != next){
                        b = true;
                    }
                }

                if(b){
                    break;
                }
            }else{
                
                if(myposition == v.size()-1){
                    v.push_back(next);
                    mp[next] = v.size() - 1;
                }else if(myposition == 0 ){
                    v.insert(v.begin(),next);
                    for(auto it : mp){
                        mp[it.first]++;
                    }
                    mp[next] = 0;
                }else{
                    b = true;
                    break;
                }
            }
        }

        char c = 'a';
        for(int i = 0; i < 26; i++){
            char aux = char(c + i);    
            if(mp.find(aux) == mp.end()){
                v.push_back(aux);
            }
        }
    

        if(b){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            for(int i = 0; i < 26; i++){
                cout << v[i];
            }
            cout << endl;
        }


    }
}