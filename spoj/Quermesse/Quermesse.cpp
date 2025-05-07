#include <iostream>
using namespace std;


int main(){
    int n;

    int t = 1;
    while(cin >> n){
        if(n == 0){
            break;
        }

        if(t != 1){
            cout << endl;
        }
        
        printf("Teste %d\n", t);
        for(int i = 1; i <= n ; i++){
            int num;
            cin >> num;
            if(num == i){
                cout << num << endl;
            }
        }

        t++;
    }
}