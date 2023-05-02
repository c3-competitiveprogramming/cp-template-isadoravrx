#include <iostream>
using namespace std;

int main(){
    double d,l,v1,v2;

    cin >> d >> l >> v1 >> v2;

    double tempo = (l - d)/ (v1 + v2);   

    printf("%.20f\n",tempo);
}