#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_LENGTH 256
#define MAX_OPTIONS 4

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    char answer;
    int difficulty;
} Question;

typedef struct {
    int score;
    char name[50];
} HighScore;

Question questions[MAX_QUESTIONS];
int totalQuestions = 0;

// Function to load questions from file
int loadQuestions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        return 0;
    }

    char line[MAX_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < MAX_QUESTIONS) {
        line[strcspn(line, "\n")] = 0;
        
        char *token = strtok(line, "|");
        if (token == NULL) continue;
        
        strcpy(questions[count].question, token);
        
        for (int i = 0; i < MAX_OPTIONS; i++) {
            token = strtok(NULL, "|");
            if (token == NULL) break;
            strcpy(questions[count].options[i], token);
        }
        
        token = strtok(NULL, "|");
        if (token == NULL) continue;
        questions[count].answer = token[0];
        
        token = strtok(NULL, "|");
        if (token == NULL) continue;
        questions[count].difficulty = atoi(token);
        
        count++;
    }

    fclose(file);
    totalQuestions = count;
    printf("Loaded %d questions from %s\n\n", totalQuestions, filename);
    return count > 0;
}

// Function to shuffle questions
void shuffleQuestions(int *indices, int count) {
    srand(time(NULL));
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}

// Function to display a question
void displayQuestion(Question *q, int questionNumber, int totalAsked) {
    printf("\n--- Question %d of %d (Difficulty: %d) ---\n", questionNumber, totalAsked, q->difficulty);
    printf("%s\n", q->question);
    printf("A) %s\n", q->options[0]);
    printf("B) %s\n", q->options[1]);
    printf("C) %s\n", q->options[2]);
    printf("D) %s\n", q->options[3]);
}

// Function to get user answer
char getUserAnswer() {
    char answer;
    printf("\nYour answer (A/B/C/D): ");
    scanf(" %c", &answer);
    answer = (answer >= 'a' && answer <= 'd') ? (answer - 32) : answer;
    return answer;
}

// Function to calculate score based on difficulty
int calculateScore(int difficulty, int correct) {
    if (!correct) return 0;
    return 10 * difficulty;
}

// Function to load high score
HighScore loadHighScore() {
    HighScore hs = {0, "No Score Yet"};
    FILE *file = fopen("highscore.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d %s", &hs.score, hs.name);
        fclose(file);
    }
    return hs;
}

// Function to save high score
void saveHighScore(int score, const char *name) {
    FILE *file = fopen("highscore.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d %s", score, name);
        fclose(file);
    }
}

// Function to display menu
int displayMenu() {
    int choice;
    printf("\n========== QUIZ GAME ==========\n");
    printf("1. Play Quiz (All Questions)\n");
    printf("2. Play Custom (Select Difficulty)\n");
    printf("3. View High Score\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

// Function to play quiz
void playQuiz(int difficulty) {
    if (totalQuestions == 0) {
        printf("No questions available!\n");
        return;
    }

    int *indices = (int *)malloc(totalQuestions * sizeof(int));
    int questionsToAsk = (totalQuestions < 5) ? totalQuestions : 5;
    int score = 0;
    int questionCount = 0;

    for (int i = 0; i < totalQuestions; i++) {
        indices[i] = i;
    }

    shuffleQuestions(indices, totalQuestions);

    printf("\n========== QUIZ STARTED ==========\n");

    for (int i = 0; i < questionsToAsk; i++) {
        Question *q = &questions[indices[i]];
        
        if (difficulty != 0 && q->difficulty != difficulty) {
            i--;
            questionsToAsk++;
            if (questionsToAsk > totalQuestions) questionsToAsk = totalQuestions;
            continue;
        }

        displayQuestion(q, i + 1, questionsToAsk);
        char userAnswer = getUserAnswer();

        if (userAnswer == q->answer) {
            printf("Correct!\n");
            score += calculateScore(q->difficulty, 1);
        } else {
            printf("Incorrect! Correct answer: %c\n", q->answer);
        }
        questionCount++;
    }

    printf("\n========== QUIZ FINISHED ==========\n");
    printf("Your final score: %d\n", score);

    HighScore hs = loadHighScore();
    if (score > hs.score) {
        char name[50];
        printf("New high score! Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        saveHighScore(score, name);
        printf("High score saved!\n");
    }

    free(indices);
}

int main() {
    if (!loadQuestions("questions.txt")) {
        printf("Failed to load questions. Please ensure questions.txt exists.\n");
        return 1;
    }

    int choice;
    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1:
                playQuiz(0);
                break;
            case 2: {
                printf("Select difficulty (1=Easy, 2=Medium, 3=Hard): ");
                int diff;
                scanf("%d", &diff);
                if (diff >= 1 && diff <= 3) {
                    playQuiz(diff);
                } else {
                    printf("Invalid difficulty level!\n");
                }
                break;
            }
            case 3: {
                HighScore hs = loadHighScore();
                printf("\n========== HIGH SCORE ==========\n");
                printf("Name: %s\n", hs.name);
                printf("Score: %d\n", hs.score);
                printf("================================\n");
                break;
            }
            case 4:
                printf("Thank you for playing! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
