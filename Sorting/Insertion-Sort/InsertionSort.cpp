#include<iostream>
#include<vector>
using namespace std;
 
void insertionSort(vector<int>&arr , int n){
    for(int i = 1; i < n  ; i++){
        int current = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > current){ // (arr[prev] > current) for descending order
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
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
    insertionSort(arr,n);
    print(arr,n);

}
