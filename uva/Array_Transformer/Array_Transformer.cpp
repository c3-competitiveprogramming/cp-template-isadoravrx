#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,m,u;
    scanf("%d %d %d",&n, &m, &u);

    vector<int>original(n);
    for(int i=0;i<n;i++){
        scanf("%d",&original[i]);
    }

    for(int i=0;i<m;i++){
        int l,r,v,p, cont=-1;
        scanf("%d %d %d %d",&l,&r,&v,&p);

        vector<int> novo=original;
        sort(novo.begin()+(l-1), novo.begin()+r);

        int low=l-1, high=r-1, mid;
        while(low<=high){
            mid=(high+low)/2;
            if(novo[mid]<v){
                low=mid+1;
            }
            else{
                cont=mid-(l-1);
                high=mid-1;
            }
        }

        if(cont==-1){
            cont=r;
        }

        original[p-1]=(u*cont)/(r-l+1);
    }

    for(int i=0;i<n;i++){
        printf("%d\n",original[i]);
    }


    return 0;
}