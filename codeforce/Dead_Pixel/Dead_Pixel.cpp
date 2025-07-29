#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t; 

    while(t--){
        int qlinhas, qcolunas, x,y;
        cin >> qlinhas >> qcolunas >> x >> y;
        
        int mx = 0;

        if(x != 0){
            mx = max(mx,x * qcolunas);
        }

        if(y != 0){
            mx = max(mx, qlinhas * y);
        }

        if(x != qlinhas-1){
            mx = max(mx, (qlinhas-x-1) * qcolunas);
        }

        if(y != qcolunas-1) {
            mx = max(mx, qlinhas * (qcolunas-y-1));
        }


        cout << mx << endl;
    }
}