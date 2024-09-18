#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long>a;
long long n, k;
vector<long long>v;


bool bs(long long value){
    int low = 0;
    int high = a.size() - 1;
    int mid = (low + high)/2;

    while(true){
        if(low > high){
            break;
        }
        
        if(a[mid] * k == value){
            return false;
        }

        if(a[mid] * k < value){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    
        mid = (low + high) /2;
    }
    
    return true;
}

int main(){
    
    cin >> n >> k;

    
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    int i = 0;
    while(true){
        
        if(i == n){
            break;
        }

        if(bs(v[i])){
            a.push_back(v[i]);
        }

        i++;
    }

    cout << a.size() << endl;
}
