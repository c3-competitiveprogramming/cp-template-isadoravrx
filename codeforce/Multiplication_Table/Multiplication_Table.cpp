#include <iostream>
#include <cmath>
using namespace std;
long long n, m, k;
double qrep;

long long validate(double mid){
    double qmenoresiguais = 0;

    qrep = -1;
    for(double i = 1; i <= m; i++){
       long long menor_igual = mid / i ;

       if(menor_igual < n){
           qmenoresiguais += menor_igual;
       }else{
           qmenoresiguais += n;
       }

       double isdivisible = mid / i;
       long long isdivis = mid / i;

       if((isdivisible == isdivis) && (mid <= n * i)){
            qrep++;
       }
    }

    if( k >= (qmenoresiguais - qrep)  && k <= qmenoresiguais && qrep > -1){ //qrep > -1 pois ele deve aparecer pelo menos uma vez na tabela.
       return k;
    }

    return qmenoresiguais;
}

int main(){
    cin >> n >> m >> k;

    long long low = 1;
    long long high = n * m;
    long long mid = (low + high)/2;

    long long ans;
    while(low <= high){
        long long pos = validate(mid);
        if(pos == k && qrep != -1){ //caso da qmenoresiguais bater com o k, mas o numero nao estar na tabela ex: 3 3 8
           ans = mid;
           break;
        }else if(pos > k || (pos == k && qrep == -1)){
           high = mid -1;
        }else{
            low = mid + 1;
        }

        mid = (low + high)/2;
    }

    cout << ans << endl;
}
