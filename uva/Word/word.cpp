#include<iostream>
#include<string>
#include<vector>
typedef long long ll;
using namespace std;

string o(string w, int n){
    vector<char> p;

    string s="zzzzzzzzz";

    for(int i=0;i<n;i++){
        p.push_back(w[i]);
    }

    for(int i=0;i<n;i++){
        string str(p.begin(), p.end());

        if(str<s){
            s=str;
        }

        p.push_back(p[0]);

        p.erase(p.begin());
    }


    return s;
}

int main(){

    ll nn;
    int n;
    while(cin>>n){
        string word, regra;
        cin>>word;

        vector<string>regras;

        for(int i = 0; i < 8; i++){
            cin >> regra;
            regras.push_back(regra);
        }
        for(int j=0;j<n;j++){
            for(int i=0; i<regras.size();i++){
               
                if(j<2){
                    if(word[j-2 +n]==regras[i][0] &&  word[j]==regras[i][1] && word[j+1]==regras[i][2]){
                        word[j]=regras[i][3];
                    }
                }
                else if(j==n-1){
                    if(word[j-2]==regras[i][0] && word[0]==regras[i][2] && word[j]==regras[i][1]){
                        word[j]=regras[i][3];
                    }
                }
                else{
                    if(word[j-2]==regras[i][0] && word[j+1]==regras[i][2] && word[j]==regras[i][1]){
                        word[j]=regras[i][3];
                    }
                }
            }
        }

        cout<<o(word, n)<<endl;

        cin>>nn;
    }


    return 0;
}