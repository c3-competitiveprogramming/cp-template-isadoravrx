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
            temp = temp - (temp/10); //ela sempre come um valor inteiro
        }                                   //decimal é com .
    }

    if(n % 2 == 0){
        if(eat >= n/2){
            return true;
        }
    }else{  //se a divisao não for exata, ele vai arredondar pra baixo
        if(eat > n/2){
            return true;
        }
    }

    return false;

}

int main(){
    cin >> n;

    long long k;
    long long low = 1;//tem que comer pelo menos 1
    long long high  = n;
    k = (long long)((low + high)/2);

    long long ans = 1000000000000000000;
    while(low <= high){
        if(validate(k)){
            high = k - 1;
            ans = min(ans,k);
        }else{
            low = k + 1;
        }

        k = (long long)((low + high)/2);
    }

    cout << ans << endl;
}