#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numbers;
    int n, number;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> number;
            numbers[i].push_back(number);
        }
    }

    
}