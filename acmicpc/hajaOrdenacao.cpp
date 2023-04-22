#include <iostream>
#include <vector>
using namespace std;
void ordenador(int i);
vector<vector<int>>jogo;


void arrayOrdenado(int qcores){
    for(int i = 1; i <= qcores; i++ ){
        ordenador(i);
    }
    
}


void ordenador(int arrayEscolhido){
    
    for(int i = 1; i < jogo[arrayEscolhido].size(); i++){
        for(int j = i; j >= 1; j--){
            if(jogo[arrayEscolhido][j-1] > jogo[arrayEscolhido][j]){
                int temp = jogo[arrayEscolhido][j-1];
                jogo[arrayEscolhido][j-1] = jogo[arrayEscolhido][j];
                jogo[arrayEscolhido][j] = temp;
                
            }
        }
    }
}

bool ordened(vector<int>cartasOrdenadas){
    for(int i = 1; i < cartasOrdenadas.size() - 1 ; i++){
        if(cartasOrdenadas[i] < cartasOrdenadas[i - 1]){
            return false;
        }
    }

    return true;
}

int main(){
    int qblocos, qcores;
    cin >> qblocos >> qcores;
    jogo.resize(qcores + 1); //resize vai colocar qcores + 1 linhas
    
    int tempQblocos = qblocos;
    while (tempQblocos--){
        int numcarta, corCarta;
        cin >> numcarta >> corCarta;
        jogo[0].push_back(corCarta);
        jogo[corCarta].push_back(numcarta);
    }

    arrayOrdenado(qcores);    

    vector<int>cartasOrdenadas;
    for(int i = 0; i < qblocos; i++){
        int linhaCor = jogo[0][i]; 
        
        cartasOrdenadas.push_back(jogo[linhaCor][0]);
        jogo[linhaCor].erase(jogo[linhaCor].begin()); // apaga um elemento do vector, e dá um arrumada pra ele não ficar com buraco
    }
    
    bool isordened = ordened(cartasOrdenadas);

    if(isordened == true){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}
