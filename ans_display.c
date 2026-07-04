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
