#include <iostream>
#include <vector>
#include <stack>
#include <ctime>


#define SIZE 9
#define REMOVE_CELLS 40

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>

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

// variables for sudoku grid
vvi solvedGrid( SIZE,  vector<int>(SIZE, 0));
vvi unsolvedGrid(SIZE, vector<int>(SIZE, 0));
vvi userSolution(SIZE, vector<int>(SIZE, 0));
vvb isCellPregiven(SIZE, vector<bool>(SIZE, true));
bool isSudokuComplete(vvi& grid);
stack<UserMove> moves;

// sudoku methods
bool getFilledSudoku(vvi& grid, int row, int col);
void removeCells(vvi& solved, vvi& unsolved, vvb& isCellPregiven, int count);
bool isSafe(vvi mat, int row, int col, int num);

void printSudokuGrid(vvi grid);

void clearScreen(){
    system(CLEAR);
}


void undoMove(){
    if ( moves.empty() ){
        cout << RED << "No moves to undo.\n" << DEFAULT;
        return;
    }
    UserMove lastMove = moves.top();
    moves.pop();
    unsolvedGrid[lastMove.row-1][lastMove.col-1] = 0;

    cout << GREEN << "Last move undone.\n" << DEFAULT;
    printSudokuGrid(unsolvedGrid);
}

UserMove getUserInput(){
    printSudokuGrid(solvedGrid);

    UserMove userInput;

    setColor(CYAN);
    cout << "Make your move. (Use -1 as Row no. to undo last move.)\n";
    setColor(DEFAULT);
    cout << PURPLE << "Use -1 to undo last move. and q to quit.\n" << DEFAULT;
    
    cout << "Row no. (Top to bottom ): ";
    cin >> userInput.row;
    while( userInput.row < 1 || userInput.row > SIZE ){
        if ( userInput.row == -1 ) return userInput;
        cout << RED << "Please enter a valid row number: " << DEFAULT;
        cin >> userInput.row;
    }

    cout << "Col no. (Left to right) : ";
    cin >> userInput.col;
    while( userInput.col < 1 || userInput.col > SIZE ){
        cout << RED << "Please enter a valid row number: " << DEFAULT;
        cin >> userInput.row;
    }


    if ( isCellPregiven[userInput.row-1][userInput.col-1] ){
        cout << RED << "You can not edit this cell.\n" << DEFAULT;
        return getUserInput();
    }

    if ( unsolvedGrid[userInput.row-1][userInput.col-1] != 0 ){
        cout << YELLOW << "THE GRID ALREADY HAS A VALUE. Want to change?( Y/N )" << DEFAULT;
        bool change;
        cin >> change;
        if ( change == 'Y' || change == 'y' ){
            cout << "Enter new value: ";
            cin >> userInput.value;
            while( userInput.value < 1 || userInput.value > SIZE ){
                cout << RED << "Please enter a valid row number: " << DEFAULT;
                cin >> userInput.row;
            }
        }
        else {
            cout << RED << "Please enter a valid cell.\n" << DEFAULT;
            return getUserInput();
        }
    }

    cout << "Value                   : ";
    cin >> userInput.value;
    while( userInput.value < 1 || userInput.value > SIZE ){
        cout << RED << "Please enter a valid row number: " << DEFAULT;
        cin >> userInput.row;
    }

    if ( !isSafe(unsolvedGrid, userInput.row -1 , userInput.col - 1, userInput.value) ){
        cout << RED << "THIS VALUE IS NOT SUITABLE FOR THE POSITION. \n" << DEFAULT;
        return getUserInput();

    }

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
            if( grid[i][j] != 0 ){
                cout << ( isCellPregiven[i][j] ? DEFAULT : GREEN  ) << grid[i][j] << ' ' << DEFAULT;
            } else{
                cout << ". ";
            }

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


void startGame(){ 

    time_t startTime = time(0);

    while( true ){
        clearScreen();
        printSudokuGrid(unsolvedGrid);
        time_t currentTime = time(0);
        cout << "Time elapsed: " << difftime(currentTime, startTime) << " seconds\n";
        UserMove userInput = getUserInput();

        if ( userInput.row == -1 ){
            undoMove();
            continue;
        } else {
            moves.push(userInput);
        }

        if ( userInput.row == 'q' || userInput.col == 'q' ){
            cout << "Exiting game.\n";
            break;
        }

        if ( isSafe(unsolvedGrid, userInput.row-1, userInput.col-1, userInput.value) ){
            unsolvedGrid[userInput.row-1][userInput.col-1] = userInput.value;
            moves.push(userInput);
            printSudokuGrid(unsolvedGrid);
        } else {
            cout << RED << "Invalid move. Try again.\n" << DEFAULT;
        }

        if ( isSudokuComplete(unsolvedGrid) ){
            cout << GREEN << "Congratulations! You have completed the Sudoku.\n" << DEFAULT
            cout << CYAN << "Do you want to play again? (Y/N): " << DEFAULT;
            char choice;
            cin >> choice;
            if ( choice == 'Y' || choice == 'y' ){
                cout << GREEN << "Starting new game...\n" << DEFAULT;
                beforeGame();
                break;
            } else {
                cout << "Thanks for playing.\n";
                break;
            }
            break;
        }
    }
    cout << "Game over.\n";
    cout << "Exiting game.\n";
    clearScreen();
}


void initGame(){
    clearScreen();
    cout << GREEN << "Initiating game.......\n" << DEFAULT;
    getFilledSudoku(solvedGrid, 0, 0);
    printSudokuGrid(solvedGrid);
    removeCells(solvedGrid, unsolvedGrid, isCellPregiven, REMOVE_CELLS);
    clearScreen();
}

void beforeGame(){
    initGame();
    int choice;
    clearScreen();
    cout << "🧩 SODUKO \n\n";
    cout << GREEN << "1. Start Game\n";
    cout << RED   << "2. Exit Game\n";
    cout << DEFAULT << "\nYOUR CHOICE: ";
    cin >> choice;
    while( choice > 2 || choice < 1  ){
        setColor(RED);
        cout << "Please enter a valid choice: ";
        setColor(DEFAULT);
        cin >> choice;
    }
    if ( choice == 2 ){
        cout << "Exiting. Thanks for playing.\n";
        return;
    }

    if ( choice == 1 ){
        cout << "Starting game...\n";
        clearScreen();
        startGame();
    }
    clearScreen();
}



int main(){
    beforeGame();

    return 0;
}