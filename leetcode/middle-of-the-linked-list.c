#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *current = head, *middle = head;
    while(current && current->next != NULL){
        middle = middle->next;
        current = current->next->next;
    }
    return middle;
}

struct ListNode* createListNode(int num){
    struct ListNode *head; 
    struct ListNode *listNode= malloc(sizeof(struct ListNode));
    head = listNode;
    for(int i = 1; i < num; i++){
       listNode->next = malloc(sizeof(struct ListNode));
       listNode = listNode->next;
       listNode->val = i;
    }
    return head;
}

void printListNode(struct ListNode *listNode){
    while(listNode != NULL){
        printf("%d ", listNode->val);
        listNode = listNode->next;
    }
    printf("\n");
}
int main(){
    struct ListNode *test;
    struct ListNode *middle;
    for(int i = 1; i <= 10; i++){
        printf("list node num: %d\n", i);
        test = createListNode(i);
        printf("listNode: ");
        printListNode(test);
        middle = middleNode(test);
        printf("middle: %d\n\n", middle->val);

    }
}
