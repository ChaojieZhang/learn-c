#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *res = malloc(sizeof(struct ListNode));
    struct ListNode *tmpList = res;
    int v1, v2, tmpSum;
    int carry = 0;
    while (1)
    {
        v1 = l1 == NULL ? 0 : l1->val;
        v2 = l2 == NULL ? 0 : l2->val;
        tmpSum = v1 + v2 + carry;
        if (tmpSum > 9)
        {
            tmpList->val = tmpSum - 10;
            carry = 1;
        }
        else
        {
            tmpList->val = tmpSum;
            carry = 0;
        }

        l1 = l1 == NULL ? NULL : l1->next;
        l2 = l2 == NULL ? NULL : l2->next;
        if (l1 == NULL && l2 == NULL && carry == 0)
        {
            break;
        }

        tmpList->next = malloc(sizeof(struct ListNode));
        tmpList = tmpList->next;
    }
    return res;
}

struct ListNode *createList(char numsStr[])
{
    struct ListNode *res = malloc(sizeof(struct ListNode));
    struct ListNode *tmpListNode = res;
    for (int i = 0;; i++)
    {
        if (numsStr[i] == '\0')
        {
            break;
        }
        tmpListNode->val = numsStr[i] - 48;
        tmpListNode->next = malloc(sizeof(struct ListNode));
        tmpListNode = tmpListNode->next;
    }
    return res;
}

void printListNode(struct ListNode *list)
{
    while (list != NULL)
    {
        printf("%d", list->val);
        list = list->next;
    };
    printf("\n");
}

int main()
{
    struct ListNode *l1 = createList("123123123202313101230123");
    struct ListNode *l2 = createList("112128202313901330123");
    printf("content of l1:\t");
    printListNode(l1);
    printf("content of l2:\t");
    printListNode(l2);
    struct ListNode *res = addTwoNumbers(l1, l2);
    printf("content of res:\t");
    printListNode(res);
}
