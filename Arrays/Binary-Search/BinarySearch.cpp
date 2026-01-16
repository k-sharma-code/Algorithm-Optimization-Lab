#include<iostream>
#include<vector>

using namespace std;

int recBnarySarch(vector<int>arr,int tar,int st,int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if(tar>arr[mid]){
            return recBnarySarch(arr, tar, mid+1, end);
        }else if(tar<arr[mid]){
            return recBnarySarch(arr, tar, st,mid-1);
        }else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<" Enter the size of vector = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter sorted array = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int tar;
    cout<<"Enter target = ";
    cin>>tar;
    int st=0,end=n-1;
    cout << recBnarySarch(arr,tar,st,end);

    return 0;
}
