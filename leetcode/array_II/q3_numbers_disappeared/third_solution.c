#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), comp);

    int *ans = malloc(numsSize * sizeof(int));
    int j = 0;
    int expected = 1;

    for(int i = 0; i < numsSize; i++){
        while(expected < nums[i]){
            ans[j++] = expected;
            expected++;
        }
        if(expected == nums[i]){
            expected++;
        }
    }

    while(expected <= numsSize){
        ans[j++] = expected++;
    }

    *returnSize = j;
    return ans;
}