#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test = 1;
    while(true){
        int alunos;
        cin >> alunos;

        if(alunos == 0){
            break;
        }

        int codigo,media;
        vector<vector<int>>codigoENotas(2);
            
        int high = 0;
        for(int i = 0; i < alunos ; i++){
            cin >> codigo >> media;
            codigoENotas[0].push_back(codigo);
            codigoENotas[1].push_back(media);
            if(media > high){
                high = media;
            }
        }
        
        printf("Turma %d\n",test); 
        test++;

        vector<int>CodigosbestNotas;
        for(int i = 0; i < alunos; i++){
            if(codigoENotas[1][i] == high){
                CodigosbestNotas.push_back(codigoENotas[0][i]);
            }

        }

        for(int i = 0; i < CodigosbestNotas.size(); i++){
                if(i == CodigosbestNotas.size() - 1){
                    cout << CodigosbestNotas[i] << endl;
                    break;
                }

                cout << CodigosbestNotas[i] << " ";
        }
    }
}
