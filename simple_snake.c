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

    // TODO: Complete the program
    int ar, ac; // ar = apple row, ac = apple column
    int sr, sc; // sr = snake row, sc = snake column
    char d; // d = direction
    int g; // g = game over flag
    
    printf("Please enter apple location: ");
    scanf("%d %d", &ar, &ac);
    
    printf("Please enter snake location: ");
    scanf("%d %d", &sr, &sc);
    
    map[ar][ac] = APPLE;
    map[sr][sc] = SNAKE;
    
    print_map(map);
    
    g = 0;
    while (g == 0) {
        scanf(" %c", &d);
        
        // Mark current position as visited
        map[sr][sc] = VISITED;
        
        // Move snake based on direction
        if (d == 'u') {
            sr = sr - 1;
        } else if (d == 'd') {
            sr = sr + 1;
        } else if (d == 'l') {
            sc = sc - 1;
        } else if (d == 'r') {
            sc = sc + 1;
        }
        
        // Check if snake reached apple
        if (sr == ar && sc == ac) {
            g = 1;
        } else {
            map[sr][sc] = SNAKE;
        }
        
        if (g == 0) {
            print_map(map);
        }
    }
    
    printf("Chomp!\n");

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
