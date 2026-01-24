#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
bool bubblesort(vector<int>&arr , int n){
    bool alreadysorted = true;
    for(int i = 0; i < n - 1 ; i++){
        bool isSwap = false;
        for(int j = 0 ; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){ // for ascending
                swap(arr[j] , arr[j+1]);
                isSwap = true;
                alreadysorted = false;
            }
        }
        if(!isSwap){ // array is already sorted
          break;
        } 
    }
    return alreadysorted;
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
    bool isalreadysorted=bubblesort(arr ,n);
    if(isalreadysorted){
        cout<<"Array is already sorted ";
        print(arr,n);
    }else{
        cout<<"Sorted array = ";
        print(arr,n);

    }
   

}
