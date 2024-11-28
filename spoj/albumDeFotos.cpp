#include <iostream>
using namespace std;

int main(){
    int xpg,ypg;
    int c1,l1,c2,l2;
    cin >> xpg >> ypg >> c1 >> l1 >> c2 >> l2;
    bool cabe = true; 
    if(((c1 + c2 <= xpg) && (l1 <= ypg) && (l2 <= ypg)) || ((max(c1,c2) <= xpg) && (l1 +l2 <= ypg))){ 
        cout << "S" << endl;
    }else if(((c1 + l2 <= xpg) && (c2 <= ypg) && (l1 <= ypg)) || ((max(c1,l2) <= xpg) && (l1 +c2 <= ypg))){
        cout << "S" << endl;
    }else if(((l1 + c2 <= xpg) && (c1<= ypg) && (l2 <= ypg)) || ((max(l1,c2) <= xpg) && (c1 + l2 <= ypg))){
        cout << "S" << endl;
    }else if(((l1 + l2 <= xpg) && (c1 <= ypg) && (c2 <= ypg)) ||((max(l1,l2) <= xpg) && (c1 + c2 <= ypg))){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
    
    return 0;
}