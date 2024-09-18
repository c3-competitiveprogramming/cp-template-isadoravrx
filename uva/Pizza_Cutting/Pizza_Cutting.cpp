#include <iostream>
#include <map>
using namespace std;

int main(){

   while(true){
        long long n;
        cin >> n;

        if(n < 0){
            break;
        }

        cout << (((1+n)*n)/2) + 1 << endl;
   }
}