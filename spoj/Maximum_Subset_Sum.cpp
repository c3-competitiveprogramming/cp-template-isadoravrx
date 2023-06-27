#include <iostream>
#include <vector>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        
        vector<int>v;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }

        int i = 0;
        int j = 1;
        int sum = v[i];
        int bestsum = sum;

        while(true){
            if(j == n){
                break;
            }

            if(sum + v[j] > bestsum){
                sum += v[j];
                j++;
            }else{
                sum = sum - v[i];
                i++;
            }

            if(sum > bestsum){
                bestsum = sum;
            }
        }

        cout << bestsum << endl;
    }
}
