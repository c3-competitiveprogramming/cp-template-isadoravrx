#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>matrix;

bool all_is_zero(int linha){
    if(linha == n - 1){
        return true;
    }

    bool allzero = true;
    for(int i = linha + 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0){
                allzero = false;
                break;
            }
        }
    }

    return allzero;

}

bool checking_colunas(int linha, int pos){
    if(linha == n -1){
        return true;
    }
    for(int i = linha + 1; i < n; i++ ){
        for(int j = 0; j <= pos; j++){
            if(matrix[i][j] != 0){
                return false;
            }
        }
    }

    return true;
}

int main(){
    cin >> n >> m;

    bool allzero = true;
    vector<int>first_nozero;
    int cont = 0;
    matrix.resize(n);

    for(int i = 0; i < n; i++){
        cont = 0;
        int position;
        allzero = true;
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            matrix[i].push_back(num);
            if(num != 0 && cont == 0){
                allzero = false;
                position = j;
                cont = 1;
            }
        }

        if(allzero){
            first_nozero.push_back(-1);
        }else{
            first_nozero.push_back(position);
        }
    }
    
    bool answer = true;
    for(int i = 0; i < n; i++){
        if(first_nozero[i] == -1){
            answer = all_is_zero(i);//testar apartir da linha i
            break;
        }else{
            answer = checking_colunas(i,first_nozero[i]);
        }

        if(answer == false){
            break;
        }
    }

    if(answer){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
}
