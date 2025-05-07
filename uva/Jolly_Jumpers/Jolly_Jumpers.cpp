#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        map<int, int> s;
        int a,b;
        bool eh=true;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(i>0){
                int c=abs(a-b);
                if(c > n-1 || c<1){
                    eh=false;
                }

                if(s.find(c)!=s.end()){
                    eh=false;
                }

                s[c]=c;
            }
            b=a;
        }
        
        if(eh || n==1){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }

    return 0;
}
