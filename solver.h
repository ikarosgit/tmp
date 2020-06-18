#ifndef __SOLVER_H__
#define __SOLVER_H__
#include "list.h"
#include "state.h"

void bfs(int start[PSIZE][PSIZE], int goal[PSIZE][PSIZE]) {
    int depth = 0;
    int moved[PSIZE][PSIZE];
    int curr[PSIZE][PSIZE];
    State* curr_state = NULL;
    State* next_state = NULL;
    ListNode* curr_node = NULL;
    ListNode* next_node = NULL;
    List* queue = NULL;

    curr_state = createState(depth, start, NULL);
    curr_node = createListNode(curr_state);
    queue = createList();
    pushListNode(curr_node, &queue);

    while (!isEmpty(queue)) {
        curr_state = popListNode(&queue)->data;
        curr = curr_state->puzzle;
        if (comparePuzzle(curr, goal) == 0) break;
        space = findSpace(curr);
        for (move = UP; move <= RIGHT; move++) {
            moved = movePuzzle(curr, space, UP)
            next_state = createState(depth+1, moved, curr_state);
        }
        
    }
}
#endif
