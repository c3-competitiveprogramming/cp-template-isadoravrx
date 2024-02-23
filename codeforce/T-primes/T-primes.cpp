#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
       
        double mynum = num;
        long long cont = 0;
        for(int j = 1; j <= sqrt(num); j++){
            if(cont > 3){
                break;
            }
            if(num % j == 0){
                cont++;
            }
        }

        double half = mynum /2;
        int myhalf = num/2;
        
        cont++;
        if(half == myhalf && sqrt(num) < myhalf){
            cont++;
        }

        if(cont == 3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
