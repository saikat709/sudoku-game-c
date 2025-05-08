#include <iostream>
#include <vector>
#include <stack>

#define SIZE 9
#define REMOVE_CELLS 40

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif
#define vvi vector<vector<int>>

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define DEFAULT "\033[0m"
#define BLACK   "\033[0;30m"
#define GREEN   "\033[0;32m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

using namespace std;

struct userMove {
    int row;
    int col;
    int value;
};
typedef userMove UserMove;

void setColor(string colorCode) {
    cout << colorCode;
}

vvi solvedGrid( SIZE, vector<int>(SIZE, 0));
vvi unsolvedGrid(SIZE, vector<int>(SIZE, 0));
vvi userSolution(SIZE, vector<int>(SIZE, 0));
stack<UserMove> moves;


bool getFilledSudoku(vvi& grid, int row, int col);
void removeCells(vvi& solved, vvi& unsolved, int count);


void clearScreen(){
    system(CLEAR);
}

UserMove getUserInput(){
    UserMove userInput;

    setColor(CYAN);
    cout << "Make your move.\n";
    setColor(DEFAULT);
    cout << "Row no. (Top to bottom ): ";
    cin >> userInput.row;

    cout << "Col no. (Left to right) : ";
    cin >> userInput.col;

    if ( unsolvedGrid[userInput.row][userInput.col] != 0 ){
        cout << YELLOW << "THE GRID ALREADY HAS A VALUE. Want to change? " << DEFAULT;
    }

    cout << "Value                   : ";
    cin >> userInput.value;

    return userInput;
}


void printSudokuGrid(vvi grid){
    
    setColor(GREEN);
    cout << "###   🧩  SODUKO \n";
    cout << "   ";
    for( int i = 0; i < 12; i++ ) cout << "--";
    cout << "\n\n    ";
    setColor(DEFAULT);

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
    int choice;
    clearScreen();
    cout << GREEN << "1. Start Game\n";
    cout << RED << "2. Exit \n";
    cout << DEFAULT << "\nYOUR CHOICE: ";
    cin >> choice;
    while( choice > 2 || choice < 1  ){
        setColor(RED);
        cout << "Please enter a valid choice: ";
        setColor(DEFAULT);
        cin >> choice;
    }
    clearScreen();
}


int main(){
    game();
    printSudokuGrid(solvedGrid);
    // getUserInput();
    // clearScreen();
    getFilledSudoku(solvedGrid, 0, 0);
    printSudokuGrid(solvedGrid);
    removeCells(solvedGrid, unsolvedGrid, REMOVE_CELLS);
    printSudokuGrid(unsolvedGrid);
    getUserInput();

    return 0;
}