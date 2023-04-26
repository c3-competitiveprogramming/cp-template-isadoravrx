#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    if(n % 2 != 0 && m % 2 != 0){
        cout << "Paula" << endl;
    }else if(n % 2 != 0 && m % 2 == 0){
        cout << "Carlos" << endl;
    }else if(n % 2 == 0 && m % 2 == 0){
        cout << "Paula" << endl;
    }else if(n % 2 == 0 && m % 2 != 0){
        cout << "Carlos" << endl;
    }
}