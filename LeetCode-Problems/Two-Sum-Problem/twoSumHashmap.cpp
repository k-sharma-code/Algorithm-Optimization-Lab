#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr , int tar){
    unordered_map<int ,int> m;
    vector<int> ans;
    
    for(int i = 0 ; i < arr.size(); i++){
        int first = arr[i];
        int second = tar - first;

        if(m.find(second) != m.end()){
            ans.push_back(i); // 1st value index 
            ans.push_back(m[second]); // complemet's index
            return ans; 
        }
        m[first] = i;
    }

    return ans; // if no pair found
}

int main(){
    int n ;
    cout << "Enter size of array  = ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements = ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    int target;
    cout << "Enter target = ";
    cin >> target;

    vector<int> result = twoSum(arr,target);
    if(!result.empty()){
        cout<<" Indices = "<<result[0]<<" and "<<result[1]<<endl;
    }else{
        cout<<" No pair exist = "<<endl;
    }

    return 0;
}
