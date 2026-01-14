#include<iostream>
#include<vector> 
using namespace std;
vector<int>prodExceptself(vector<int>& arr){
    int n= arr.size();
    vector<int>ans(n,1);
    for(int i=1 ;i<n;i++){ // to calculate prefix
        ans[i]=ans[i-1]*arr[i-1];
    }
    int suffix = 1 ; // to calculate suffix
    for(int i=n-2;i>=0; i--){
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter array size = ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result=prodExceptself(arr);
    cout<<"the product of an given array except self = ";
    for(int i=0;i<n;i++){
    cout<<result[i]<<" ";
    }
    return 0;

}
