#include "kdethgay.h" 
#include <stdio.h>
#include "score_calc.h"
#include <string.h>

int displayQuestions() {
    char userAnswer;
    int score;
    loadQuestions(0);
    printf("Enter your answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'A' || userAnswer == 'a'){
        calScore();
    }
    loadQuestions(1);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'B' || userAnswer == 'b'){
        calScore();
    }
    loadQuestions(2);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        calScore();
    }
    loadQuestions(3);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        calScore();
    }
    loadQuestions(4);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'D' || userAnswer == 'd'){
        calScore();
    }
    loadQuestions(5);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        calScore();
    }
    loadQuestions(6);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        calScore();
    }
    loadQuestions(7);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'A' || userAnswer == 'a'){
        calScore();
    }
    loadQuestions(8);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        calScore();
    }
    loadQuestions(9);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        score = calScore();
    }
    return score;
}
void displayScore(int score){
    displayScore(score, 10 ,"dorm");
}