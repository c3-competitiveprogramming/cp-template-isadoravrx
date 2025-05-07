#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string n;
    
    while(cin >> n){
        bool isp = true;
        
        int tempn = stoi(n);
        for(int i = 2; i <= sqrt(tempn); i++){
            if(tempn % i == 0){
                isp = false;
                break;
            }
        }

        if(isp){
            
             string temps = "";

             for(int i = n.size() -1; i >= 0; i--){
                 temps+= n[i];
             }

             int flipped = stoi(temps);
             bool isemirp = true;

             for(int i = 2; i <= sqrt(flipped); i++){
                 if(flipped % i == 0){
                     isemirp = false;
                     break;
                 }
             }

             if(!isemirp || n == temps){
                printf("%d is prime.\n",tempn);
             }else{
                 printf("%d is emirp.\n",tempn);
             }
        }else{
            printf("%d is not prime.\n",tempn);
        }
    }
}
