#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int qpormao;
    cin >> qpormao;
    int qtotal = qpormao * 2;
    string display;
    vector<int>contParalelo;
    contParalelo.assign(9,0); //vai colocar 9 linhas, mas tentar usasr assing

    for(int i = 0; i < 4; i++){
        cin >> display;
        for(int j = 0; j < 4; j++){
            if(display[j] == '.'){
                continue;
            }

            int position = (int) display[j]; //como passar de char para inteiro 
            contParalelo[position - 1] = contParalelo[position - 1] + 1;
        }
        
    }
    bool sheCan = true;
    for(int i = 0; i < contParalelo.size(); i++){
        if(contParalelo[i] > qtotal){
            sheCan = false;
        }
    }

    if(sheCan == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}