#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int>numbers;
    int cont = 0;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
        
    }        

    sort(numbers.begin(), numbers.end());
    for(int i = 0; i < n; i++){

        bool isrepeated = false;
        if(i != 0){
            if(numbers[i - 1] == numbers[i]){
                isrepeated = true;
            }
        }
        
        if(isrepeated == false){
            cont++;
        }
    }
    
    cout << cont << endl;
}
