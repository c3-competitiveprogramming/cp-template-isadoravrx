#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long l, n;
    cin >> l >> n;

    long nummaior = l - (n -1);
    long soma = pow(nummaior,2) + (n - 1);

    cout << soma << endl;
}