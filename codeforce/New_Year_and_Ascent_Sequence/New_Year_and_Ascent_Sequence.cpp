#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>>v;
vector<int>max;
vector<bool>isAscedent;

bool hasAscedent(int indv1,int indv2){
    int low = 0;
    int high = v[indv2].size() - 1;
    int mid = (low + high)/2;

    while(low <= high){
        if(v[indv1][0] < v[indv2][mid]){
            return true;
        }
        low = mid + 1;
        mid = (low + high)/2;
    }
    return false;
}

int main(){
    cin >> n;
    v.resize(n);
    for(int i  = 0; i < n; i++){
        int len;
        cin >> len;
        int cont = 0;
        int last;
        for(int j = 0; j < len; j++){
            int num;
            cin >> num;
            if(j != 0){
                if(last < num){

                }
            }
            v[i].push_back(num);
            last = num;
        }
        sort(v[i].begin(),v[i].end());
    }

    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(){

            }
        }
    }

    cout << cont << endl;
}