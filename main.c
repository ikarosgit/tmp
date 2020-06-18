#include "state.h"
#include "solver.h"

int main() {
 
    char start_path[] = "testcase";
    char goal_path[] = "goal";
    int start[PSIZE][PSIZE];
    int goal[PSIZE][PSIZE];

    loadPuzzle(start, start_path);
    loadPuzzle(goal, goal_path);
    printPuzzle(start);
    printf("------\n");
    printPuzzle(goal);

    bfs(start, goal);

    /* int data[] = {10, 33, 4}; */

    /* List* list = NULL; */
    /* ListNode* node = NULL; */

    /* list = createList(); */

    /* for (int i = 0; i < 3; i++) { */
    /*     node = createListNode(data[i]); */
    /*     pushListNode(node, &list); */
    /* } */

    /* printList(&list); */
    
    /* printf("End of main\n"); */
    return 0;
}
