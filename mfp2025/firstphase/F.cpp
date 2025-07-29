#include <iostream>
using namespace std;

int main(){
    int n,p,k;
    cin >> n >> p >> k;

    

    int cont = 0;
    int i = p+1;
    if(i > n){
        i = 1;
    }
    while(true){
        cont++;
        if(cont > k){
            break;
        }
        
        i++;

        if(i > n){
            i = 1;
        }

        if(i == p){
            i++;
        }

        if(i > n){
            i = 1;
        }
    }

    cout << i << endl;
}