#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    char mensagem[10001], crib[10001], substring[10001];
    
    int counter1 = 0, counter2 = 0, i = 0, j ;
    
    cin.getline(mensagem,10001);
    cin.getline(crib,10001);

    j = strlen(crib) - 1;

    while(true){
        
        if(j > (strlen(mensagem) - 1)){  //se j passar do tamanho da mensagem
            break;
        }

        int tempi = i;
        for(int k = 0 ; k < strlen(crib) ; k++){  //montando a substring da mensagem
            substring[k] = mensagem[i];
            i++;
        }
        
        i = tempi;


        for(int l = 0 ; l < strlen(crib) ; l++ ){   //compara a substring da mensagem com o crib
            if(crib[l] == substring[l]){
                counter1++;
                break;
            }
        }

        if(counter1 == 0){
            counter2++;
        }
    
        counter1 = 0;
        i++;
        j++;

    }


    cout << counter2 << endl;

    return 0;
}
