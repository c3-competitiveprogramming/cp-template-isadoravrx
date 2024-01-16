#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long>sum;
    vector<long long>two_smallest;

    for(long long i = 0; i < n; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        sum.push_back(a+b+c);

        vector<long long> v = {a,b,c};
        sort(v.begin(),v.end());
        two_smallest.push_back(v[0] + v[1] + 2); // o +2 pra garantir que é maior nos dois parametros
    }.


    sort(two_smallest.begin(),two_smallest.end());

    for(long long i = 0; i < n; i++){
        long long ind = (upper_bound(two_smallest.begin(),two_smallest.end(),sum[i]) - two_smallest.begin());

        long long ans = ind - 1;
        if(ans < 0){
            ans = 0;
        }
        if(ind >= n){
            if(two_smallest[0] < sum[i]){
                ans = n -1;
            }else{
                ans = 0;
            }
        }

        if(i == n-1){
            cout << ans << endl;
        }else{
            cout << ans << " ";
        }
    }
}
