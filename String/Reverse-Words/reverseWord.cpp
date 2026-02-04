#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reverseWord(string s ){
    int n = s.length();
    string ans = "";
    // Reverse the entire sentence
    reverse(s.begin(),s.end());
    for(int i = 0 ; i < n ; i++){
        string word = "";
        while(i < n && s[i] != ' '){
            word += s[i];
            i++;
        }
        //To Reverse individual word
        reverse(word.begin(), word.end());
        if(word.length() > 0){
            ans += " " + word;
        }
    }
    return ans.substr(1);

}
int main(){
    string s ;
    cout<<"Enter Sentence = ";
    getline(cin,s);

    cout<<" reversed
      Sentence = "<<reverseWord(s)<<endl;

    return 0;
}
