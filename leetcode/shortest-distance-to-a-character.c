#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shortestToChar(char *S, char C, int *returnSize)
{
    *returnSize = strlen(S);
    printf("strlen: %d\n", *returnSize);
    int *res = malloc(sizeof(int) * *returnSize);
    int distance, i, before, after;
    for (i = 0; S[i] != '\0'; i++)
    {
        distance = 0;
        while (1)
        {
            before = i - distance;
            after = i + distance;
            if(before < 0 && *returnSize <= after){
                distance = -1;
                break;
            }
            if(before >= 0 && S[before] == C){
                break;
            }
            if(after < *returnSize && S[after] == C){
                break;
            }
            distance++;
        }
        res[i] = distance;
    }
    return res;
}

int main()
{
    char S[] = "this is a test string";
    char C = 'b';
    int *res;
    int returnSize[1];
    res = shortestToChar(S, C, returnSize);
    printf("S: %s, length: %d C: %c\n", S, *returnSize, C);
    printf("distance:");
    for (int i = 0; i < *returnSize; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
