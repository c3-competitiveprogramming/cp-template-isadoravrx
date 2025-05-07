#include <iostream>
using namespace std;
int values[] = {1,5,10,20,50};
int caixa[5];
int est[5];

bool hastroco(int troco){
    int sum = 0;
    for(int i = 4; i >= 0; i--){
        if(sum == troco){
            return true;
        }
        if(values[i] <= (troco - sum)){
            while((sum + values[i]) <= troco && caixa[i] > 0){ //enq eu quero pegar mais e tem o que eu pegar
                sum += values[i];
                caixa[i]--;
            }
        }
    }
    if(sum == troco){
        return true;
    }
    return false;
}

int pagamento(int k){
    int sum1 = 0;
    for(int i = 4; i >= 0; i--){
        if(sum1 >= k){
            break;
        }                             //e se eu tiver uma de 50 e uma de 2 e quiser pagar 2?
        while(sum1 < k && est[i] > 0){ //enq eu quero pegar mais e tem o que eu pegar
                sum1 += values[i];
                est[i]--;
                caixa[i]++;
        }
    }
    return sum1;
}

int main(){
    int n;
    cin >> n;

    bool ans = true;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < 5; j++){
            cin >> est[j];
        }
        if(ans){
            int pag = pagamento(k);
            int troco = abs(pag - k);
            if(!hastroco(troco)){
                ans = false;
            }
        }
    }

    if(ans){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}