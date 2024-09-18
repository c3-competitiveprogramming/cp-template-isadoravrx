#include <iostream>
using namespace std;

int main(){
    int candidatos,votosCarlos,bestVoto = 0,votosPcandidato, counter = 0;

    cin >> candidatos;
    while(candidatos--){
        cin >> votosPcandidato;
        if(counter== 0){
            votosCarlos = votosPcandidato;
            counter++;
        }

        if(bestVoto < votosPcandidato){
            bestVoto = votosPcandidato;
        }
    }

    if(bestVoto == votosCarlos){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

    return 0;
}
