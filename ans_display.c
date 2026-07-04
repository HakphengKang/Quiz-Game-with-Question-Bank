#include "kdethgay.h" 
#include <stdio.h>

int main() {
    char userAnswer;
    loadQuestions(0);
    printf("Enter your answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'A' || userAnswer == 'a'){
    printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(1);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'B' || userAnswer == 'b'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(2);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(3);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(4);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'D' || userAnswer == 'd'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(5);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(6);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(7);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'A' || userAnswer == 'a'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(8);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
    loadQuestions(9);
    printf("Enter Your Answer (A-D): ");
    scanf(" %c", &userAnswer);

    if(userAnswer == 'C' || userAnswer == 'c'){
        printf("Correct\n");
    }else {
        printf("Incorrect\n");
    }
}