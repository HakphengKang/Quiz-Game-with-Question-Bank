#include <stdio.h>
#include "score_calc.h"
#include <string.h>
int calScore(){
    static int score=0;
    score++;
    return score;
}
    



void displayScore(int currentScore, int totalQuestion, char name[]){
    char nam[50];
    if (totalQuestion <= 0){
        printf("no question answered \n");
        return;
    }

    float percentage = (  (float) currentScore  /   totalQuestion) * 100.0f ;

    strcpy(nam, name);
    printf("Name: %s\n", name);
    printf("Total Questions : %d\n", totalQuestion);
    printf("Correct Answers : %d\n", currentScore);
    printf("Accuracy Rate   : %.2f%%\n", percentage);


<<<<<<< HEAD
}
=======
}





>>>>>>> Ra
