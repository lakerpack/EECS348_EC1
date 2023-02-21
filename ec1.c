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
    printf("\n");
    printf("Programmers: \n");
    for (int i = 0; i < 5; i++){
        printf("%d %d %d %d %d \n", programmers[0][i], programmers[1][i], programmers[2][i], programmers[3][i], programmers[4][i]);
    }
}

void match(int programmers[10][10], int departments[10][10], int selection[5][2]){
    for (int i = 0; i < 5; i++){
        for (int dep1 = 0; dep1 < 5; dep1++){
            printf("Department %d Row %d, ", dep1 + 1, i + 1);
            int counter = 0;
            int conflicts[5];
            for (int dep2 = 0; dep2 < 5; dep2++){
                if (departments[dep1][i] == departments[dep2][i] && dep1 != dep2){
                    if (counter == 0) conflicts[0] = dep1 + 1;
                    counter++;
                    conflicts[counter] = dep2 + 1;
                }
            }
            printf("Conflicts: ");
            for (int j = 0; j < counter + 1; j++){
                printf("%d ", conflicts[j]);
            }
            printf("\n");
        }
    }

}

int main(){
    int programmers[10][10];
    int departments[10][10];
    int selection[5][2] = {{1,1},{2,2}, {3,3}, {4,4}, {5,5}};
    populateArrays(programmers, departments);
    // printArrays(programmers, departments); //
    match(programmers, departments, selection);
    return 0;
}