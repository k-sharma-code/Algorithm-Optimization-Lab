#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int n , int m,int maxAllowedtime){ //O(n)
    int painters=1 , time =0;

    for(int i=0;i<n;i++){ 
        if(arr[i]> maxAllowedtime){
            return false;
        }
        
        if(time + arr[i] <= maxAllowedtime){
            time += arr[i];
        }else{
            painters++;
            time =arr[i];
        }
    }
   return   painters <= m;
}
int minTimeToPaint(vector<int>&arr,int m){ //O(logN *n)
    int n = arr.size();
    if(m>n){
        return -1;
    } 
     
    int sum=0, maxVal=INT_MIN;
    for(int i=0;i<n;i++){ //O(n)
        sum+=arr[i];
        maxVal=max(maxVal,arr[i]);

    }

    int ans=-1;
    int st=maxVal,end=sum; // range os possible ans

    while(st<=end){ // O(log(sum) * n)
        int mid=st+(end-st)/2;

        if(isPossible(arr , n , m , mid)){ //left
            ans=mid;
            end= mid-1;
        }else{ //right
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<" enter the size of vector = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter length of each board = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter number of painters= ";
    cin>>m;
    cout<<minTimeToPaint(arr,m);
    return 0;
}
