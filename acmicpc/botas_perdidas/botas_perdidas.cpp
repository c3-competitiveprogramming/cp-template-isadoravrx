#include<iostream>
#include<map>
using namespace std;

int main(){

    int n;
    while(cin>>n){
        map<int, int> dir,esq;
        int tam,qtd=0;
        char pe;
        for(int i=0;i<n;i++){
            cin>>tam>>pe;
            if(pe=='D'){
                if(esq.find(tam)==esq.end() || esq[tam]==0){
                    dir[tam]++;
                }
                else{
                    esq[tam]--;
                    qtd++;
                }
            }else{
                if(dir.find(tam)==dir.end() || dir[tam]==0){
                    esq[tam]++;
                }
                else{
                    dir[tam]--;
                    qtd++;
                }
            }
        }

        printf("%d\n",qtd);
    }

    return 0;
}