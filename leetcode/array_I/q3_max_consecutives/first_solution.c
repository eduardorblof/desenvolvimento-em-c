int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count_max = 0;
    int count_temp = 0;

   for(int i = 0; i < numsSize; i++){

    if(nums[i]==1){
        int j = i;
        
        while(j < numsSize && nums[j]){
            count_temp++;
            j++; 
        }
        if (count_temp > count_max)
        count_max = count_temp;
        count_temp = 0;
        
    } 
   }
   return count_max;
    
}