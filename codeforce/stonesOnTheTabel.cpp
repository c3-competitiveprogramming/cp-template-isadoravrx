#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, qdeletados = 0;
    string sequencia;
    char anterior, atual;
    cin >> n >> sequencia;
    anterior = sequencia[0];
    for(int i = 1; i < sequencia.size(); i++){
        atual = sequencia[i];
        if(anterior == atual){
            qdeletados++;
            continue;
        }

        anterior = atual;
    }

    cout << qdeletados << endl;
    return 0;
}