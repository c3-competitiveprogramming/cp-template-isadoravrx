#include <iostream>
using namespace std;

int main(){
    long long test;
    cin >> test;

    for(long long m = 0; m < test; m++){

        long long amp,f;
        cin >> amp >> f;

        for(int i = 0; i < f; i++){
            long long cont = 1;
            for(int j = 1; j <= amp; j++) {
                for (int k = 0; k < cont; k++) {
                    cout << j;
                }
                cout << endl;
                cont++;
            }
            cont = amp -1;
            for(int j = amp-1; j > 0; j--){
                for(int k = 0; k < cont; k++){
                    cout << j;
                }
                cout << endl;
                cont--;
            }

            if(m == test -1 && i == f-1){

            }else{
                cout << endl;
            }
        }

    }
}