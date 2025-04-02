#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){

    int n;
    ll a,maior;
    bool b=true,bb=true;
    vector<ll> v,v1;
    cin>>n;
    for(int i = 0; i < pow(2,n); i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    while(v1.size()>1 || v.size()>1){
        if(bb){
            for(int i=1;i<v.size();i+=2){
                ll soma=v[i]+v[i-1];
                if(b){
                    maior=soma;
                    b=false;
                }else if(maior<soma){
                    maior=soma;
                }

                v1.push_back(soma);
            }

            v.clear();
            bb=false;       
        }else{
            for(int i=1;i<v1.size();i+=2){
                ll soma=v1[i]+v1[i-1];
                if(maior<soma){
                    maior=soma;
                }

                v.push_back(soma);
            }

            v1.clear();
            bb=true; 
        }
    }
    
    cout<<maior<<endl;

    return 0;
}