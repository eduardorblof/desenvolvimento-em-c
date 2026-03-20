int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0, max = 0;

    for (int i = 0; i < numsSize; i++) {
        count = nums[i] ? count + 1 : 0;
        max = (count > max) ? count : max;
    }
    return max;
}