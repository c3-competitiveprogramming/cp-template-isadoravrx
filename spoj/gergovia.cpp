#include <iostream>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    int n;

    while(true){
        cin >> n;

        if(n == 0){
            break;
        }

        map<int,int>mp;
        deque<int>ic;//indice compra
        deque<int>iv;//indice venda

        long long int sum = 0;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;

            mp[i] = abs(num);
            if(num < 0){
                if(ic.empty()){
                    iv.push_back(i);
                }else{
                    int compra = ic.front();
                    ic.pop_front();
                    if(abs(num) > mp[compra]){ 
                        sum += (i - compra) * mp[compra];
                        mp[i] = abs(num) - mp[compra];
                        iv.push_back(i);
                    }else{  
                        sum += (i - compra) * mp[i];
                        mp[compra] = mp[compra] - abs(num);
                        ic.push_front(compra);
                    }       
                } 
            }else{
                if(iv.empty()){
                    ic.push_back(i);
                }else{
                    int venda = iv.front();
                    iv.pop_front();
                    if(num > mp[venda]){
                        sum += (i - venda) * mp[venda];
                        mp[i] = num - mp[venda];
                        ic.push_back(i);
                    }else{
                        sum += (i - venda) * mp[i];
                        mp[venda] = mp[venda] - num;
                        iv.push_front(venda);
                    }
                }
            }
        }


        while(!ic.empty()){
            int num = mp[ic.front()];
            int i = ic.front();
            ic.pop_front();
            int venda = iv.front();
            iv.pop_front();
            if(num > mp[venda]){
                sum += abs(i - venda) * mp[venda];
                mp[i] = num - mp[venda];
                ic.push_back(i);
            }else{
                sum += abs(i - venda) * mp[i];
                mp[venda] = mp[venda] - num;
                iv.push_front(venda);
            }

        }

        cout << sum << endl;
    }
}
