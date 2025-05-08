#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

const int SIZE = 9;
const int EMPTY_CELLS = 45; // number of cells to remove (adjustable)

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int r = 0; r < 3; r++)
        for (int d = 0; d < 3; d++)
            if (grid[startRow + r][startCol + d] == num)
                return false;

    return true;
}

bool fillGrid(vector<vector<int>>& grid, int row, int col) {
    if (row == SIZE - 1 && col == SIZE)
        return true;
    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return fillGrid(grid, row, col + 1);

    vector<int> nums(SIZE);
    iota(nums.begin(), nums.end(), 1);
    static std::random_device rd;
    static std::mt19937 g(rd());
    shuffle(nums.begin(), nums.end(), g);

    for (int num : nums) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (fillGrid(grid, row, col + 1))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void removeCells(vector<vector<int>>& grid, int count) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_int_distribution<> dist(0, SIZE - 1);

    while (count > 0) {
        int row = dist(gen);
        int col = dist(gen);
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            count--;
        }
    }
}

void printGrid(const vector<vector<int>>& grid) {
    for (int r = 0; r < SIZE; r++) {
        for (int d = 0; d < SIZE; d++) {
            if (grid[r][d] == 0)
                cout << ". ";
            else
                cout << grid[r][d] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> grid(SIZE, vector<int>(SIZE, 0));

    fillGrid(grid, 0, 0);

    cout << "✔️ Solved Sudoku:\n";
    printGrid(grid);

    removeCells(grid, EMPTY_CELLS);

    cout << "\n🧩 Puzzle Sudoku:\n";
    printGrid(grid);

    return 0;
}
