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

int selectionsNotFilled(int selection[5][2]){
    for (int i = 0; i < 5; i++){
        if (selection[i][1] == -1){
            return 1;
        }
    }
    return 0;
}

int check(int selection[5][2], int programmer){
    for (int i = 0; i < 5; i++){
        if (selection[i][1] == programmer){
            return 1;
        }
    } 
    return 0;
}

void match(int programmers[10][10], int departments[10][10], int selection[5][2]){
    while (selectionsNotFilled(selection)){
        printSelections(selection);
        for (int i = 0; i < 5; i++){
            if (selection[i][1] == -1){
                for (int j = 0; j < 5; j++){
                    if (check(selection, departments[i][j])){
                        int *value = &i;
                        for (int k; k < 5; k++){
                            int key;
                            for (int a = 0; a < 5; a++){
                                if(selection[a][1] == departments[i][j]){
                                    key = a;
                                }
                            }
                            if(programmers[(departments[i][j] - 1)][k] == i + 1){
                                break;
                            } else if (programmers[(departments[i][j] - 1)][k] == key + 1){
                                value = NULL;
                                break;
                            }
                        }
                        if (value != NULL){
                            int key;
                            for (int a = 0; a < 5; a++){
                                if(selection[a][1] == departments[i][j]){
                                    key = a;
                                }
                            }
                            selection[key][1] = -1;
                            selection[i][1] = departments[i][j];
                            break;
                        } else{
                            selection[i][1] = departments[i][j];
                            break;
                        }
                    }
                }
            }
        }
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