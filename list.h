#ifndef __LIST_H__
#define __LIST_H_
#include <stdlib.h>

typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode {
    State* data;
    ListNode* next;
    ListNode* prev;
};

typedef struct List {
    unsigned int size;
    ListNode* head;
    ListNode* tail;
} List;

int isEmpty(List* list) {
    return (list->size == 0);
}

ListNode* createListNode(State* state) {
    ListNode* node = NULL;
    node = (ListNode*)malloc(sizeof(ListNode));
    if (node != NULL) {
        node->data = state;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

List* createList() {
    List* list = NULL;
    list = (List*)malloc(sizeof(List));
    if (list != NULL) {
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

int pushListNode(ListNode* node, List** list) {
    if (node == NULL) return 0;

    if ((*list)->size == 0) {
        (*list)->head = node;
        (*list)->tail = node;
        node->next = NULL;
        node->prev = NULL;
        ((*list)->size)++;
        return 1;
    }
    
    (*list)->head->prev = node;
    node->next = (*list)->head;
    node->prev = NULL;
    (*list)->head = node;
    ((*list)->size)++;

    return 1;
}

ListNode* popListNode(List** list) {
    ListNode* curr_node = (*list)->tail;
    ListNode* prev_node = (*list)->tail->prev;

    free((*list)->tail);

    if ((*list)->size == 1) {
        (*list)->head = NULL;
    } else {
        prev_node->next = NULL;
    }
    (*list)->tail = prev_node;
    ((*list)->size)--;
    return curr_node;
}

void printList(List** list) {
    ListNode* node = (*list)->tail;
    printf("front -> ");
    while (node != NULL) {
        printf("(%d) -> ", node->data->depth);
        node = node->prev;
    }
    printf("rear\n");
}

#endif
