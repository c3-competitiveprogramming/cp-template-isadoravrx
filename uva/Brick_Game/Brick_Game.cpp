#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;


        int age;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(i == (n-1)/2){
                age = num;
            }
        }
        cout << "Case "<< i << ": " << age << endl;

    }

}
