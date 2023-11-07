#include <iostream>
using namespace std;
long long n;

bool validate(long long k){
    long long temp = n;
    long long eat = 0;
    while(true){
        if(temp > 0){
            if(temp >= k){
                eat += k;
                temp -= k;
            }else{
                eat += temp;
                temp = 0;
            }
        }else{
            break;
        }

        if(temp >= 10){
            temp = temp - (0,1 * temp);
        }
    }

    if(eat >= n/2){
        return true;
    }

    return false;
}

int main(){
    cin >> n;

    long long k;
    long long low = 0;
    long long high  = n - 1;
    k = (low + high)/2;

    while(low <= high){
        if(validate(k)){
            high = k -1;
        }else{
            low = k + 1;
        }

        k = (low + high)/2;
    }

    cout << k << endl;
}