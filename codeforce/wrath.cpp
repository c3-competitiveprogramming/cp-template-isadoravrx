#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>pessoas;
    int value;
    for(int i = 0; i < n; i++){
        cin >> value;
        pessoas.push_back(value);
    }

    for(int i = 0; i < pessoas.size(); i++){
        for(int j = 0; j < pessoas.size(); j++){
            if(i == j){//ele não pode matar ele mesmo
                continue;
            }

            if(pessoas[j] == -1){//a pessoa já morreu
                continue;
            }

            if(i > j && j >= i - pessoas[i]){
                pessoas[j] = -1;
            }
        }
    }

    int alives = 0;
    for(int i = 0; i < pessoas.size(); i++){
        if(pessoas[i] != -1){
            alives++;
        }
    }

    cout << alives << endl;
}