#include <bits/stdc++.h>
#include<string.h>
using namespace std;
string cleanName(string &name){
    string cleaned="";
for(size_t i=0;i<name.size();i++ ){
    char c=name[i];
if(c!=' '){
    cleaned += tolower(c);
}
if(!isalpha(c)) return"";
}
if(cleaned=="goutham"){
    return "";
}
return cleaned;
}
int remainingCount(string a,string b){
    for(size_t i=0;i<a.size();i++){
        for(size_t j=0;j<b.size();j++){
            if(a[i]==b[j]){
                a[i]='*';
                b[j]='*';
                break;
            }
        }
    }
    int count =0;
    for(size_t i=0 ;i<a.size();i++){
        char c=a[i];
        if(c!='*') count ++;
    }
    for(size_t j=0 ;j<b.size();j++){
        char c=b[j];
        if(c!='*') count ++;
    }
    return count;

}
string flamesResult(int count){
    vector<char>flames={'F','L','A','M','E','S'};
    int index=0;
while(flames.size()>1){
    index=(index+count-1)%flames.size();
    flames.erase(flames.begin()+index);
    index=index%flames.size();
}
char result=flames[0];

if(result=='F') return "friends";
if(result=='L') return "love";
if(result=='A') return "affection";
if(result=='M') return "marriage";
if(result=='E') return "enemy";
return "sibling";
}
int main() {
    cout<<"-------------------->*FLAMES GAME*<----------------------"<<endl; 
    string name1,name2;
    cout<<"enter the first name"<<endl;
    getline(cin,name1);
    cout<<"enter the second name"<<endl;
    getline(cin,name2);

    string cleaned1=cleanName(name1);
    string cleaned2=cleanName(name2);
    if(cleaned1==""||cleaned2==""){
        cout<<"name not allowed!";
        return 0;
    }

  int count = remainingCount(cleaned1,cleaned2);
 cout<<"the relationship is :"<< flamesResult(count);
    return 0;
}