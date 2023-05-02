#include <iostream>
using namespace std;

int main(){
    int d,l,v1,v2;
    int x1,x2;

    cin >> d >> l >> v1 >> v2;
    x1 = 0;
    x2 = l;
    int cont = 0;
    while(true){
        if(x2 - x1 >= d && x2 - x1 > 0){
            cont++;
            x1 += v1;
            x2 += v2;
        }else{
            break;
        }
    }
    
       

    cout << cont << endl;
}