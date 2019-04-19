#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int *res = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize - i - 1; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 34, 234, 23, 2123};
    int target = nums[3] + nums[10];
    int *res;
    res = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);
    printf("target %d, res  index: %d, %d, value: %d + %d = %d\n", target, res[0], res[1], nums[res[0]], nums[res[1]], nums[res[0]] + nums[res[1]]);
}
