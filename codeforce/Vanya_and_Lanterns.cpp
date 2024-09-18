#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    double n,l;
    cin >> n >> l;

    vector<double>v;
    for(int i = 0; i < n; i++){
        double num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    
    double mx = 0;
    if(v.size() == 1){
        mx = max(v[0], l - v[0]);
    }else{
        for(int i = 0; i < v.size(); i++){
            if(i == 0){
                mx = max(mx,v[i]);
            }else if(i == v.size() - 1){
                mx = max(mx,l - v[i]);
                mx = max(mx, (v[i] - v[i - 1])/2);
            }else{
                mx = max(mx,(v[i] - v[i - 1])/2);
            }
        }
    }
    

    printf("%.10f\n",mx);
}