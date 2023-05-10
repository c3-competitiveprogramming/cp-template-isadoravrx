#include <iostream>
#include <vector>
using namespace std;

vector<int>paleta;
vector<int>newpaleta;
int n;

int calculandoDireita(int elementIndex){
    int distancia = 1;    
    for(int i = elementIndex + 1; i < n; i++){
        if(paleta[i] == 0){
            return distancia;
        }
        
        distancia++;
    }

    return 0;
}

int calculandoEsquerda(int elementIndex){
    int distancia = 1;
    for(int i = elementIndex - 1; i >= 0; i--){
        if(paleta[i] == 0){
            return distancia;
        }   

        distancia++;
    }

    return 0;
}

int main(){
    
    cin >> n;
    
    int color;
    for(int i = 0; i < n; i++){ //recebendo como a paleta está
        cin >> color;
        paleta.push_back(color);
    }

    int distanciaE;
    int distanciaD;

    for(int i = 0; i < n; i++){
        if(paleta[i] == 0){
            newpaleta.push_back(0);
            continue;
        }
        if(i == 0){
            distanciaD = calculandoDireita(i);
            if(distanciaD > 9){
                newpaleta.push_back(9);
            }else{
                newpaleta.push_back(distanciaD);
            }
        }else if(i == n - 1){
            distanciaE = calculandoEsquerda(i);
            if(distanciaE > 9){
                newpaleta.push_back(9);
            }else{
                newpaleta.push_back(distanciaE);
            }
            
        }else{
            distanciaD = calculandoDireita(i);
            distanciaE = calculandoEsquerda(i);
            if(distanciaD == 0){ //se a distancia é 0, é porque não achou nenhum 0 a direita
                if(distanciaE > 9){
                    newpaleta.push_back(9);
                }else{
                    newpaleta.push_back(distanciaE);
                }

            }else if(distanciaE == 0){
                if(distanciaD > 9){
                    newpaleta.push_back(9);
                }else{
                    newpaleta.push_back(distanciaD);
                }
            }else if(distanciaD < distanciaE){
                 if(distanciaD > 9){
                    newpaleta.push_back(9);
                }else{
                    newpaleta.push_back(distanciaD);
                }
            }else{
                if(distanciaE > 9){
                    newpaleta.push_back(9);
                }else{
                    newpaleta.push_back(distanciaE);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i == n-1){
            cout << newpaleta[i] << endl;
        }else{
            cout << newpaleta[i] << " ";
        }
    }

    return 0;
}