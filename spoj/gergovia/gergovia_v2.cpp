#include <iostream>
using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;

        if(n == 0){
            break;
        }
        
        long long sum = 0;
        long long acum = 0;

        for(int i = 0; i < n; i++){
            long long num;
            cin >> num;
            acum += num;
            sum += abs(acum);
        }

        cout << sum << endl;
    }
}
