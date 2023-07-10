#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int paises,modalidades;
    cin >> paises >> modalidades;
    
    vector<vector<int>>medalhas(paises);
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
    for(int i = paises - 1; i >= 0; i--){
        if(i == 0){
            cout << medalhas[i][3] << endl;
        }else{
            cout << medalhas[i][3] << " ";
        }
    }
    
}
