#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
long long n, m, w;
long long v[100010];
bool validate(long long mid){
    long long b[100010]; //array aux
    memset(b,0,sizeof(b));

    long long dias_usados = 0;
    long long sum = 0;

    for(int i = 0; i < n; i++){ //tenho que mudar o sum??
        sum += b[i];
        long long num = v[i] + sum;
        if(num < mid){
            if((mid - num) <= m - dias_usados){
                sum += (mid - num);
                if(i + w < n){
                    b[i + w] += -(mid - num);
                }
                dias_usados += (mid - num);
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m >> w;

    long long mn = 10e9;
    long long mx = 0;
    for(long long i = 0; i < n; i++){
        long long num;
        cin >> num;
        v[i] = num;
        mn = min(mn,num);
        mx = max(mx,num);
    }

    long long low = mn;
    long long high = mn + m;
    long long mid = (low + high)/2;

    long long ans = 0;
    while(low <= high){
        if(validate(mid)){
            low = mid + 1;
            ans = max(ans,mid);
        }else{
            high = mid - 1;
        }

        mid = (low + high)/2;
    }

    cout << mid << endl;
}