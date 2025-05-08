#include <iostream>
#include <vector>
#define SIZE 9
#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif
#define vvi vector<vector<int>>
using namespace std;

vvi grid(SIZE, vector<int>(SIZE, 0));


struct userMove {
    int row;
    int col;
    int value;
};
typedef userMove UserMove;


void clearScreen(){
    system(CLEAR);
}

UserMove getUserInput(){
    UserMove userInput;

    cout << "Make your move.\n";

    cout << "Row no. (Top to bottom ): ";
    cin >> userInput.row;

    cout << "Col no. (Left to right) : ";
    cin >> userInput.col;

    cout << "Value                   : ";
    cin >> userInput.value;

    return userInput;
}


void printSudokuGrid(){
    cout << "## SODUKO: \n\n";
    cout << "    ";
    for( int i = 0; i < SIZE; i++ ){
        cout << i + 1 << " ";
        if ( (i+1) % 3 == 0 ){
            cout << "  ";
        }
    }
    cout << "\n   ";
    for( int i = 0; i < SIZE; i++ ){
        cout << "--";
        if ( (i+1)%3 == 0 ){
            cout << "- ";
        }
    }
    cout << "\n";
    for( int i = 0; i < SIZE; i++ ){
        cout << i + 1 << " | ";
        for( int j = 0; j < SIZE; j++ ){
            if( grid[i][j] != 0 ) cout << grid[i][j] << ' ';
            else cout << ". ";

            if ( (j+1)%3 == 0 ){
                cout << "| ";
            }
        }

        if ( (i+1)%3 == 0 ) {cout << '\n';
            cout << "   ";
            for( int i = 0; i < 9; i++ ){
                cout << "--";
                if ( (i+1)%3 == 0 ){
                    cout << "- ";
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void game(){
    cout << "1. Start Game\n";
    cout << "2. Exit\n";
    clearScreen();
}


int main(){
    game();
    printSudokuGrid();
    getUserInput();
    clearScreen();
    printSudokuGrid();
    getUserInput();

    return 0;
}