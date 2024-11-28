#include <iostream>
using namespace std;

int fatorialRecursivo(int n){
    if(n == 0){
        return 1;
    }

    return n * fatorialRecursivo(n - 1);
}

int main(){
    int n;
    cin >> n;
    int fatorialn = fatorialRecursivo(n);
    cout << fatorialn << endl;
    return 0;
}