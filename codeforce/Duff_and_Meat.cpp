#include <iostream>
using namespace std;

int main(){
    int n;

    cin >> n;
    int sum  = 0;
    int mini = 101;
    for(int i = 0; i < n; i++){
        int meat, cost;
        cin >> meat >> cost;
        mini = min(mini,cost);
        sum += meat * mini;
    }

    cout << sum << endl;
}
