#include<iostream>
#include<map>
using namespace std;

int main(){

    int n;
    while(cin>>n){
        int circunferencia=0;
        map<int,int> pontos;
        pontos[0]++;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            circunferencia+=x;
            pontos[circunferencia]++;
        }

        if(circunferencia%3!=0){
            cout<<"0\n";
            continue;
        }

        int qtd=0, lado=circunferencia/3;
        for(auto it:pontos){
            if(it.first>=lado){
                break;
            }

            if(pontos.find(it.first+lado)!=pontos.end() && pontos.find(it.first+lado+lado)!=pontos.end()){
                qtd++;
            }
        }

        cout<<qtd<<endl;
    }

    return 0;
}