int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;

    for(int i = 0; i < n; i++){
        nums[i] |= (nums[n + i] << 10);
    }

    int index = numsSize - 1;

    for(int i = n - 1; i >= 0; i--){
        int y = nums[i] >> 10;
        int x = nums[i] & 1023;

        nums[index--] = y;
        nums[index--] = x;
    }

    return nums;
}