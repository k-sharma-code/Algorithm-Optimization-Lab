#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int,int> searchMatrix(vector<vector<int>>& mat, int target){
    if(mat.empty() || mat[0].empty()) return {-1 , -1};
    int m = mat.size();
    int n = mat[0].size();

    long long st = 0;
    //1LL prevents overflow int multiplication
    long long end = 1LL * m * n - 1;

    while(st <= end){
        long long mid = st + (end - st)/2;
        //converting 1D into 2D
        int row = mid / n; // quotient gives row index
        int col = mid % n; // remainder give cols index

        if(mat[row][col] == target){
            return {row, col};

        }else if(mat[row][col] < target){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return {-1, -1};
}

int main(){

    int m,n;
    cout<<"Enter rows and cols = ";
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout<<"Enter elements matrix "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;

    pair<int,int> ans = searchMatrix(mat, target);

    if(ans.first == -1){
        cout<<"Not found";
    }else{
        cout<<"Found at row "<<ans.first<<" col "<<ans.second;
    }

    return 0;
    
}
