#include <iostream>
#include <vector>
using namespace std;


bool isValid(vector<vector<int>>& mat, int row, int col, int num){
    for (int i = 0; i < 9; i++){
        if (mat[row][i] == num || mat[i][col] == num ){
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for( int row = 0; row < 3; row++ ){
        for( int col = 0; col < 3; col++ ){
            if ( mat[row + startRow][col + startCol] == num ){
                return false;
            }
        }
    }
    return true;
}


bool helper(vector<vector<int>>& mat, int row, int col){
    if ( row == 9 ){
        return true;
    }

    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col + 1) % 9;

    if ( mat[row][col] != 0 ){
        return helper(mat, nextRow, nextCol);
    }

    for( int i = 1; i <= 9; i++ ){
        if ( isValid(mat, row, col, i) ) {
            mat[row][col] = i;
            if ( helper(mat, nextRow, nextCol) ){
                return true;
            }
        }
        mat[row][col] = 0;
    }
    return false;
}


bool sudokuSolver(vector<vector<int>>& mat){
    return helper(mat, 0, 0);
}


int main() {
    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
      	{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
      	{0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
      	{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
      	{0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
      	{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
      	{0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

	sudokuSolver(mat);
    
  	for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}


/*
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 
*/