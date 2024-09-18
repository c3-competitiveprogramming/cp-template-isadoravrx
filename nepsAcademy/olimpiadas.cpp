#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>medalhas;
int cont = 0;
void rep(int i){
    if(i == 0){
        return;
    }else{
        if(medalhas[i][0] == medalhas[i-1][0] && medalhas[i][1] == medalhas[i-1][1] &&medalhas[i][2] == medalhas[i-1][2]){
            cont++;
            return rep(i-1);
        }else{
            return;
        }
    }
}
int main(){
    int paises,modalidades;
    cin >> paises >> modalidades;
    
    medalhas.resize(paises);
    for(int i = 0; i < paises; i++){  //assim, o país 0,1,2... terao suas q de medalhas
        medalhas[i].assign(4,0);//quantidade,depois o numero
        medalhas[i][3] = i + 1;// identidade do pais
    }

    for(int i = 0; i < modalidades; i++){
        int ouro,prata,bronze;
        cin >> ouro >> prata >> bronze;
        ouro--; //pois os paises comecam de 0
        prata--;
        bronze--;
        medalhas[ouro][0]++;
        medalhas[prata][1]++;
        medalhas[bronze][2]++;
    }

    sort(medalhas.begin(),medalhas.end());
    int qprint = 0;
    for(int i = paises - 1; i >= 0; i--){
        cont = 0;
        rep(i);
        
        for(int j = i - cont; j <= i; j++){
            if(qprint == paises - 1){
                cout << medalhas[j][3] << endl;
                break;
            }

            cout << medalhas[j][3] << " ";
            qprint++;
        }

        i = i - cont;
    }

}
