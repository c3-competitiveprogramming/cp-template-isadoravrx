#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;
int main(int argc, char * argv[]){
    int t; 
    int n;
    cin >> t;
    while(t--){
        cin >> n;
        ll sum = 0;
        ll best = 0;
        while(n--){
            int i;
            cin >> i;
            sum += i;
            if(sum < 0){
                sum = 0;
            }
            best = max(sum,best);
            
        }
        cout << best << endl;
    }
}
