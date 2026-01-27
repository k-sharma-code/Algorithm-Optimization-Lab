#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
void SortColors(vector<int>& arr ){
    int n = arr.size();
    int low = 0 , mid = 0 , high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;

        }else if(arr[mid] == 1){
            mid++;

        }else{
            swap(arr[mid], arr[high]);
            high--;
        }

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
    SortColors(arr);
    print(arr,n);
}
