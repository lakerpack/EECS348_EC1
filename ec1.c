#include <stdio.h>

void populateArrays(int programmers[5][5], int departments[5][5]){
    FILE *input;
    input = fopen("matching-data.txt", "r");
    for (int i = 0; i < 10; i++){
        if (i < 5){
            fscanf(input, "%d %d %d %d \n", &departments[0][i], &departments[1][i], &departments[2][i], &departments[3][i], &departments[4][i]);
            continue;
        }
        fscanf(input, "%d %d %d %d \n", &programmers[0][i], &programmers[1][i], &programmers[2][i], &programmers[3][i], &programmers[4][i]);
    }
    fclose(input);
}

int main(){
    int programmers[5][5];
    int departments[5][5];

    return 0;
}