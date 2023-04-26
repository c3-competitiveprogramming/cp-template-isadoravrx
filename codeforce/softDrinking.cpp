#include <iostream>
using namespace std;

int main(){
    int n,k,l,c,d,p, nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int qcoposcombebida = (k * l) / nl ;
    int qcoposcomlimao = (d * c);
    int qcoposcomsal = p / np;
    int qbrindesonlybebida = qcoposcombebida / n;
    int qbrindesonlylimao = qcoposcomlimao / n;
    int qbrindesonlysal = qcoposcomsal / n;
    
    if(qbrindesonlybebida < qbrindesonlylimao && qbrindesonlybebida < qbrindesonlysal){
        cout << qbrindesonlybebida << endl;
    }else if(qbrindesonlylimao < qbrindesonlybebida && qbrindesonlylimao < qbrindesonlysal){
        cout << qbrindesonlylimao << endl;
    }else if(qbrindesonlysal < qbrindesonlybebida && qbrindesonlysal < qbrindesonlylimao){
        cout << qbrindesonlysal << endl;
    }

    return 0;

}