#include <iostream>
#include <cstring>
using namespace std;

int m, n;
long long mem[60][100000];

long long dp(int t, int k){
    if(t == 1 ){
        return 1;
    }

    if(mem[t][k] != -1){
        return mem[t][k];
    }

    long long cont = 0;

    if(k < n){
        cont += dp(t-1, k+1);
    }

    if(k > m){
        cont += dp(t-1, k-1);
    }

    return mem[t][k] = cont; //retorna cont
}

int main(){
    int t;

    cin >> t >> m >> n;

    long long cont = 0;

    memset(mem, -1, sizeof(mem));

    for(int i = m; i != n + 1; i++){
        cont += dp(t, i) % (1000000000 + 7);
    }


    cout << (cont %(1000000000 + 7)) << endl;

}

