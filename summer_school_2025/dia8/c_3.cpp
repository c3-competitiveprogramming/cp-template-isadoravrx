#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int n,m;
ll sumcarac = 0;

void mult2(string s){
    int i = s.size() -1;
    int resto = 0;
    int soma;
    while(i >= 0){
        soma = (s[i] - '0') * 2;
        soma += resto;
        resto = soma/10;
        soma = soma % 10;
        sumcarac += soma;
        if(sumcarac > m){
            return;
        }
        i--;
    }

    if(resto > 0){
        soma = resto;
        sumcarac += soma;
    }
}

string increment_string(string a, ll n){
    string b=to_string(n);
    string s="";
    int i=a.size()-1, j=b.size()-1, resto=0;
    while(i>=0 && j>=0){
        int soma=0;
        if(i>=0){
            soma+=(a[i]-'0');
        }
        if(j>=0){
            soma+=(b[j]-'0');
        }

        soma+=resto;

        resto=soma/10;
        soma=soma%10;
        s.insert(0,1,soma+'0');

        i--,j--;
    }

    if(resto>0){
        s.insert(0,1,resto+'0');
    }

    return s;

}

ll sumIsolated(string s){
    ll sum = 0;

    for(int i = 0; i < s.size(); i++){
        sum += s[i] - '0';
    }

    return sum;
}


int main(){
    
    cin >> n >> m;

    ll sum = sumIsolated(to_string(n));
    string s = to_string(sum);
    ll lastdigitofs = s[s.size() -1] - '0';
    ll iniIntervalo = sum-lastdigitofs, fimIntervalo = sum + 9 - lastdigitofs ;
    

    ll qincrementos = 0;
    while(true){
        sumcarac = 0;
        mult2(to_string(sum)); 
        if(sum >= n && sumcarac <= m){
            break;
        }  

        if(sum +1 > fimIntervalo ){  //como eu sei que acabou o intervalo
            iniIntervalo++;
            fimIntervalo++;
            sum = iniIntervalo;
        }else{
            sum++;
        }
        qincrementos++;
    }



    s = increment_string(s, qincrementos);
    


    cout << s << endl;
    cout << s << endl;
}