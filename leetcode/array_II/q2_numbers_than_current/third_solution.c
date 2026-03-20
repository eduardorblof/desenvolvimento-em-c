#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ans = (int*) malloc(numsSize * sizeof(int));

    int count[101] = {0};

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i < 101; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            ans[i] = 0;
        else
            ans[i] = count[nums[i] - 1];
    }

    return ans;
}