#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int>times;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        times.push_back(num);
    }

    int i = 0;
    int j = 0;
    int sum = 0;
    int maiordist = 0;
    int cont = 0;
    while(true){
        if(j == n){
            break;
        }

        if(sum + times[j] <= t){
            sum += times[j];
            cont++;
            j++;
        }else{
            sum = sum - times[i];
            i++;
            cont--;
        }
 
        if(maiordist < cont){
            maiordist = cont;
        }
    }

    cout << maiordist << endl;
    
}