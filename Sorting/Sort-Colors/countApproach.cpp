#include<iostream>
#include<vector>
using namespace std;
 
void sortColors(vector<int>&arr , int n){
    int count0 = 0, count1 = 0, count2 = 0;
    // First pass : count frequency of 0s ,1s and 2s.
    for(int i = 0; i < n  ; i++){
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    int idx = 0; // Second pass: overwrite array based on counts
    for(int i = 0; i < count0  ; i++){
        arr[idx++] = 0;
    }
    for(int i = 0; i < count1  ; i++){
        arr[idx++] = 1;
    }
    for(int i = 0; i < count2  ; i++){
        arr[idx++] = 2;
    }
}
 void print(vector<int>&arr, int n){
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size of vector = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements = ";
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    sortColors(arr,n);
    print(arr,n);

}
