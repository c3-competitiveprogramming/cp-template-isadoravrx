#include <iostream>
#include <vector>
using namespace std;
vector<long>money;
int dias;

int main(){
    cin >> dias;
    for(int i = 0; i < dias; i++){
        long moneyday;
        cin >> moneyday;
        money.push_back(moneyday);
    }
    
    if(dias == 1){
        cout << "1" << endl;
    }else{
   
        long bestlength = 1;
        long nowlenght = 1;
        long nowvalue;
        long lastvalue = money[0];
        for(int i = 1; i < dias; i++){
            nowvalue = money[i];
            if(nowvalue >= lastvalue){
                nowlenght++;
                if(nowlenght >= bestlength){
                    bestlength = nowlenght;
                }
    
            }else{
                nowlenght = 1;
            }

            lastvalue = nowvalue;
        }

        cout << bestlength << endl;
    
    }

    return 0;
}