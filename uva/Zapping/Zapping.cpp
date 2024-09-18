#include<iostream>
using namespace std;

int main(){


    int a,b;
    while(cin>>a>>b && a+b!=-2){
        int res=abs(a-b);
        if(res>50){
            res=100-res;
        }

        cout<<res<<endl;
    }

    return 0;
}
