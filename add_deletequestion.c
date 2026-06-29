#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING 256


typedef struct {
    char question[MAX_STRING];
    char options[4][MAX_STRING];  
    char answer;                 
    int difficulty;               
} Question;

// Function prototype
Question addQuestion(void);
void displayAddedQuestion(Question q);
void saveQuestionToFile(Question q, const char *filename);

int main(void) {
    Question newQuestion;

    printf("\n  ╔═══════════════════════════════════════╗\n");
    printf("  ║       ADD A NEW QUESTION              ║\n");
    printf("  ╚═══════════════════════════════════════╝\n\n");

    newQuestion = addQuestion();

    printf("\n  ═══════════════════════════════════════\n");
    printf("  Here is your added question:\n");
    printf("  ═══════════════════════════════════════\n");

    displayAddedQuestion(newQuestion);

    // Save to file
    saveQuestionToFile(newQuestion, "questions.txt");
    printf("\n  Question saved to questions.txt!\n");

    return 0;
}

// Function to add a new question via user input
Question addQuestion(void) {
    Question q;
    char input[MAX_STRING];

    // Get the question
    printf("  Enter your question:\n");
    printf("  > ");
    fgets(q.question, MAX_STRING, stdin);
    q.question[strcspn(q.question, "\n")] = '\0';  // Remove newline

    // Get options A, B, C, D
    printf("\n  Enter Option A:\n");
    printf("  A. ");
    fgets(q.options[0], MAX_STRING, stdin);
    q.options[0][strcspn(q.options[0], "\n")] = '\0';

    printf("\n  Enter Option B:\n");
    printf("  B. ");
    fgets(q.options[1], MAX_STRING, stdin);
    q.options[1][strcspn(q.options[1], "\n")] = '\0';

    printf("\n  Enter Option C:\n");
    printf("  C. ");
    fgets(q.options[2], MAX_STRING, stdin);
    q.options[2][strcspn(q.options[2], "\n")] = '\0';

    printf("\n  Enter Option D:\n");
    printf("  D. ");
    fgets(q.options[3], MAX_STRING, stdin);
    q.options[3][strcspn(q.options[3], "\n")] = '\0';

    // Get correct answer
    while (1) {
        printf("\n  Enter the correct answer (A/B/C/D):\n");
        printf("  > ");
        fgets(input, MAX_STRING, stdin);
        q.answer = toupper(input[0]);

        if (q.answer >= 'A' && q.answer <= 'D') {
            break;
        }
        printf("  Invalid! Please enter A, B, C, or D.\n");
    }

    // Get difficulty
    while (1) {
        printf("\n  Enter difficulty level:\n");
        printf("  1. Easy\n");
        printf("  3. Hard\n");
        printf("  > ");
        fgets(input, MAX_STRING, stdin);
        q.difficulty = atoi(input);

        if (q.difficulty == 1 || q.difficulty == 3) {
            break;
        }
        printf("  Invalid! Please enter 1 (Easy) or 3 (Hard).\n");
    }

    return q;
}

// Display the added question
void displayAddedQuestion(Question q) {
    printf("\n  Question: %s\n", q.question);
    printf("  A. %s\n", q.options[0]);
    printf("  B. %s\n", q.options[1]);
    printf("  C. %s\n", q.options[2]);
    printf("  D. %s\n", q.options[3]);
    printf("  Correct Answer: %c\n", q.answer);
    printf("  Difficulty: %s\n", q.difficulty == 1 ? "Easy" : "Hard");
}

// Save question to file in the correct format
void saveQuestionToFile(Question q, const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("  Error: Could not open file.\n");
        return;
    }

    fprintf(fp, "%s|%s|%s|%s|%s|%c|%d\n",
            q.question,
            q.options[0],
            q.options[1],
            q.options[2],
            q.options[3],
            q.answer,
            q.difficulty);

    fclose(fp);
}