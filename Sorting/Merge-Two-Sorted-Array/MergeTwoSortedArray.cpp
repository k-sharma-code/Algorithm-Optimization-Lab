#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>&arr1, int m, vector<int>&arr2 , int n){
    int idx = m + n - 1 , j = n-1, i=m-1;
    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[idx] = arr1[i];
            i-- ;
            idx--;
        }else{
            arr1[idx] = arr2[j];
            j--;
            idx--;
        }
    }
    while(j >= 0){
        arr1[idx] = arr2[j];
            j--;
            idx--;
    }
}
 void print(vector<int>&arr, int n){
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int m, n;
    cout<<"Enter size of 1st vector = ";
    cin>>m;
    cout<<"Enter size of 2nd vector = ";
    cin>>n;
    vector<int>arr1(m+n);
    vector<int>arr2(n);
    cout<<"Enter 1st array  elements = ";
    for(int i = 0; i < n ; i++){
        cin>>arr1[i];
    }
     cout<<"Enter 2nd array elements = ";
    for(int i = 0; i < n ; i++){
        cin>>arr2[i];
    }

    merge(arr1,m , arr2,n);
    print(arr1,m+n);

}
