#include<iostream>
#include<vector>
using namespace std;
int searchPeakelement(vector<int>& arr){
    int n=arr.size();
    int st=1, end= n-2;
    while(st<end){
        int mid = st + (end - st)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]> arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1]<arr[mid]){ // right 
            st=mid+1;
        }else{ // left
            end=mid-1;
        }
    }
    return -1;
}
int main(){
   
    int n;
    cout<<" enter the size of vector = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter mauntain  array (inc then decr)  = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<searchPeakelement(arr);
    return 0;



}
