#include <iostream>
using namespace std;

int main(){
    long descanso, duracaovoo, qrefeicoes , minutorefeicao, minutoanterior = 0, counter = 0, diferenca;
    cin >> descanso >> duracaovoo >> qrefeicoes;
    while(qrefeicoes--){
        cin >> minutorefeicao;
        diferenca = minutorefeicao - minutoanterior;
        if(diferenca >= descanso){
            counter++;
        }

        minutoanterior = minutorefeicao;
    }

    diferenca = duracaovoo - minutoanterior;
    if(diferenca >= descanso){
        counter++;
    }


    if(counter > 0){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
}
