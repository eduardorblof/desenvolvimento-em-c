#include <stdlib.h>

int pack(int a, int b) {
    return (a << 16) | (b & 0xFFFF);
}

int unpack_a(int packed) {
    return packed >> 16;
}

int unpack_b(int packed) {
    return packed & 0xFFFF;
}

int compare(const void* a, const void* b) {
    int x = unpack_a(*(int*)a);
    int y = unpack_a(*(int*)b);

    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *ans;
    ans = (int*) malloc (numsSize * sizeof(int));
    *returnSize = numsSize;

    for(int i = 0; i<numsSize; i++){
        nums[i] = pack(nums[i], i);
    }

    qsort(nums, numsSize, sizeof(int), compare);
    int j;
    for(int i = 0; i < numsSize; i++){
        j = unpack_b(nums[i]);
        ans[j] = (i != 0)&&((unpack_a(nums[i]) == unpack_a(nums[i-1]))) ? ans[unpack_b(nums[i-1])] : i; 
    }

    
    return ans;
}