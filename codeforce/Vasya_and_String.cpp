#include <iostream>
#include <cmath>
using namespace std;
int n, k;
string s;
int qpercorridas = 0;
char bestletra;

void trocandoletrasAntes(int besti, char bestletra){
    
    
    if(besti != n - 1 && besti >= 0 && s[besti + 1] == bestletra){
        if(s[besti] != bestletra && k > 0){
            s[besti] = bestletra;
            k--;
            qpercorridas++;
        }
        
        trocandoletrasAntes(besti-1,bestletra); 
    }else{
        return;
    }
    
}

void trocandoletrasDepois(int bestj, char bestletra){
    
    if(bestj < n && bestj > 0 && s[bestj - 1] == bestletra){
        if(s[bestj] != bestletra && k > 0){
            s[bestj] = bestletra;
            k--;
            qpercorridas++;
        }

        trocandoletrasAntes(bestj+1,bestletra); 
    }else{
        return;
    }
    
}

int main(){
    
    cin >> n >> k;

    int lenght = 1;
    int bestlength = 1;

    
    cin >> s;

    int besti = 0;
    int bestj = 0;

    char lastchar = s[0];

    for(int p = 1; p < n; p++){ //achando o comprimento da maior cadeia, onde ela comeca e onde ela termina

        char i;
        i = s[p];
        
        if(i == lastchar){
            lenght++;
        }else{
            lenght = 1;
        }

        if(lenght > bestlength){
            bestlength = lenght;
            bestj = p;
            besti = bestj - lenght + 1;
        }

        lastchar = i;
    }    

    bestletra = s[bestj];
    trocandoletrasAntes(besti - 1,bestletra);
    trocandoletrasDepois(bestj + 1,bestletra);
    
    cout << bestlength + qpercorridas << endl;
}
