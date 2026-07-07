<<<<<<< HEAD
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
int main(){
    displayScore(10,10,"deth");
}
=======
#include <stdio.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 256

struct Question {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    char answer;
    int difficulty;
};

extern struct Question questionBank[MAX_QUESTIONS];
extern int totalQuestions;

void DisplayChoice(struct Question question) {
    printf("   A) %s\n", question.options[0]);
    printf("   B) %s\n", question.options[1]);
    printf("   C) %s\n", question.options[2]);
    printf("   D) %s\n", question.options[3]);
}

void viewQuestions(void) {
    if (totalQuestions == 0) {
        printf("\nNo questions available.\n");
        return;
    }

    printf("\n============================================\n");
    printf("               STORED QUESTIONS\n");
    printf("============================================\n");

    for (int i = 0; i < totalQuestions; i++) {
        printf("%d. %s\n", i + 1, questionBank[i].question);
        DisplayChoice(questionBank[i]);
        printf("   Answer: %c | Difficulty: %d\n", questionBank[i].answer, questionBank[i].difficulty);
        printf("--------------------------------------------\n");
    }
}
>>>>>>> 60ecbdb1ecd10e857b09f4fb643b00d199ea808b
