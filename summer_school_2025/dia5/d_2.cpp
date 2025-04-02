#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll>v;
    ll sum = 0;
    ll qnegouzero = 0, qpos=0;
    ll neg1=1,neg2=1,menorpos=0;
    ll num;

    while(cin >> num){
        v.push_back(num);
        if(num > 0){
            qpos++;
            sum += num;
            if(menorpos==0 || menorpos>num){
                menorpos=num;
            }
        }else {
            qnegouzero++;
            if(neg1==1){
                neg1=num;
            }else if(neg2==1){
                neg2=num;
                if(neg2>neg1){
                    ll temp=neg1;
                    neg1=neg2;
                    neg2=temp;
                }
            }else{
                if(num>neg1){
                    neg2=neg1;
                    neg1=num;
                }else if(num>neg2){
                    neg2=num;
                }
            }
        }
    }


    if(n == 1){
        cout << v[0] + v[1] << endl;
    }else if(qpos == 0){
        cout << neg1 + neg2 << endl;
    }
    else if(qnegouzero % 2 != 0){
        if(neg1+menorpos >0){
            sum+=neg1;
        }else{
            sum-=menorpos;
        }

        cout << sum << endl;
    }else{
        cout << sum << endl;
    }

    return 0;
}