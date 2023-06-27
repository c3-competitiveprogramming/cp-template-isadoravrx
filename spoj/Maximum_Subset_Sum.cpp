#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        
        vector<int>v;
        int mn = 0;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            mn = min(mn,num);
            
            v.push_back(num);
        }

        int i = 0;
        int j = 1;
        int sum = v[0];
        int bestsum = mn;

        while(true){
            if(j == n){
                break;
            }

            if(sum + v[j] > bestsum){
                sum += v[j];
                j++;
            }else{
                
                if(v[i] < 0){
                    sum = sum + v[i];
                }else{
                    sum = sum - v[i];
                }

                i++;
               
            }

            
            bestsum = max(bestsum,sum);
            
        }

        cout << bestsum << endl;
    }
}
