#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s1,s2;

    cin >> s1 >> s2;
    vector<int>a;
    vector<int>b;

    int conta = 0,contb = 0;
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i]){
            if(s1[i] == 'a'){
                conta++;
                a.push_back(i + 1);
            }else{
                contb++;
                b.push_back(i + 1);
            }
        }
    }

    if((a.size()+b.size()) % 2 != 0){
        cout << -1 << endl;
    }else{
        vector<pair<int,int>>ans;

        bool primeirobjafoi = false;
        
        for(int i = 0; i < a.size(); i+=2){
            if(i + 1 < a.size()){
                ans.push_back(make_pair(a[i],a[i+1]));
            }else{
                primeirobjafoi = true;
                ans.push_back(make_pair(a[i],a[i]));
                ans.push_back(make_pair(a[i],b[0]));
            }
        }

        int i = 0;
        if(primeirobjafoi){
            i = 1;
        }
        
        for( ;i < b.size();i+=2){
            if(i + 1 < b.size()){
                ans.push_back(make_pair(b[i],b[i+1]));
            }
        }
    
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
}
