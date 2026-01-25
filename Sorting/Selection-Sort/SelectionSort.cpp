#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void selectionSort(vector<int>&arr , int n){
    for(int i = 0; i < n - 1 ; i++){
        int smallestIndex = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[smallestIndex ]){ 
                smallestIndex = j;
            }
        }
        if(smallestIndex != i){
        swap(arr[i],arr[smallestIndex]);
        }
    }
}
 void print(vector<int>&arr, int n){
    for(int i = 0; i < n; i++){
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
    selectionSort(arr,n);
    print(arr,n);

}
