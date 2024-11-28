#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n;
    
    while(true){
        cin >> n;

        if(n == 0){
            break;
        }
    
        vector<int>v;
        deque<int>d;
        int truenum = 1;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            
            if(num == truenum){
                v.push_back(num);
                truenum++;
                while(true){
                    if(!d.empty() && d[0] == truenum){
                        d.pop_front();
                        v.push_back(d[0]);
                        truenum++;
                    }else{
                        break;
                    }
                }
            }else{
                d.push_front(num);
            }
        }

        if(d.empty()){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
