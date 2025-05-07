#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<long long>v(500002);
int main(){
    for(int i = 2; i <= 500000; i++){
        long long sum = 1;
        for(int j = 2; j <= sqrt(i); j++){
            if(i %  j == 0){
                sum += j;
                if(sqrt(i) != j){
                    sum += (i / j);
                }
            }
        }
    
        v[i] = sum;
    }

    
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int num;
        cin >> num;
        cout << v[num] << endl;
    }
}
