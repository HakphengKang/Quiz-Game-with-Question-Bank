#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void saveQuestions(void);
void viewQuestions(void);

static void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

static int readIntInput(const char *prompt) {
    char buffer[MAX_LENGTH];
    int value;

    while (1) {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));

        if (sscanf(buffer, "%d", &value) == 1) {
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
    }
}

void addQuestion(void) {
    if (totalQuestions >= MAX_QUESTIONS) {
        printf("\nQuestion bank is full. Cannot add more questions.\n");
        return;
    }

    struct Question q;
    char buffer[MAX_LENGTH];

    printf("\n============================================\n");
    printf("                ADD QUESTION\n");
    printf("============================================\n");

    printf("Enter question: ");
    readLine(q.question, sizeof(q.question));

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %c: ", 'A' + i);
        readLine(q.options[i], sizeof(q.options[i]));
    }

    while (1) {
        printf("Enter correct answer (A/B/C/D): ");
        readLine(buffer, sizeof(buffer));
        if (strlen(buffer) == 1) {
            char answer = buffer[0];
            if (answer >= 'a' && answer <= 'd') {
                answer -= 32;
            }
            if (answer >= 'A' && answer <= 'D') {
                q.answer = answer;
                break;
            }
        }
        printf("Invalid answer. Please enter A, B, C, or D.\n");
    }

    while (1) {
        printf("Enter difficulty (1=Easy, 2=Medium, 3=Hard): ");
        readLine(buffer, sizeof(buffer));
        if (sscanf(buffer, "%d", &q.difficulty) == 1 && q.difficulty >= 1 && q.difficulty <= 3) {
            break;
        }
        printf("Invalid difficulty. Please enter 1, 2, or 3.\n");
    }

    questionBank[totalQuestions++] = q;
    saveQuestions();
    printf("Question added successfully.\n");
}

void deleteQuestion(void) {
    if (totalQuestions == 0) {
        printf("\nNo questions available to delete.\n");
        return;
    }

    viewQuestions();

    int choice = readIntInput("Enter the question number to delete (0 to cancel): ");
    if (choice == 0) {
        printf("Delete cancelled.\n");
        return;
    }

    if (choice < 1 || choice > totalQuestions) {
        printf("Invalid question number.\n");
        return;
    }

    for (int i = choice - 1; i < totalQuestions - 1; i++) {
        questionBank[i] = questionBank[i + 1];
    }

    totalQuestions--;
    saveQuestions();
    printf("Question deleted successfully.\n");
}
