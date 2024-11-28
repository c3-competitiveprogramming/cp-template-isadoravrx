#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>letras(5);
vector<vector<int>>senhas(6);

void busca(int letra_senha, int pos_senha,int i){
    if(i == 0){
        senhas[pos_senha][0] = letras[letra_senha][0];
        senhas[pos_senha][1]  = letras[letra_senha][1];
    }else{
        for(int i = 0; i < senhas[pos_senha].size(); i++){
            if(senhas[pos_senha][i] != letras[letra_senha][0] && senhas[pos_senha][i] != letras[letra_senha][1]){
                senhas[pos_senha].erase(senhas[pos_senha].begin() + i);
            }
        }
    }
}

int main(){
    int n;
    int test = 1;
    while(true){
        cin >> n;
        
        if(n == 0){
            break;
        }

        senhas.clear();
        senhas.resize(6);
        senhas[0].assign(2,0);
        senhas[1].assign(2,0);
        senhas[2].assign(2,0);
        senhas[3].assign(72,0);
        senhas[4].assign(2,0);
        senhas[5].assign(2,0);

        for(int i = 0; i < n; i++){
            letras.clear();
            letras.resize(5);
            for(int j = 0; j < 5; j++){
                int num1,num2;
                cin >> num1 >> num2;
                letras[j].push_back(num1);
                letras[j].push_back(num2);
            }

            
            for(int j = 0; j < 6; j++){
                char c;
                cin >> c;

                busca(c - 'A',j,i);
            }
            
        }

            printf("Teste %d\n",test);
            test++;
            for(int i = 0; i < 6 ; i++){
                if(i == 5){
                    cout << senhas[i][0] << endl;
                    break;
                }
                cout << senhas[i][0] << " ";
            }

    }

}
