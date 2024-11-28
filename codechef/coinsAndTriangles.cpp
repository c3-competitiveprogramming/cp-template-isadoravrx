#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int test; 
    cin >> test;

    while(test--){
        long long n;
        cin >> n;
        int h;

        int delta = sqrt(8 * n + 1);
         h = (-1 + delta) / 2;
        cout << h << endl;
    }
}
