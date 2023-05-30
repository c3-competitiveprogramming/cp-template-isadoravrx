#include <iostream>
#include <vector>
using namespace std;

int main(){
    int paises,modalidades;
    cin >> paises >> modalidades;
    
    vector<vector<int>>medalhas;
    for(int i = 0; i < paises; i++){
        medalhas[i].assing(3,0);//quantidade,depois o numero
    }

    for(int i = 0; i < modalidades; i++){
        int ouro,prata,bronze;
        cin >> ouro >> prata >> bronze;
        medalhas[ouro][0]++;
        medalhas[prata][1]++;
        medalhas[bronze][2]++;
    }


}
