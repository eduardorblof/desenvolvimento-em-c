int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0, 0};
    register int i = 0;

    for(int i =0; i< studentsSize; i++){
        if (students[i] == 0)
            count[0]++;
        
        else
            count[1]++;
        
    }

    for (int i = 0; i < sandwichesSize; i++) {
    int top = sandwiches[i];
    if (count[top] == 0)
        return sandwichesSize - i; 
    count[top]--;
    }   

    return (count[0] + count[1]);

}