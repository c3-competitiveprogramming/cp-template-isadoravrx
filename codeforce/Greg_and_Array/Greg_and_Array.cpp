#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, k; 
    cin >> n >> m >> k;
    
    int array[n];
    for(int i = 0; i < n; i++){ // recebendo array
        int value;
        cin >> value;
        array[i] = value;
    }

    int fl, fr, somador; //fronteira left...
    int op[m][n]; //a 4 posicao é pra quantas vezes ele foi utilizado
    for(int i = 0; i < m; i++){ // recebendo as operações e colocando na matriz
        cin >> fl >> fr >> somador;
        fl--;
        fr--;
        op[i][fl] += somador;
        if(fr + 1 < n){
            op[i][fr+1] -= somador;
        }
    }

    int opinicial, opfinal;
    vector<int>freq_op;
    freq_op.assign(m,0);
    for(int i = 0; i < k; i++){ 
        cin >> opinicial >> opfinal;
        opinicial--;
        opfinal--;
        //talvez isso esteja lento, devo fazer o mesmo da matriz das operacoes?
        for(int j = opinicial; j < opfinal; j++){
            freq_op[j]++;
        }
    }  

    vector<long long>cadeia_somadora;
    cadeia_somadora.assign(n,0);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            op[i][j] = freq_op[i] * op[i][j];
            if(j == 0){
                cadeia_somadora[j] += op[i][j];
            }else{
                cadeia_somadora[j] += op[i][j - 1] + op[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        array[i] += cadeia_somadora[i];
        
        if(i == n - 1){
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << " ";
    }


    return 0;

}
