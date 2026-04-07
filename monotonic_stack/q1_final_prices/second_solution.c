/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *answer=malloc(pricesSize*sizeof(int));
    for(int i=0;i<pricesSize;i++)
    {
        answer[i]=prices[i];
        for(int j=i+1;j<pricesSize;j++)
        {
            if(prices[i]>=prices[j])
            {
                answer[i]=prices[i]-prices[j];
                break;
            }
        }
    }
    *returnSize=pricesSize;
    return answer;

    
}