#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isValid(vector<int> &arr, int n , int m,int maxAllowedpages){ //O(n)
    int students=1 , pages =0;

    for(int i=0;i<n;i++){
        if(arr[i]> maxAllowedpages){
            return false;
        }
        
        if(pages + arr[i] <= maxAllowedpages){
            pages += arr[i];
        }else{
            students++;
            pages=arr[i];
        }
    }
   return  students > m ? false : true;
}
int allocatebook(vector<int>&arr,int m){ //O(logN *n)
    int n = arr.size();
    if(m>n){
        return -1;
    } 
     
    int sum=0;
    for(int i=0;i<n;i++){ //O(n)
        sum+=arr[i];
    }

    int ans=-1;
    int st=*max_element(arr.begin(),arr.end()),end=sum; // range os possible ans

    while(st<=end){ // O(logN * n)
        int mid=st+(end-st)/2;

        if(isValid(arr , n , m , mid)){
            ans=mid;
            end= mid-1;
        }else{
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
    cout<<"Enter number of pages in each book = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"Enter number of student= ";
    cin>>m;
    cout<<allocatebook(arr,m);
    return 0;
}
