#include <iostream>
#include <vector>
using namespace std;
vector<int>myarray;

void ordenate(int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j >= 1; j--){
            if(myarray[j-1] > myarray[j]){
                int temphigh = myarray[j-1];
                myarray[j-1] = myarray[j];
                myarray[j] = temphigh;
            }
        }
    }
}

int main(){
    int n,number;
    cin >> n;
    int tempn = n;

    while(tempn--){
        cin >> number;
        myarray.push_back(number);
    }

    ordenate(n);
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << myarray[i] << endl;
        }else{
            cout << myarray[i] << " ";
        }     
    }

    return 0;
}
