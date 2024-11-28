#include <iostream>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    long long n;

    while(true){
        cin >> n;

        if(n == 0){
            break;
        }

        map<long,long>mp;
        deque<long>ic;//indice compra
        deque<long>iv;//indice venda

        long long sum = 0;
        for(long long i = 0; i < n; i++){
            long long num;
            cin >> num;

            mp[i] = abs(num);
            if(num < 0){
                if(ic.empty()){
                    iv.push_back(i);
                }else{
                    while(true){
                        if(ic.empty()){
                            break;
                        }
                        long long compra = ic.front();
                        ic.pop_front();
                        if(abs(num) > mp[compra]){ 
                            sum += (i - compra) * mp[compra];
                            mp[i] = abs(num) - mp[compra];
                            iv.push_front(i);
                        }else{  
                            sum += (i - compra) * mp[i];
                            mp[compra] = mp[compra] - abs(num);
                            if(mp[compra] != 0){
                                ic.push_front(compra);
                            }

                            break;
                        }   
                    }
                } 
            }else{
                if(iv.empty()){
                    ic.push_back(i);
                }else{
                    while(true){
                        if(iv.empty()){
                            break;
                        }
                        long long venda = iv.front();
                        iv.pop_front();
                        if(num > mp[venda]){
                            sum += (i - venda) * mp[venda];
                            mp[i] = num - mp[venda];
                            ic.push_back(i);
                        }else{
                            sum += (i - venda) * mp[i];
                            mp[venda] = mp[venda] - num;
                            if(mp[venda] != 0){
                                iv.push_front(venda);
                            }

                            break;
                        }
 
                    }
                }
            }
        }

        cout << sum << endl;
    }
}
