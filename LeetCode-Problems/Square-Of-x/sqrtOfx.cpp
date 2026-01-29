#include<iostream>
using namespace std;

int sqrt(int n){
    // Handle all edge cases
    if(n==0 ) return 0;
    if(n==1 ) return 1;
    if(n<0) return -1;

    int st=0 , end = n/2 , ans = -1;
    
    while(st <= end){
        long long mid = st + (end - st)/ 2 ; 
        long long square = mid*mid; 
        if( square == n) return mid;
        if(square < n){
             ans = mid;
             st = mid +1;
           
        }else{
            end = mid -1;
        }
    } 
    return ans;
}
int main(){
    int x;
    cout<<" Enter integer value = ";
    cin>>x;
    cout<<sqrt(x);
    return 0;
}
