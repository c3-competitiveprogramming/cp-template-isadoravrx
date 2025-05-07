#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long>sum,two_smallest;
    vector<int>ganha_delemesmo;

    for(int i = 0; i < n; i++){
        long long a,b,c;
        scanf("%lld %lld %lld", &a, &b, &c);
        sum.push_back(a+b+c);

        long long mx;
        mx = max(a,b);
        mx = max(mx,c);
        two_smallest.push_back(a+b+c-mx);

        if(sum[i] >= (two_smallest[i] + 2)){
            ganha_delemesmo.push_back(-1);
        }else{
            ganha_delemesmo.push_back(0);
        }
    }


    sort(two_smallest.begin(),two_smallest.end());

    for(int i = 0; i < n; i++){
        int ind = (upper_bound(two_smallest.begin(),two_smallest.end(),sum[i] - 2) - two_smallest.begin()); //ind do primeiro que ganha de mim

        ganha_delemesmo[i] += ind;

        if(i == n-1){
            printf("%d\n", ganha_delemesmo[i]);
            return 0;
        }
        printf("%d ", ganha_delemesmo[i]);
    }
}
