#include <iostream>
using namespace std;


int main(){
    int ca,cb,r;
    cin >> ca >> cb >> r;

    int sex = ca-r;
    int sey = cb + r;


    int sdx = ca+r;
    int sdy = cb + r;

    int iex = ca -r;
    int iey = cb-r;

    int idx = ca + r;
    int idy = cb -r;


    cout << sdx << " " << sdy << endl;
    cout << idx << " " << idy << endl;
    cout << iex << " " << iey << endl;
    cout << sex << " " << sey << endl;

}