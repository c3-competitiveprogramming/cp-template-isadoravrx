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
        int xans = 0,yans = 0,uans = 0,vans = 0;
        int xmax = -10000, ymin = 10000 ,umin = 10000,vmax = -10000;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> u >> v;
            if(xmax < x && x < umin && vmax < y && y < ymin){
                xans = x;
                yans = y;
            }if(xmax < u && u < umin && vmax < v &&   v < ymin){
                uans = u;
                vans = v;
            }

            xmax = max(xmax,x);
            ymin = min(ymin,y);
            umin = min(umin,u);
            vmax = max(vmax,v);
        }
        
        cout << "Teste " << t << endl;
        t++;
        if(n == 1 || (xans != 0 && yans != 0 && uans != 0 && vans != 0)){
            cout << xans << " " << yans << " " << uans << " " << vans << endl;
        }else{
            cout << "nenhum" << endl;
        }
        cont = 1;
    }
}
