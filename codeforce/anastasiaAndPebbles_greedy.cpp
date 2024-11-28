#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long sum1 = 0;
    long long sum2 = 0;
    int count = 0;
    while(n--){
        int w;
        cin >> w;
        if(sum1 == 0){
            if(w <= k){
                sum1 += w;
            }else{  
                sum1 += k;
            }
        }else if(sum2 == 0){
            if(w <= k){
                sum2 += w;
            }else{  
                sum2 += k;
            }
        }else{
            count++;
            sum1 = 0;
            sum2 = 0;
        }   

    }
}
