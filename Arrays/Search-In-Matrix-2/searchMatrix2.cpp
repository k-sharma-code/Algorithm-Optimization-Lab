#include<iostream>
#include<vector>
#include<utility>

using namespace std;
pair<int,int> searchMAtrix(vector<vector<int>> & mat , int tar){
    
    if(mat.empty() || mat[0].empty()) return {-1 ,-1};

    int m = mat.size() , n = mat[0].size();
    // starting from the top- right corner
    int row = 0 , cols = n-1;

    while(row < m && cols >= 0){

        if(tar == mat[row][cols]){
            return {row, cols};

        }else if(tar < mat[row][cols]){
            //target is smaller: move left
            cols--;

        }else{
            //target is larger : move down
            row++;
        }
    }

    return {-1,-1};
}

int main(){
    int m ,n;
    cout<<"Enter rows and columns = ";
    cin>>m>>n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout<<"Enter elements matrix "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    int target;
    cout<<"Enter target: ";
    cin>>target;
    
    pair<int,int> ans = searchMAtrix(matrix , target);

    if(ans.first == -1){
        cout<<"Target does not exist : ";
    }else{
        cout<<" found elements at row = "<<ans.first<< " cols = "<<ans.second;
    }
    
    return 0;
}
