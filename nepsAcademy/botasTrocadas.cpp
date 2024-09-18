#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num;
    char lado;

    vector<int>esquerdo;
    vector<int>direito;

    int tempn = n;
    while(tempn--){  //lendo as entradas
        cin >> num >> lado;
        if(lado == 'E'){
            esquerdo.push_back(num);
        }else{
            direito.push_back(num);
        }
    }

    int counter = 0;
    int tamanhoEsquerdo = esquerdo.size();
    
    for(int i = 0; i < tamanhoEsquerdo; i++){
        for(int j = 0; j < direito.size(); j++){
            if(esquerdo[i] == direito[j]){
                direito.erase(direito.begin() + j);
                counter++;
                break;
            }
        }
    }

    cout << counter << endl;
    return 0;
}