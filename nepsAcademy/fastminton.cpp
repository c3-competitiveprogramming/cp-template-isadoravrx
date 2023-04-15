#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char score[65]; //cada partida tem no máximo 3 games de 19 jogadas
    int pontL = 0, pontR = 0;
    int gameL = 0, gameR = 0;  //game ganhados de cada jogador
     
    int playerSacando = 0; // 0 é o left e 1 é o right
    int ultimaApontuar = -1;

    cin.getline(score,65); //lendo o input
    int comprimentoString = strlen(score);
    
    for(int i = 0; i < comprimentoString; i++){
        if((pontL >= 5 && pontL - pontR >= 2) || pontL == 10){  //possibilidade em que o L ganhou o game
            gameL++;
            playerSacando = ultimaApontuar;
            pontL = 0;
            pontR = 0;

        }else if((pontR >= 5 && pontR - pontL >= 2) || pontR == 10){
            gameR++;
            playerSacando = ultimaApontuar;
            pontL = 0;
            pontR = 0;
        }
        if(score[i] == 'S'){
            if(playerSacando == 0){
                pontL++;
                ultimaApontuar = 0;
                playerSacando = 0;
            }else{
                pontR++;
                ultimaApontuar = 1;
                playerSacando = 1;
            }

        }else if(score[i] == 'R'){
            if(playerSacando == 0){
                pontR++;
                playerSacando = 1;
                ultimaApontuar = 1;
            }else{
                pontL++;
                playerSacando = 0;
                ultimaApontuar = 0;
            }
        }else if(score[i] == 'Q'){
            if(gameL == 2 || gameR == 2){ // fazer esse
                if(gameL > gameR){
                    cout << gameL << " " << "(winner)" << " " << "-" <<  " " << gameR << endl;
                }else{
                    cout << gameL << " " << "-" <<  " " << gameR << " " << "(winner)" << endl;
                }
                break;
            }else{
                if(playerSacando == 0){
                    cout << gameL << " " << "(" << pontL << "*" <<")" << " " << "-" << " " << gameR << " " << "(" << pontR << ")" << endl;
                }else{
                    cout << gameL << " " << "(" << pontL <<")" << " " << "-" << " " << gameR << " " << "(" << pontR << "*" << ")" << endl;
                }
                 
            }
            
        }
    }

    return 0;
}