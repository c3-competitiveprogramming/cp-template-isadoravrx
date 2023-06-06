#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int testes;
    cin >> testes;

    while(testes--){
        int linhas, colunas;
        cin >> linhas >> colunas;
        string value;
        int qzerosborda = 0, qunsmeio = 0;

        for(int i = 0; i < linhas; i++){ //verificando cada numero da matriz
            cin >> value;
            for(int j = 0; j < colunas ; j++){
                char number = value[j];
                if(i == 0 || j == 0 || j == colunas - 1 || i == linhas - 1){ //verifica se ta na borda
                    if(number == '0'){
                        qzerosborda++;
                    }
                }else{
                    if(number == '1'){
                        qunsmeio++;
                    }
                }
            }
        }

        if(qunsmeio >= qzerosborda){
            cout << qzerosborda << endl; 
        }else{
            cout << "-1" << endl;
        }
        
    }
}