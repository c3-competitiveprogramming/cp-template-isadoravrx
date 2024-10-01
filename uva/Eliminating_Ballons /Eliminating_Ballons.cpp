#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int ans = 0;
    vector<int>visited(n);
    for(int i = 0; i < n ; i++){
        if(visited[i] != 0){
            continue;
        }

        ans++;
        int exp = v[i] - 1;
        for(int j = i+1; j < n ; j++){
            if(v[j] == exp){
                exp--;
                visited[j] = 1;
            }

            if(exp==0){break;}
        }
    }

    cout << ans << endl;

    return 0;
}