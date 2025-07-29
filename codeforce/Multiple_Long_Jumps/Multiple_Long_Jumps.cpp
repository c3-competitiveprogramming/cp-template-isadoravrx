#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int mx = 0;
int estacoes; 

void recursive(int k, int sum, vector<int>&coins){
    if(k > estacoes){
        if(sum > mx){
            mx = sum;
        }

        return;
    }

    sum+= coins[k];
    recursive(2*k, sum, coins);
    recursive(2*k+1, sum, coins);
}

int main(){
    int n;
    cin >> n;

    estacoes = (pow(2,n) - 1);
    vector<int>coins(estacoes+1);
    for(int i = 1; i <= estacoes; i++){
        cin >> coins[i];
    }

    recursive(1,0, coins);

    cout << mx << endl;
}