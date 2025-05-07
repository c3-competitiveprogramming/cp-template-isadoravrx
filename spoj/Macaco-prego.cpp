#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int t = 1;
    int cont = 0;
    while(true){
        cin >> n;

        if(n == 0){
            break;
        }
            
        if(cont != 0){
            cout << endl;
        }
        
        int x,y,u,v;
        int xans = -10001, yans = 10001,uans = 10001,vans = -10001;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> u >> v;
            
            xans = max(xans,x);
            yans = min(yans,y);
            uans = min(uans,u);
            vans = max(vans,v);
        }
        
        cout << "Teste " << t << endl;
        t++;
        if( xans > uans || yans < vans){
            cout << "nenhum" << endl;
        }else{
            cout << xans << " " << yans << " " << uans << " " << vans << endl;
        }
        cont = 1;
    }
}
