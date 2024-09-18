#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int iii;

string separar(string s){
    string x="";
    while(s[iii]!=':' && s[iii]!=',' && s[iii]!='}'){
        x+=s[iii];
        iii++;
    }

    return x;
}

int main(){

    int t;
    cin>>t;
    
    string um,dois;
    while(t--){
        cin>>um>>dois;

        vector< pair<string, string> > d1,d2;

        iii=1;
        while(iii<um.size()){
            string key=separar(um); iii++;
            if(iii>=um.size()){
                break;
            }
            string value=separar(um); iii++;
            d1.push_back(make_pair(key,value));
        }
        iii=1;
        while(iii<dois.size()){
            string key=separar(dois); iii++;
            if(iii>=dois.size()){
                break;
            }
            string value=separar(dois); iii++;
            d2.push_back(make_pair(key,value));
        }

        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());

        vector<string> change, novo, old;

        int i=0,j=0;
        while(i<d1.size() && j<d2.size()){
            if(d1[i].first==d2[j].first && d1[i].second==d2[j].second){
                i++;j++; continue;
            }

            if(d1[i].first==d2[j].first){
                change.push_back(d1[i].first);
                i++;j++; continue;
            }

            if(d1[i].first>d2[j].first){
                novo.push_back(d2[j].first);
                j++;
            }
            else{
                old.push_back(d1[i].first);
                i++;
            }
        }

        if(i< d1.size()){
            while(i<d1.size()){
                old.push_back(d1[i].first);
                i++;
            }
        }

        if(j<d2.size()){
            while(j<d2.size()){
                novo.push_back(d2[j].first);
                j++;
            }
        }


        if(um.size()==2){
            old.clear();
            change.clear();
        }
        if(dois.size()==2){
            novo.clear();
            change.clear();
        }

        if(change.size()==0 && novo.size()==0 && old.size()==0){
            cout<<"No changes"<<endl<<endl;
            continue;
        }

        if(novo.size()>0){
            cout<<"+";
            for(i=0;i<novo.size();i++){
                cout<<novo[i];
                if(i<novo.size()-1){
                    cout<<",";
                }
            }
            cout<<endl;
        }
        if(old.size()>0){
            cout<<"-";
            for(i=0;i<old.size();i++){
                cout<<old[i];
                if(i<old.size()-1){
                    cout<<",";
                }
            }
            cout<<endl;
        }
        if(change.size()>0){
            cout<<"*";
            for(i=0;i<change.size();i++){
                cout<<change[i];
                if(i<change.size()-1){
                    cout<<",";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}