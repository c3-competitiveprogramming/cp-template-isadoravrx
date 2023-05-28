#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int>numbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int cont = 0;

    for(int i = 0; i < n; i++){
        bool isrepeated = false;
        for(int j = 0; j < i; j++){
            if(numbers[i] == numbers[j]){
                isrepeated = true;
                break;
            }        
        }
        if(isrepeated == false){
            cont++;
        }
    }

    cout << cont << endl;
}
