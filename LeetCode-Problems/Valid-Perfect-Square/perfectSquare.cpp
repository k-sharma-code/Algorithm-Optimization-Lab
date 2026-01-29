#include<iostream>
using namespace std;

bool perfectSqrt(int n){
  // Handle negative numbers and small edge cases
    if(n==0 || n==1 ) return true;
    if(n<0) return false;

    int st=0 , end = n/2;
    
    while(st <= end){
        long long mid = st + (end - st)/ 2 ; 
        long long square = mid*mid; // prevent overflow
        if( square == n)  return true;
        else if(square < n){
            st = mid +1;
        }else{
            end = mid-1;
        }
    } 
    return false;
}
int main(){
    int x;
    cout<<" Enter integer value = ";
    cin>>x;
    cout<< perfectS
      qrt(x);
    return 0;
}
