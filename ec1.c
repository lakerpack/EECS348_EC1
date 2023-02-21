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

void match(int programmers[10][10], int departments[10][10], int selection[5][2]){
    for (int i = 0; i < 5; i++){
        for (int first = 0; first < 5; first++){
            printf("Department %d picks Programmer %d ", first + 1, departments[first][i]);
        }
        printf("\n");
    }

}

int main(){
    int programmers[10][10];
    int departments[10][10];
    int selection[5][2] = {{1,0},{2,0}, {3,0}, {4,0}, {5,0}};
    populateArrays(programmers, departments);
    match(programmers, departments, selection);
    return 0;
}