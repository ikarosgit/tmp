#ifndef __STATE_H__
#define __STATE_H__

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define PSIZE 3
#define FOR2D(i, j) for(i=0;i<PSIZE;i++)for(j=0;j<PSIZE;j++)

typedef struct Space {
    int x;
    int y;
};

typedef enum Move {
    UP, LEFT, DOWN, RIGHT
} Move;

typedef struct State State;
struct State {
    int depth;
    int puzzle[PSIZE][PSIZE];
    State* parent;
};

void copyPuzzle(int dst[PSIZE][PSIZE], int src[PSIZE][PSIZE]) {
    int i, j;
    FOR2D(i, j) {
        dst[i][j] = src[i][j];
    }
}

int movePuzzle(int puzzle[PSIZE][PSIZE], Space space, Move move) {
    int i, j;
    if (move == UP) {
        i = space.x;
        j = space.y - 1;
    } else if (move == LEFT) {
        i = space.x - 1;
        j = space.y;
    
    } else if (move == DOWN) {
        i = space.x;
        j = space.y + 1;
    } else if (move == RIGHT) {
        i = space.x + 1;
        j = space.y;
    }
    if (i < 0 || i >= PSIZE || j < 0 || j >= PSIZE) return 0;
    swap(&puzzle[space.x][space.y], &puzzle[i][j])
}

State* createState(int depth, int puzzle[PSIZE][PSIZE], State* parent) {
    State* state = NULL;
    state = (State*)malloc(sizeof(State));
    if (state != NULL) {
        copyPuzzle(state->puzzle, puzzle);
        state->depth = depth;
        state->parent = parent;
    }
    return state;
}

int comparePuzzle(int curr[PSIZE][PSIZE], int goal[PSIZE][PSIZE]) {
    int i, j;
    int cnt = 0;
    FOR2D(i, j) {
        if (curr[i][j] != goal[i][j]) cnt++
    }
    return cnt;
}

int loadPuzzle(int puzzle[PSIZE][PSIZE], char *path) {
    int i, j;
    FILE* fp = fopen(path, "r");
    if (fp == NULL) return 0;

    for (int i = 0; i < PSIZE; i++) {
        fscanf(fp ,"%d%d%d", &puzzle[i][0], &puzzle[i][1], &puzzle[i][2]);
    }
    return 1;
}

void printPuzzle(int puzzle[PSIZE][PSIZE]) {
    int i, j;
    FOR2D(i, j) {
        printf("%d", puzzle[i][j]);
        if (j == PSIZE-1) printf("\n");
        else printf(" ");
    }
}

#endif
