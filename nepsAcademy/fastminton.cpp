#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char score[65]; //cada partida tem no máximo 3 games de 19 jogadas
    int pontL = 0, pontR = 0;
    int nowGame = 1; //game sendo jogado no momento
    int playerSacando = 0; // 0 é o left e 1 é o right
    
    cin.getline(score,65); //lendo o input
    int comprimentoString = strlen(score);
    
    for(int i = 0; i < comprimentoString; i++){
        if(score[i] == 'S'){
            if(playerSacando == 0){
                pontL++;
            }else{
                pontR++;
            }
        }
    }
    
}