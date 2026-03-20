#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ans = (int *) malloc(2 * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    int rep = -1;
    int sub = -1;

    for(int i = 0; i < numsSize - 1; i++){
        int step = nums[i+1] - nums[i];

        if (step == 0){
            rep = nums[i];
        } 
        else if (step > 1){
            sub = nums[i] + 1;
        }
    }

    if (nums[0] != 1) {
        sub = 1;
    }
    if (nums[numsSize - 1] != numsSize) {
        sub = numsSize;
    }

    ans[0] = rep;
    ans[1] = sub;
    return ans;
}