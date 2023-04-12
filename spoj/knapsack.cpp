#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> pesos;
vector<int>valores;
int mem[2005][2005];
int capacity, itens;

int recursive(int i, int c){
    if( i == itens || c < 0){   
        return 0;
    }

    if(mem[i][c] != -1){
        return mem[i][c];
    }

    int p = 0;
    int np = 0;
    if(c - pesos[i] >= 0){
        p += valores[i];
            
    }
    np += recursive(i + 1, c);
    p += recursive(i + 1, c - pesos[i]);
        

    
    return mem[i][c] = max(p,np);

}   

int main(){
    
    cin >> capacity >> itens;
    int tempitens = itens;
    memset(mem, -1 , sizeof(mem));
    while(tempitens--){
        int valor, peso;
        cin >> peso >> valor;        
        pesos.push_back(peso);
        valores.push_back(valor);
    }

    int bestvalue;
    bestvalue = recursive(0,capacity);
    
    
    cout << bestvalue << endl;

}
