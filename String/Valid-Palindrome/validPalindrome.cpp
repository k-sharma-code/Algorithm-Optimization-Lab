#include<iostream>
#include<string>
#include<cctype>

 using namespace std;

  bool isValidPalindrome(string str){
    int st = 0, end = str.length()-1;
    while(st < end){
        // skip non-alphanumeric characters at start pointer
        if(!isalnum(str[st])){
            st++; continue;
        }
        //skip non-alphanumeric characters at end pointer
        if(!isalnum(str[end])){
            end--; continue;
        }
        if(tolower(str[st]) != tolower(str[end])){
            return false;
        }
        st++;
        end--;
    }
    return true;
  }
  int main(){
    string str;
    cout<<"Enter a string = ";
    getline(cin,str);

    if(isValidPalindrome(str)){
        cout<<" Valid Palindrome ";
    }else{
        cout<<" Not a Valid Palindrome ";
    }

    return 0;
  }
