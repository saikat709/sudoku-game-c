#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#define SIZE 9
using namespace std;
typedef vector<vector<int>> vvi;
#define vvb vector<vector<bool>>
typedef vector<int> vi;

bool isSafe(vvi mat, int row, int col, int num){
    for (int i = 0; i < 9; i++){
       if ( i != col && mat[row][i] == num ){
            return false;
        }
        if ( i != row && mat[i][col] == num ){
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++ ){
            if ( i == row && col == j ) continue;
            if ( mat[i + startRow][j + startCol] == num ){
                return false;
            }
        }
    }
    return true;
}


void randomShuffle(vi& nums){
    static random_device rd;
    static mt19937 g(rd());
    shuffle(nums.begin(), nums.end(), g);
}



bool isSudokuComplete(vvi& grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ( grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}


void removeCells(vvi& solved, vvi& unSolved, vvb& isCellPregiven, int count) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, SIZE - 1);

    for( int i = 0; i < SIZE; i++ ){
        for( int j = 0; j < SIZE; j++ ){
            unSolved[i][j] = solved[i][j];
        }
    }

    while (count > 0) {
        int row = dist(gen);
        int col = dist(gen);
        if (unSolved[row][col] != 0) {
            unSolved[row][col] = 0;
            isCellPregiven[row][col] = false;
            count--;
        }
    }
}


bool getFilledSudoku(vvi& grid, int row, int col) {
    if (row == SIZE - 1 && col == SIZE)
        return true;
    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return getFilledSudoku(grid, row, col + 1);

    vi nums(SIZE);
    iota(nums.begin(), nums.end(), 1);
    randomShuffle(nums);

    for (int num : nums) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (getFilledSudoku(grid, row, col + 1))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}


bool helper(vvi& mat, int row, int col){
    if ( row == 9 ){
        return true;
    }

    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col + 1) % 9;

    if ( mat[row][col] != 0 ){
        return helper(mat, nextRow, nextCol);
    }

    for( int i = 1; i <= 9; i++ ){
        if ( isSafe(mat, row, col, i) ) {
            mat[row][col] = i;
            if ( helper(mat, nextRow, nextCol) ){
                return true;
            }
        }
        mat[row][col] = 0;
    }
    return false;
}


bool solveSudoku(vvi& mat){
    return helper(mat, 0, 0);
}