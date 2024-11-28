#include <iostream>
using namespace std;

void hanoi(int n, char s, char a, char o){
    if(n == 0){
        return;
    }

    hanoi(n-1,s,o,a);
    cout << s << " " << o << endl;
    hanoi(n-1,a,s,o);
}

int main(){
    int n, k;
    cin >> n >> k;

    if( k < ((1 << n) -1) ||k == ((1 << n) )){
        cout << "N" << endl;
    }else{
        cout << "Y" << endl;
        
        hanoi(n,'A','B','C');

        k -= ((1 << n) -1);
        
        if(k % 2 != 0 && k > 0){
            k -= 3;
            cout << "C B" << endl;
            cout << "B A" << endl;
            cout << "A C" << endl;
        }


        for(int i = 0; i < k;  i++){
            if(i % 2 == 0){
                cout << "C B" << endl;
            }else{
                cout << "B C" << endl;
            }
        }
    }
}
