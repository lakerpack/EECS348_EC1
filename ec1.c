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

int selectionsFilled(int selection[5][2]){
    for (int i = 0; i < 5; i++){
        if (selection[i][1] == -1){
            return 0;
        }
    }
    return 1;
}

void match(int programmers[10][10], int departments[10][10], int selection[5][2]){
    do {
        
    } while (selectionsFilled(selection))

}

void printSelections(int selection[5][2]){
    for (int i = 0; i < 5; i++){
        printf("Department %d gets Programmer %d \n", i + 1, selection[i][1]);
    }
}

int main(){
    int programmers[10][10];
    int departments[10][10];
    int selection[5][2] = {{1,-1},{2,-1}, {3,-1}, {4,-1}, {5,-1}};
    populateArrays(programmers, departments);
    match(programmers, departments, selection);
    printSelections(selection);
    return 0;
}