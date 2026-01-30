#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
int maxProfit(vector<int>&prices , int n){
    if(n==0) return 0;
    int maxProfit = 0, bestBuy = prices[0];

    for(int i = 1; i<n; i++){
        if(prices[i] > bestBuy){
            maxProfit = max(maxProfit,prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy,prices[i]);
    }
   
    return maxProfit;
}
int main(){
    int n;
    cout<<"Enter size of vector = ";
    cin>>n;
    vector<int>prices(n);
    cout<<"Enter elements = ";
    for(int i = 0; i < n ; i++){
        cin>>prices[i];
    }
   cout<<maxProfit(prices,n);

}
