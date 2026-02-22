#include<iostream>
#include<vector>
#include<utility>

using namespace std;

pair<int, int>searchInRow(vector<vector<int>>&mat , int tar , int row){
    int n = mat[0].size();
    int st = 0 , end = n-1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(tar == mat[row][mid] ){
            return {row , mid};
        }else if(tar > mat[row][mid]){
            st = mid +1;
        }else{
            end = mid -1;
        }
    }
    return {-1,-1};
}

pair<int,int>searchMatrix(vector<vector<int>>&mat , int tar ){  
    int m = mat.size() , n = mat[0].size();
    int stRow = 0 , endRow = m - 1;
    while(stRow <= endRow){
        int midRow = stRow + (endRow - stRow)/2;
        if(tar >= mat[midRow][0] && tar <= mat[midRow][n-1]){
            //found row now binary search on this row
            return searchInRow(mat , tar , midRow);

        }else if(tar > mat[midRow][n-1]){
            //find downword
            stRow = midRow + 1;
        }else{
            //find upword
            endRow = midRow - 1;
        }
    }
    return {-1 , -1};
}

int main(){
    int  m , n;
    cout<<"Enter number of rows = ";
    cin>>m;
    cout<<"Enter number of columns  = ";
    cin>>n;
    cout<<"Enter elements of matrix: "<<endl;
    vector<vector<int>>mat (m,vector<int>(n));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0; j < n ; j++){
            cin>>mat[i][j];
        }
    }

    int target;
    cout<<"Enter target = ";
    cin>>target ;

    pair<int , int> ans = searchMatrix(mat , target);
    if(ans.first == -1){
        cout<<"Not found ";
    }else{
        cout<<"Row = "<<ans.first <<" column = "<<ans.second<<endl;
    }
    
    return 0;
}
