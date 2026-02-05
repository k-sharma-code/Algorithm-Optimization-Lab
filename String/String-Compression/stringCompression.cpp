#include<iostream>
#include<vector>
#include<string>

using namespace std;
int compress(vector<char>& chars){
    int n = chars.size();
    int idx = 0; 

    for(int i = 0; i < n ; i++){
        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch){
            count++;
            i++;
        }
        
        if(count == 1){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            string num = to_string(count);
            for(char dig : num){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}
int main(){
    int n ;
    cout<<"Enter number of characters = ";
    cin >> n;
    vector<char> chars(n);

    cout<<"Enter characters = ";
    for(int i = 0 ; i < n ; i++){
        cin >> chars[i];
    }

    int ans = compress(chars);
    for(int i = 0 ; i < ans ; i++){
        cout<<chars[i]<<" ";
    }

    cout<< " \nNew length = "<<ans<<endl;
    return 0;
}
