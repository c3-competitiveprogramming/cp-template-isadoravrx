#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    
    int plusone = m + 1;
    
    if((n > m + 1 && n <= (2*m +1)) || m > n){
        cout << "Paula" << endl;
    }else{
        if(n % (m + 1) == 0){
            cout << "Carlos" << endl;
        }else{
            cout << "Paula" << endl;
        }
    }

    return 0;
}
 