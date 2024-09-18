#include <iostream>
#include <string>
using namespace std;


int main(){
    string s1,s2;

    while(getline(cin,s1) && getline(cin,s2)){
        double sum1 = 0;
        double sum2 = 0;

        for(int i = 0; i < s1.size(); i++){
            if(s1[i] >= 97 && s1[i] <= 122){
                sum1+= s1[i] - 96;
            }else if(s1[i] >= 65 && s1[i] <= 90){
                sum1 += s1[i] - 64;
            }
        }

        for(int i = 0; i < s2.size(); i++){
            if(s2[i] >= 97 && s2[i] <= 122){
                sum2+= s2[i] - 96;
            }else if(s2[i] >= 65 && s2[i] <= 90){
                sum2 += s2[i] - 64;
            }
        }
        
        double resul1 = sum1;
        double resul2 = sum2;
        
        string s3 = to_string(resul1);
        string s4 = to_string(resul2);
        while(true){
            int s3int = stoi(s3);
            string stemp = to_string(s3int);
            if(stemp.size() == 1){
                resul1 = stoi(s3);
                break;
            }
            double sum = 0;
            for(int i = 0; i < s3.size(); i++){
                if(s3[i] == '.'){
                    break;
                }
                sum += (s3[i] - '0');
            }            
            
            s3 = to_string(sum);
        }

         while(true){
             int s4int = stoi(s4);
             string stemp = to_string(s4int);
            if(stemp.size() == 1){
                resul2 = stoi(s4);
                break;
            }
            double sum = 0;
            for(int i = 0; i < s4.size(); i++){
                if(s4[i] == '.'){
                    break;
                }
                sum += (s4[i] - '0');
            }            
            
            s4 = to_string(sum);
        }
        
         if(((min(resul1,resul2) / max(resul1,resul2)) * 100) <= 100){
            printf("%.2f ",(min(resul1,resul2) / max(resul1,resul2)) * 100);
             cout << "%" << endl;
 
         }else{
             cout << "100.00 %" << endl;
         }

    }
}
