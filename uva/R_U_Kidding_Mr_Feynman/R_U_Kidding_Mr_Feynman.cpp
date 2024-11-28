#include <iostream>
using namespace std;

int bs(double n){
    int low = 1;
    int high = 100;
    int mid = (low+high)/2;

    while(low <= high){
        if(mid * mid * mid == n){
            return mid;
        }
        if(mid*mid*mid < n){
            low = mid + 1;
        }else{
            high = mid -1;
        }

        mid = (low+high)/2;
    }

    return mid;
}

int main(){
    double n;
    

    while(cin >> n){
        if(n == 0){
            break;
        }
        double a = (double)bs(n);
        if(a * a * a == n){
            printf("%.4f\n",a);
            continue;
        }
        double numerador = n - (a*a*a);
        double den = 3*a*a;
        double dx = numerador/den;

        printf("%.4f\n",a+dx);
    }
}
