// Memory Limit Exceeded

#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *ans = NULL;
    int count = 0;
    int *aux = calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        aux[nums[i] - 1] = 1;
    }

    for(int i = 0; i < numsSize; i++){
        if(aux[i] == 0){
            count++;
            int *temp = realloc(ans, count * sizeof(int));
            if(!temp){
                free(ans);
                free(aux);
                return NULL;
            }
            ans = temp;
            ans[count - 1] = i + 1;
        }
    }

    free(aux);
    *returnSize = count;
    return ans;
}