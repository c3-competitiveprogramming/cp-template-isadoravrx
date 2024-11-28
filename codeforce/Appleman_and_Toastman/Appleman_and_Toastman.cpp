#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    vector<int>v;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    long long sum = 0;
    long long cont = 2;
    for(int i = 0; i < n; i++){
        if(n <= 2){
            sum += v[i] * n;
        }else if(i >= n - 2) {
            sum += v[i] * n;
        }else{
            sum += v[i] * cont;
            cont++;
        }
    }

    cout << sum << endl;
}
