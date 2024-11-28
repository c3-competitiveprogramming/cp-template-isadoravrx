#include <iostream>
using namespace std;
int main(){
    int caixas, conteudo, score = 100;
    int bestResult = 100;
    cin >> caixas;
    while(caixas--){
        cin >> conteudo;
        score = score + conteudo;
        if(score > bestResult){
            bestResult = score;
        }
    }

    cout << bestResult << endl;

    return 0;
}
