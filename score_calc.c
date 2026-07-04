<<<<<<< HEAD
printf("He's gay");
=======
#include <stdio.h>
#include "score_calc.h"
int calScore(){
    static int score=0;
    score++;
    return score;
}
    


void displayScore(int currentScore, int totalQuestion){

    if (totalQuestion <= 0){
        printf("no question answered \n");
        return;
    }

    float percentage = (  (float) currentScore  /   totalQuestion) * 100.0f ;



    printf("Total Questions : %d\n", totalQuestion);
    printf("Correct Answers : %d\n", currentScore);
    printf("Accuracy Rate   : %.2f%%\n", percentage);


}
int main(){
    int bro;
    int question = 10;
    calScore();
    bro = calScore();
    displayScore(bro,question);

    
}




>>>>>>> soth
