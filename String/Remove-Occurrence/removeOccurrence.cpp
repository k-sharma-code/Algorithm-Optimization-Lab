#include<iostream>
#include<string>

using namespace std;
string removeOccurrence(string str , string part){
    size_t pos = str.find(part);
    while(pos != string::npos){
        // to remove the substring from position
        str.erase(pos , part.length());
        // To find the next occurrence 
        pos =  str.find(part);

    }
    return str;
}
int main(){
    string str , part;
    cout<<"Enter original string = ";
    getline(cin , str);
    cout<<"Enter substring to remove = ";
    getline(cin , part);
    
    cout<<removeOccurrence(str,part);
    return 0;
}
