#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){

    int n,k, cont=0, pagar=0,custo;
    scanf("%d %d",&n,&k);
    map<int,int> m;
    for(int i=0;i<n;i++){
        scanf("%d",&custo);

        if(cont==k){
            cont=0;
            m[custo]=1;
        }else if(m.size()>0){
            auto it=m.begin();
            if(it->first<custo){
                pagar+= it->first;
                m.erase(it);
                m[custo]=1;
                cont++;
            }
        }else{
            cont++;
            pagar+=custo;
        }

    }
    printf("%d\n",pagar);

    return 0;
}