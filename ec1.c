#include <stdio.h>

void populateArrays(int programmers[10][10], int departments[10][10]){
    FILE *input;
    input = fopen("matching-data.txt", "r");
    for (int i = 0; i < 10; i++){
        if (i < 5){
            fscanf(input, "%d %d %d %d %d", &departments[0][i], &departments[1][i], &departments[2][i], &departments[3][i], &departments[4][i]);
        } else {
            fscanf(input, "%d %d %d %d %d", &programmers[0][i - 5], &programmers[1][i - 5], &programmers[2][i - 5], &programmers[3][i - 5], &programmers[4][i - 5]);
        }
    }
    fclose(input);
}


void printArrays(int programmers[10][10], int departments[10][10]){
    printf("Departments: \n");
    for (int i = 0; i < 5; i++){
        printf("%d %d %d %d %d \n", departments[0][i], departments[1][i], departments[2][i], departments[3][i], departments[4][i]);
    }
    printf("Programmers: \n");
    for (int i = 0; i < 5; i++){
        printf("%d %d %d %d %d \n", programmers[0][i], programmers[1][i], programmers[2][i], programmers[3][i], programmers[4][i]);
    }
}

int main(){
    int programmers[10][10];
    int departments[10][10];
    populateArrays(programmers, departments);
    printArrays(programmers, departments);
    return 0;
}