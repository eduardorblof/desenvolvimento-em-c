#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* count = calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        count[nums[i] - 1]++;
    }

    int* ans = malloc(numsSize * sizeof(int));
    int j = 0;

    for(int i = 0; i < numsSize; i++){
        if(count[i] == 0){
            ans[j++] = i + 1;
        }
    }

    free(count);
    *returnSize = j;
    return ans;
}