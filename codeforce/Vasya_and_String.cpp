#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<char>v;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        v.push_back(c);
    }

    int conta = 0;
    int contb = 0;
    int i = 0;
    int j = 0;
    int bestcont = 0;

    while(true){
        if(j == n){
            break;
        }
        
        if(v[j] == 'a'){
            conta++;
        }else{
            contb++;
        }
        
        if(conta <= k || contb <= k){
            bestcont = max(bestcont, j - i + 1);
            j++;
        }else{
            if(v[j] == 'a'){
                conta--;
            }else{
                contb--;
            }

            if(v[i] == 'a'){
                conta--;
            }else{
                contb--;
            }
            i++;
        }

    }

    cout << bestcont << endl;
}
