#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n,k,l,c,d,p, nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int qbrindesonlybebida = ((k * l) / nl)/n;
    int qbrindesonlylimao = (d * c)/n;
    int qbrindesonlysal = (p / np)/n;
    
    int menor = min(qbrindesonlybebida,qbrindesonlylimao);
    menor = min(menor, qbrindesonlysal);
    cout << menor << endl;

    return 0;

}