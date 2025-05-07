#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,number,min,max;

    cin >> n;
    vector<int>numbers;
    int tempn = n;
    while(tempn--){
        cin >> number;
        numbers.push_back(number);
    }

    int quantSomas;
    int count = 0;
    cin >> quantSomas;
    while(quantSomas--){
        cin >> min >> max;
        for(int i = min; i <= max; i++){
            count += numbers[i]; 
        }

        cout << count << endl;
        count = 0;
    }

    return 0;
}