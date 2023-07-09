#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int n, m;
vector<int>faixas;
vector<int>prem;

int premiacao(int pont){
    int low = 0;
    int high = n -2;
    int mid = (low + high)/2;
    while(true){
        if(low > high){
            break;
        }

        if(mid == 0){//mid é primeiro
            if(n == 2){//significa que só tem uma faixa
                if(pont >= faixas[mid]){
                    return prem[n - 1];
                }
            }
            if(pont < faixas[mid]){
                return prem[0];
            }
        }else if(mid == n - 2){//mid é o ultimo
            if(pont >= faixas[mid]){
                return prem[n-1];
            }else if(pont >= faixas[mid - 1] && pont < faixas[mid]){
                return prem[n - 2];
            }
        }else{//mid nao é nem primeiro nem ultimo
            if(pont >= faixas[mid -1] && pont < faixas[mid]){
                return prem[mid];
            }
        }

        if(pont < faixas[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }

        mid = (low + high)/2;
    }

    return 0;
}


int main(){
    cin >> n >>m;
    
    int num; 
    for(int i = 0; i < n -1 ; i++){
        cin >> num;
        faixas.pb(num);
    }

    for(int i = 0; i < n; i++){
        cin >> num;
        prem.pb(num);
    }

    for(int i = 0; i < m ; i++){ //usar busca binaria pra saber qual pontuacao que o ogro fez
        int pont;
        cin >> pont;
        int prem = premiacao(pont);
        if(i == m-1){
            cout << prem << endl;
        }else{
            cout << prem << " ";
        }
    }
}
