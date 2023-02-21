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

int check(int department, int selection[5][2]){
    if (selection[department][1] != -1) return 0;
    return 1;
}

int solve(int programmers[10][10], int departments[10][10], int selection[5][2], int conflicts[5], int counter2, int conflictee){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < counter2 + 1; j++){
            if (programmers[conflictee][i] == conflicts[j]){
                printf("Department %d was able to pick Programmer %d \n", conflicts[j], conflictee);
                selection[conflicts[j] - 1][1] = conflictee;
                return 0;
            }
        }
    }

}

void match(int programmers[10][10], int departments[10][10], int selection[5][2]){
    int counter = 0;
    for (int i = 0; i < 5; i++){
        for (int first = 0; first < 5; first++){
            if (check(first, selection)){
                int counter2 = 0;
                int conflicts[5];
                int conflictee;
                int safe = 1;
                for (int second = 0; second < 5; second++){
                    if(departments[first][i] == departments[second][i] && first != second){
                        printf("Department %d and %d conflict over Programmer %d \n", first + 1, second + 1, departments[first][i]);
                        safe = 0;
                        if (counter2 == 0) conflicts[counter2] = first + 1;
                        counter2++;
                        conflicts[counter2] = second + 1;
                        conflictee = departments[first][i];
                    }
                }
                solve(programmers, departments, selection, conflicts, counter2, conflictee);
                if (safe) {
                    selection[first][1] = departments[first][i];
                    printf("Department %d was able to pick Programmer %d \n", first + 1, departments[first][i]);
                }
            }

        }
        printf("\n");
    }

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