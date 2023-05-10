#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>segundos;

    for(int i = 0; i < n; i++){
        int segundo;
        cin >> segundo;
        segundos.push_back(segundo);
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            sum += 10;
        }else if(segundos[i + 1] - segundos[i] < 10){
            sum += segundos[i + 1] - segundos[i];
        }else{
            sum += 10;
        }
    }

    cout << sum << endl;
    return 0;
}