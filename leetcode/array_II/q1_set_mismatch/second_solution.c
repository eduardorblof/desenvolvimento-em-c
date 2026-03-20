#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ans = (int*) malloc(2 * sizeof(int));

    int rep = -1;
    int sub = -1;

    for (int i = 0; i < numsSize; i++) {
        int idx = abs(nums[i]) - 1;

        if (nums[idx] < 0) {
            rep = abs(nums[i]);
        } else {
            nums[idx] = -nums[idx];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            sub = i + 1;
            break;
        }
    }

    ans[0] = rep;
    ans[1] = sub;
    return ans;
}