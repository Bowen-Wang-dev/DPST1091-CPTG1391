// A simpler version of the famous Snake game!
//
// Written by Rory Golledge (z5308772) on 3/3/23
// Modified by YOUR-NAME (zXXXXXXX) on DD-MM-YY
//

#include <stdio.h>

#define SIZE 8

enum land {
    NOT_VISITED,
    VISITED,
    SNAKE,
    APPLE
};

void initialise_map(enum land map[SIZE][SIZE]);
void print_map(enum land map[SIZE][SIZE]);

int main(void) {
    enum land map[SIZE][SIZE];
    initialise_map(map);
 
    printf("Welcome to Snake!\n");

    // apple location
    int apple_row, apple_col;
    printf("Please enter apple location: ");
    scanf("%d %d", &apple_row, &apple_col);
    map[apple_row][apple_col] = APPLE;

    // snake location
    int snake_row, snake_col;
    printf("Please enter snake location: ");
    scanf("%d %d", &snake_row, &snake_col);
    map[snake_row][snake_col] = SNAKE;

    print_map(map);

    // game loop
    char direction;
    while (snake_row != apple_row || snake_col != apple_col) {
        scanf(" %c", &direction);

        // mark current position visited
        map[snake_row][snake_col] = VISITED;

        if (direction == 'u') {
            snake_row = snake_row - 1;
        } else if (direction == 'd') {
            snake_row = snake_row + 1;
        } else if (direction == 'l') {
            snake_col = snake_col - 1;
        } else if (direction == 'r') {
            snake_col = snake_col + 1;
        }

        // if reached apple, mark snake and end
        if (snake_row == apple_row && snake_col == apple_col) {
            map[snake_row][snake_col] = SNAKE;
            print_map(map);
            printf("Chomp!\n");
            return 0;
        }

        // otherwise move snake
        map[snake_row][snake_col] = SNAKE;
        print_map(map);
    }

    return 0;
}

/**
 * Initialises the given `map` such that all tiles are `NOT_VISITED`
 * 
 * Parameters:
 *     map - The map to initialise
 * 
 * Returns:
 *     Nothing
 */
void initialise_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            map[row][col] = NOT_VISITED;
        }
    }
}

/**
 * Prints the given `map` such that all enum values are printed as nice
 * characters.
 * 
 * Parameters:
 *     map - The map to print out
 * 
 * Returns:
 *     Nothing
 */
void print_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (map[row][col] == NOT_VISITED) {
                printf(". ");
            } else if (map[row][col] == VISITED) {
                printf("- ");
            } else if (map[row][col] == SNAKE) {
                printf("S ");
            } else if (map[row][col] == APPLE) {
                printf("A ");
            }
        }
        printf("\n");
    }
}
