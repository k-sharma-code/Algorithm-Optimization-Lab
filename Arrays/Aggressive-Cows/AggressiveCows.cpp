#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int n , int C,int minAllowedDist){ //O(n)
    int cows = 1 , lastStallpos =arr[0];

    for(int i=1;i<n;i++){ 
        if((arr[i]-lastStallpos)>= minAllowedDist){
            cows++;
            lastStallpos = arr[i];
        }

        if(cows == C){
            return true;
        }
    }
   return  false;
}
int getDistance(vector<int>&arr,int C){ //O(nlogN )
    int n = arr.size();
    if(C > n) return -1;
    sort(arr.begin(), arr.end());

    int st=1 , end = arr[n-1]-arr[0], ans=-1;

    while(st<=end){ // O(log(Range) * n)
        int mid=st+(end-st)/2;

        if(isPossible(arr , n , C , mid)){ //right
            ans=mid;
            st=mid+1;

        }else{ //left
            end= mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<" enter the size of stall = ";
    cin>>n;
    vector<int>arr(n);
    cout<<"position of each stall = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int C;
    cout<<"Enter number of Cows= ";
    cin>>C;
    cout<<getDistance(arr,C);
    
    return 0;
}
