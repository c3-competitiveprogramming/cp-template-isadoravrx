#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>ladrilhos;

/*int proxPositivo(int altura, int largura){
    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            if(ladrilhos[i][j] != -1){
                return 0;
            }
        }
    }
}*/

int main(){
    int altura, largura, cor;

    cin >> altura >> largura;
    ladrilhos.resize(altura);

    for(int i = 0; i < altura; i++){ //lendo as entradas
        for(int j = 0; j< largura; j++){
            cin >> cor;
            ladrilhos[i].push_back(cor);
        }
    }
    
}