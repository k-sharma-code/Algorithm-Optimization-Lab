#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;

void nextPerutation(vector<int>& arr , int n){
    int pivot = -1 ;
    for(int i = n - 2; i >= 0; i-- ){ // for find the pivot
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){ 
        reverse(arr.begin(), arr.end());
        return ;
    }

    // find next larger element
    for(int i = n-1; i >= pivot ; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i] , arr[pivot]);
            break;
        }
    }
    
    // reverse (pivot+1 to n-1)
    int i = pivot+1 , j = n-1;
    while(i <= j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    
}
void print(vector<int>&arr, int n ){
    for(int i = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size od vector = ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array = ";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }

    nextPerutation(arr,n);
    cout<<"Next permutation = ";
    print(arr,n);

    return 0;

}
