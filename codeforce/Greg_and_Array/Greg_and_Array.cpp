#include <iostream>
#include <cstring>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;

    long long array[n];
    for(int i = 0; i < n; i++){ // recebendo array
        long long value;
        cin >> value;
        array[i] = value;
    }

    long long fl, fr, somador; //fronteira left...
    long long op[m][3]; //somador,left,right

    memset(op,0,sizeof(op));

    for(int i = 0; i < m; i++){ // recebendo as operações e colocando na matriz
        cin >> fl >> fr >> somador;
        fl--;
        fr--;

        op[i][0] += somador;
        op[i][1] = fl;
        op[i][2] = fr;
    }

    long long opinicial, opfinal;

    long long timesop[m];
    memset(timesop,0,sizeof(timesop));

    for(int i = 0; i < k; i++){
        cin >> opinicial >> opfinal;
        opinicial--;
        opfinal--;

        timesop[opinicial]++;
        if(opfinal + 1 < m){
            timesop[opfinal + 1]--;
        }
    }

    long long qtimes_op[m]; //guarda a quantidade que cada operacao foi usada
    long long anterior = 0;
    for(int i = 0; i < m; i++){
        qtimes_op[i] = timesop[i] + anterior;
        anterior = timesop[i] + anterior;
    }

    long long soma[n];
    memset(soma,0,sizeof(soma));
    for(int i = 0; i < m ; i++){
        op[i][0] = op[i][0] * qtimes_op[i];
        soma[op[i][1]] += op[i][0];
        if(op[i][2] + 1 < n){
            soma[op[i][2] + 1]-=op[i][0];
        }
    }


    anterior = 0;
    for(int i = 0; i < n; i++){
        array[i] += soma[i] + anterior;
        anterior = soma[i] + anterior;
        if(i == n - 1){
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << " ";
    }


    return 0;

}