#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int s, n;
    cin >> s >> n;
    
    vector<pair<int,int>>v;
    for(int i = 0; i < n; i++){
        int xi,yi;
        pair<int, int> p;
        cin >> xi >> yi;
        p.first = xi;
        p.second = yi;
        v.push_back(p);
    }
    
    sort(v.begin(),v.end());
    bool possible = true;
    int sum = s;
    for(int i = 0; i < n; i++){
        if(sum > v[i].first){
            sum += v[i].second;
        }else{
            possible = false;
            break;
        }
    }

    if(possible){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
