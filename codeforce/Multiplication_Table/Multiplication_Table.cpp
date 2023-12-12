#include <iostream>
#include <cmath>
using namespace std;
int n, m, k;

int validate(double mid){
    double qmenoresiguais = 0;
    double qrep = -1;

    for(double i = 1; i <= m; i++){
       int menor_igual = mid / i ;
       qmenoresiguais += min(menor_igual,n);

       double isdivisible = mid / i;
       int isdivis = mid / i;

       if((isdivisible == isdivis) && (mid <= n * i)){
            qrep++;
       }
    }

    if((qmenoresiguais - qrep) >= k && k <= qmenoresiguais){
       return k;
    }

    return qmenoresiguais;
}

int main(){
    cin >> n >> m >> k;

    int low = 1;
    int high = n * m;
    int mid = (low + high)/2;

    int ans;
    while(low <= high){
        int pos = validate(mid);
        if(pos == k){
           ans = pos;
           break;
        }else if(pos > k){
           high = mid -1;
        }else{
            low = mid + 1;
        }
    }

    cout << ans << endl;
}