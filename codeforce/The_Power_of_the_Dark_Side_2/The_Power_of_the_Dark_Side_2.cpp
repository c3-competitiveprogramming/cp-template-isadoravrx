#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long>sum;
    vector<long long>two_smallest;
    vector<bool>ganha_delemesmo;

    for(int i = 0; i < n; i++){
        long long a,b,c;
        scanf("%lld %lld %lld", &a, &b, &c);
        sum.push_back(a+b+c);

        long long mx;
        mx = max(a,b);
        mx = max(mx,c);
        two_smallest.push_back(a+b+c-mx); // o +2 pra garantir que é maior nos dois parametros

        if(sum[i] >= (two_smallest[i] + 2)){
            ganha_delemesmo.push_back(true);
        }
    }


    sort(two_smallest.begin(),two_smallest.end());

    for(int i = 0; i < n; i++){
        int ind = (upper_bound(two_smallest.begin(),two_smallest.end(),sum[i] - 2) - two_smallest.begin());

        if(ganha_delemesmo[i]){
            ind--;
        }

        if(i == n-1){
            printf("%d\n", ind);
            return 0;
        }
        printf("%d ", ind);
    }
}
