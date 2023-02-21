#include <stdio.h>

void populateArrays(int programmers[6][6], int departments[6][6]){
    FILE *input;
    input = fopen("matching-data.txt", "r");
    for (int i = 0; i < 10; i++){
        if (i < 5){
            fscanf(input, "%d %d %d %d %d", &departments[0][i], &departments[1][i], &departments[2][i], &departments[3][i], &departments[4][i]);
            printf("%d %d %d %d %d \n", departments[0][i], departments[1][i], departments[2][i], departments[3][i], departments[4][i]);
            continue;
        }
        fscanf(input, "%d %d %d %d %d", &programmers[0][i], &programmers[1][i], &programmers[2][i], &programmers[3][i], &programmers[4][i]);
    }
    fclose(input);
}

void printArrays(int programmers[6][6], int departments[6][6]){
    printf("Departments: \n");
    for (int i = 0; i < 5; i++){
        printf("%d %d %d %d %d \n", departments[0][i], departments[1][i], departments[2][i], departments[3][i], departments[4][i]);
    }
}

int main(){
    int programmers[6][6];
    int departments[6][6];
    populateArrays(programmers, departments);
    printArrays(programmers, departments);
    return 0;
}