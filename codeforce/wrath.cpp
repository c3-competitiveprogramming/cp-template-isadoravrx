#include <iostream>
#include <vector>
#include <bitset>
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
    int qmortos = 0;
    
    bitset<1000000> bt(0);
    int i = n - 1;
    int j = i - 1;
    while(true){
        
        if(j >= i){
             j = i - 1;
        }

        if(j < 0){
            break;
        }


        if(j >= i - pessoas[i]){
            if(bt[j] == 0){ //ou seja, se ela ainda estiver viva, mata
                bt[j] = 1;
                qmortos++;
            }
            j--;
        }else{
            i--;
        }
    }

    int alives;
    alives = n - qmortos;

    cout << alives << endl;
}
