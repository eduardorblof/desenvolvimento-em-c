int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *answer = calloc(temperaturesSize, sizeof(int)); 
    int *p = malloc(temperaturesSize * sizeof(int)); 
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[p[top]] < temperatures[i]) {
            int idx = p[top--];
            answer[idx] = i - idx;
        }
        p[++top] = i;
    }

    *returnSize = temperaturesSize;
    return answer;
}