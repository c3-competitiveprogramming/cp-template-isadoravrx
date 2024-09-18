#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

bool maiusculo(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ' && int(s[i]) >= 65 && int(s[i]) <= 90){
            return true;
        }
    }

    return false;
}

bool mysort(pair<int,string>s1, pair<int,string>s2){
    if(s1.first == s2.first){
        if(s1.second < s2.second){
            return true;
        }else{
            return false;
        }
    }else{
        return true;
    }
}

int main(){
    string projeto;

    while(getline(cin,projeto)){
        if(projeto[0] == '0'){
            return 0;
        }

        string aluno;
        map<string,string>students_and_projects;
        map<string, int>quantidade_por_projeto;
        quantidade_por_projeto[projeto] = 0;
       
        while(getline(cin,aluno)){
            
            if(aluno[0] == '1'){
                break;
            }
            
            if(maiusculo(aluno)){
                projeto = aluno;
                quantidade_por_projeto[projeto] = 0;
                continue;
            }

            if(students_and_projects.find(aluno) == students_and_projects.end()){
                students_and_projects[aluno] = projeto;
            }else{
                if(students_and_projects[aluno] != projeto){
                    students_and_projects[aluno] = "0";
                }
            }
            
            
        }


       
        for(auto it : students_and_projects){
            if(it.second != "0"){
                quantidade_por_projeto[it.second]++;
            }
        }

        vector<pair<int,string> >ans;

        for(auto it : quantidade_por_projeto){
            ans.push_back(make_pair(it.second,it.first));
        }

        sort(ans.begin(),ans.end());
        sort(ans.begin(),ans.end(), mysort);

        for(auto it : ans){
            cout << it.second << " " << it.first << endl;
        }
    }
}