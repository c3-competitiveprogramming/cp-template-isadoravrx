#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> numbers;
    int n, number;

    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; i++){ //criando a matriz com as entradas
        for(int j = 0; j < n; j++){
            cin >> number;
            numbers[i].push_back(number);
        }
    }

    bool isMagic = true;
    int soma = 0;

    for(int j = 0; j < n; j++){ //para descobrir qual é a soma
        soma += numbers[0][j];
    }

    int somaatual = 0;
    for(int k = 0; k < n; k++){ //  verificando os horizontais
        for(int l = 0; l < n ; l++){
            somaatual += numbers[k][l];
        }
        if(somaatual != soma){
            isMagic = false;
            break;
        }

        somaatual = 0;
    }    

    somaatual = 0;
    if(isMagic == true){
        
        for(int m = 0; m < n; m++){ // verificando os verticais
            for(int p = 0; p < n; p++){
                somaatual = numbers[p][m];
            }
            if(somaatual != soma){
                isMagic = false;
                break;
            }
            somaatual = 0;
        }

        somaatual = 0;
        for(int q = 0; q < 1; q++){ //verificando as diagonais da esquerda pra direita
            for(int r = 0; r < n; r++ ){
                somaatual += numbers[r][r];
            }
            if(somaatual != soma ){
                isMagic = false;
                break;
            }
            somaatual = 0;
        }

        somaatual = 0;
        int t = n -1;
        for(int s = 0; s < n; s++){ // verificando as diagonais da direita pra esquerda
            somaatual += numbers[s][t];
            t--;
        }
        if(somaatual != soma){
            isMagic = false;
        }
    }

    if(isMagic == true){
        cout << soma << endl;
    }else{
        cout << "-1" << endl;
    }
    
    return 0;
}
