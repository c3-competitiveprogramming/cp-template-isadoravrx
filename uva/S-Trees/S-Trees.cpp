#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int valordehigh(int n){
    if (n==1) return 1;
    if (n==2) return 3;
    if (n==3) return 7;
    if (n==4) return 15;
    if (n==5) return 31;
    if (n==6) return 63;
    if (n==7) return 127;
    return 0;
}

int main(){

    int n, cont=1;
    while(cin>>n && n!=0){
        if(cont>1){
            cout<<endl;
        }
        cout<<"S-Tree #"<<cont<<endl;
        cont++;

        string xx, terminal, vva;
        vector<string> ordem;
        map<string, int> valor;
        for(int i=0;i<n;i++){
            cin>>xx;
            ordem.push_back(xx);
            valor[xx]=0;
        }

        cin>>terminal;

        int m;
        cin>>m;

        while(m--){
            cin>>vva;

            for(int i=1;i<=n;i++){
                string temp="x";
                string num=to_string(i);
                temp+=num;
                valor[temp]=vva[i-1];
            }

            int high=valordehigh(n), low=0, mid;
            if(valor[ordem[0]]==0){
                high++;
            }
            for(int i=0;i<n;i++){
                mid=(high+low)/2;
                if(valor[ordem[i]]==0){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            mid=(high+low)/2;

            cout<<terminal[mid];

        }

        
    }

    return 0;
}