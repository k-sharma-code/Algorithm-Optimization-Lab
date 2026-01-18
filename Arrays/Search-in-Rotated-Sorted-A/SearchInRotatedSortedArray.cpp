#include<iostream>
#include<vector>

using namespace std;
int search(vector<int>& arr,int target){
    int n=arr.size();
     int st=0,end=n-1;
     while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){
            return mid;
        }

        if(arr[st]<arr[mid]){ // left side
            if(arr[st]<target && target<arr[mid]){
                end = mid - 1;
             } else{
                st = mid + 1;
            }
        }
        else{ // right side
            if(arr[mid]<target && target< arr[mid]){
                st = mid + 1;
            }else{
                end = mid -1;
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
    cout<<"enter sorted array = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int tar;
    cout<<"enter target = ";
    cin>>tar;
    cout<<search(arr,tar);

    return 0;
    
}
