#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n, k;
    cin >> n >> k;
    
    double sum = 0;
    for(int i = 0; i < n; i++){
        double w;
        cin >> w;
        sum += ceil(w / k);
    }

    long long div = ceil(sum/2);
    cout << div << endl;
}
