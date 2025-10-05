#include <stdio.h>
#include <assert.h>

#define BOARD_LENGTH 8
#define PIECE_RED 'R'
#define PIECE_BLACK 'B'
#define PIECE_EMPTY ' '
#define TYPE_KING 1
#define TYPE_NORMAL 0

struct board_square {
    int type;
    char piece_color;
};

// Prints out a checkerboard using the provided 2D array as reference.
void print_checkerboard(struct board_square board[BOARD_LENGTH][BOARD_LENGTH]);

int main(void) {
    // Declare the checkerboard
    struct board_square board[BOARD_LENGTH][BOARD_LENGTH];

    // Initialize all squares as empty, not king
    int row = 0;
    while (row < BOARD_LENGTH) {
        int col = 0;
        while (col < BOARD_LENGTH) {
            board[row][col].piece_color = PIECE_EMPTY;
            board[row][col].type = TYPE_NORMAL;
            col = col + 1;
        }
        row = row + 1;
    }

    printf("Please enter pieces:\n");

    // Read instructions until EOF (Ctrl+D)
    int r, c, t;
    char color;
    while (scanf("%d %d %c %d", &r, &c, &color, &t) == 4) {
        board[r][c].piece_color = color;
        board[r][c].type = t;
    }

    // Print the checkerboard
    print_checkerboard(board);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT EDIT THE CODE BELOW THIS LINE! ////////////////////
///////////////////////////////////////////////////////////////////////////////

void print_checkerboard(struct board_square board[BOARD_LENGTH][BOARD_LENGTH]) {
    int row_index = 0;
    while (row_index < BOARD_LENGTH) {
        printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");
        printf("|");
        
        int column_index = 0;
        while (column_index < BOARD_LENGTH) {
            assert(
                board[row_index][column_index].piece_color == PIECE_RED ||
                board[row_index][column_index].piece_color == PIECE_BLACK ||
                board[row_index][column_index].piece_color == PIECE_EMPTY
            );
   
            assert(
                board[row_index][column_index].type == TYPE_KING || 
                board[row_index][column_index].type == TYPE_NORMAL
            );
            
            if (board[row_index][column_index].type == TYPE_KING) {
                printf(" %c-K |", board[row_index][column_index].piece_color);
            } else {
                printf("  %c  |", board[row_index][column_index].piece_color);
            }
            
            column_index = column_index + 1;
        }
        
        printf("\n");
        row_index = row_index + 1;
    }
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");
    return;
}
