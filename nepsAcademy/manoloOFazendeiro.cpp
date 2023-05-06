#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>plantacao;

int colhendocenouras(int linhai,int colunai,int linhaf, int colunaf){
    int cenourasColhidas = 0;
    for(int i = linhai; i <= linhaf; i++){
        for(int j = colunai; j <= colunaf; j++){
            cenourasColhidas += plantacao[i][j];
            plantacao[i][j] = 0;
        }
    }

    return cenourasColhidas;
}
int main(){
    int tamnhoplantacao;
    cin >> tamnhoplantacao;
    plantacao.resize(tamnhoplantacao);
    for(int i = 0; i < tamnhoplantacao; i++ ){ //recebendo input
        for(int j = 0; j < tamnhoplantacao; j++){
            int value;
            cin >> value;            
            plantacao[i].push_back(value);
        }
    }

    int retiradas;
    cin >> retiradas;

    int linhai,colunai,linhaf,colunaf;
    int sum  = 0;
    while(retiradas--){
        cin >> linhai >> colunai >> linhaf >> colunaf;
        linhai--;
        colunai--;
        linhaf--;
        colunaf--;
        sum += colhendocenouras(linhai,colunai,linhaf, colunaf);
    }

    cout << sum << endl;
    return 0;
}