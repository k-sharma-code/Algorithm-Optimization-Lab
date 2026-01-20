#include<iostream>
#include<vector>
using namespace std;

int findsingleelement(vector<int>&arr){
    int n=arr.size();
    
    if(n==1) return arr[0];

    int st=0, end=n-1;
    while(st<=end){
        int mid = st +(end-st)/2;

        if(mid==0 && arr[0]!=arr[1]) return arr[mid];
        if(mid==n-1 && arr[n-1]!=arr[n-2]) return arr[mid];

        if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1]) return arr[mid];
    
        if(mid%2==0){ // if mid is even
            if(arr[mid-1]==arr[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{ //if mid is odd
            if(arr[mid-1]==arr[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
  return -1;
}
int main(){
    int n;
    cout<<" enter the size of vector = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter sorted array where every element appears twice except one = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findsingleelement(arr);
    return 0;

}
