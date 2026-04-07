#include <string.h>
#include <stdlib.h>
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **ans = (char**) malloc (sizeof(char*) * (2*n));
    int opcount = 0;
    int tgidx = 0;

   
    for(int stream = 1; stream <= n && tgidx < targetSize; stream++){
    
        ans[opcount] = (char*) malloc (sizeof(char)*5);
        strcpy(ans[opcount], "Push");
        opcount++;
        if(target[tgidx] != stream){
            ans[opcount] = (char*) malloc (sizeof(char)*5);
            strcpy(ans[opcount], "Pop");
            opcount++;
        } else {
            tgidx++;
        }
    }
    
    *returnSize = opcount; 
    return ans;



}