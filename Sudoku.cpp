#include <bits/stdc++.h>

using namespace std;
bool IsSafe(vector<vector<char>>mat,int row,int col,char val){
    for(int i=0;i<mat.size();i++)
     if(mat[i][col]==val)
      return false;
    for(int i=0;i<mat.size();i++)
     if(mat[row][i]==val)
      return false;
    int i=row/3,j=col/3;
    i=i*3,j=j*3;
    for(int k=i;k<i+3;k++){
        for(int l=j;l<j+3;l++)
         if(mat[k][l]==val)
          return false;
    }
    return true;
}
bool IsEmpty(vector<vector<char>>mat,int &row,int &col){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]=='.'){
                row=i,col=j;
                return true;
            }
        }
    }
    return false;
}
bool Solve(vector<vector<char>>&mat){
    int row,col;
    if(!IsEmpty(mat,row,col))
     return true;
    for(int i=1;i<10;i++){
        if(IsSafe(mat,row,col,i+48)){
            mat[row][col]=i+48;
            if(Solve(mat))
             return true;
            mat[row][col]='.';
        }
    }
    return false;
}
int main() {
    vector<vector<char>>mat{ {'3', '.', '6', '5', '.', '8', '4', '.', '.'}, 
                             {'5', '2', '.', '.', '.', '.', '.', '.', '.'}, 
                             {'.', '8', '7', '.', '.', '.', '.', '3', '1'}, 
                             {'.', '.', '3', '.', '1', '.', '.', '8', '.'}, 
                             {'9', '.', '.', '8', '6', '3', '.', '.', '5'}, 
                             {'.', '5', '.', '.', '9', '.', '6', '.', '.'}, 
                             {'1', '3', '.', '.', '.', '.', '2', '5', '.'}, 
                             {'.', '.', '.', '.', '.', '.', '.', '7', '4'}, 
                             {'.', '.', '5', '2', '.', '.', '3', '.', '.'} };
    int n=mat.size();
    Solve(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++)
          cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
