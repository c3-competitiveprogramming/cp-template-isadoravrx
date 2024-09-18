#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n, maior=0,soma=0;
    scanf("%d",&n);

    int og[n], dir[n],esq[n];

    for(int i=0;i<n;i++){
        scanf("%d",&og[i]);
        dir[i]=og[i];
        esq[i]=og[i];

        soma+=og[i];

        if(og[i]>og[maior]){
            maior=i;
        }
    }

    int mesa=soma/n;

    vector<int> mais,menos;
    for(int i=0;i<n;i++){
        if(og[i]>mesa){
            mais.push_back(i);
        }
        else if(og[i]<mesa){
            menos.push_back(i);
        }
    }

    int qtd1=0,qtd2=0;
    for(int i=0;i<mais.size();i++){
        int onde=upper_bound(menos.begin(), menos.end(),mais[i])-menos.begin();
        int copos=abs(mesa-og[mais[i]]);
        while(onde<menos.size() && copos>0){
            if(dir[menos[onde]]<mesa){
                if(mesa-dir[menos[onde]]>=copos){
                    dir[menos[onde]]+=copos;
                    qtd1+=(copos*(menos[onde]-mais[i]));
                    copos=0;
                }
                else{
                    copos-=(mesa-dir[menos[onde]]);
                    qtd1+=((mesa-dir[menos[onde]])*(menos[onde]-mais[i]));
                    dir[menos[onde]]=mesa;
                }
            }

            onde++;
        }

        onde=0;
        while(menos[onde]<mais[i] && copos>0){
            if(dir[menos[onde]]<mesa){
                if(mesa-dir[menos[onde]]>=copos){
                    dir[menos[onde]]+=copos;
                    qtd1+=(copos*((n-mais[i])+menos[onde]));
                    copos=0;
                }
                else{
                    copos-=(mesa-dir[menos[onde]]);
                    qtd1+=((mesa-dir[menos[onde]])*((n-mais[i])+menos[onde]));
                    dir[menos[onde]]=mesa;
                }
            }

            onde++;
        }
    }

    for(int i=mais.size()-1;i>=0;i--){
        int onde=lower_bound(menos.begin(), menos.end(),mais[i])-menos.begin();
        int copos=abs(mesa-og[mais[i]]);
        while(onde>=0 && copos>0){
            if(esq[menos[onde]]<mesa){
                if(mesa-esq[menos[onde]]>=copos){
                    esq[menos[onde]]+=copos;
                    qtd2+=(copos*(mais[i]-menos[onde]));
                    copos=0;
                }
                else{
                    copos-=(mesa-esq[menos[onde]]);
                    qtd2+=((mesa-esq[menos[onde]])*(mais[i]-menos[onde]));
                    esq[menos[onde]]=mesa;
                }
            }

            onde--;
        }

        onde=menos.size()-1;
        while(menos[onde]>mais[i] && copos>0){
            if(esq[menos[onde]]<mesa){
                if(mesa-esq[menos[onde]]>=copos){
                    esq[menos[onde]]+=copos;
                    qtd2+=(copos*(mais[i]+(n-menos[onde])));
                    copos=0;
                }
                else{
                    copos-=(mesa-esq[menos[onde]]);
                    qtd2+=((mesa-esq[menos[onde]])*(mais[i]+(n-menos[onde])));
                    esq[menos[onde]]=mesa;
                }
            }

            onde--;
        }
    }

    if(qtd1>qtd2){
        printf("%d\n",qtd2);
    }else{
        printf("%d\n",qtd1);
    }


    return 0;
}