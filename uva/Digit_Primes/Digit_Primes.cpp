#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int bt[1000002];
    long long digitprimes = 0;
    for(int i = 2; i <= 1000000; i++){
        string s;
        s = to_string(i);

        int sum = 0;

        for(int j = 0; j < s.size(); j++){
            sum += (s[j] - '0');
        }

        bool sumprime = true;
        bool iprime = true;
        int j = 2;
        for(; j <= min(sqrt(sum),sqrt(i)); j++){
            if(sum % j == 0){
                sumprime = false;
                break;
            }

            if(i % j == 0){
                iprime = false;
                break;
            }
        }

        if(sumprime && iprime){
            int julgado;
            if(sqrt(i) > sqrt(sum)){
                julgado = i;
            }else{
                julgado = sum;
            }
            for( ; j <= sqrt(julgado);j++){
                if(julgado % j == 0){
                    if(julgado ==  i){
                        iprime = false;
                    }else{
                        sumprime = false;
                    }

                    break;
                }
            }

        }

        if(sumprime && iprime && sum != 1){
            digitprimes++;
        }
        
        bt[i] = digitprimes;
    }

    int n;
    scanf("%d",&n);

    while(n--){
        int t1,t2;
        scanf("%d %d",&t1,&t2);

        printf("%d\n",bt[t2]-bt[t1-1]);
    }
}
