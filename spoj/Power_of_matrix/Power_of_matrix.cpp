#include <iostream>
#include <vector>
using namespace std;

long long m,n;
vector<vector<long long> > mult(vector<vector<long long> > &a,vector<vector<long long> > &b){
    vector<vector<long long> >ans(m,vector<long long>(m));
    for(long long i = 0; i < m; i++){
        for(long long j = 0; j < m; j++){
           long long sum = 0;
           for(long long k = 0; k < m; k++){
               sum += ((a[i][k] % 1000000007) * (b[k][j] % 1000000007)) % 1000000007;
           }

           ans[i][j] = sum % 1000000007;
        } 
    }

    return ans;
}

int  main(){
    long long t;
    cin >> t;

    while(t--){
        cin >> m >> n;
        
        vector<vector<long long> >mat(m,vector<long long>(m));
        vector<vector<long long> >ans(m,vector<long long>(m));
        for(long long i = 0; i < m; i++){
            for(long long j = 0; j < m; j++){
                long long num;
                cin >> num;
                mat[i][j] = num;   
                if(i == j){
                    ans[i][j] = 1;
                }
            }
        }

    
        while(n != 0){
            if(n % 2 == 0){
                mat = mult(mat,mat);
                n/=2;
            }else{
                ans = mult(ans,mat);
                n--;
            }
        }

        for(long long i = 0; i < m; i++){
            for(long long j = 0; j < m; j++){
                if(j == m-1){
                    cout << ans[i][j] << endl;
                }else{
                    cout << ans[i][j] << " ";
                }
            }
        }


    }
}
