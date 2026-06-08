#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 256
#define QUESTION_FILE "questions.txt"
#define HIGHSCORE_FILE "highscore.txt"

// Structure for Question
struct Question {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    char answer;          // 'A', 'B', 'C', or 'D'
    int difficulty;       // 1 = Easy, 2 = Medium, 3 = Hard
};

// Global variables
struct Question questionBank[MAX_QUESTIONS];
int totalQuestions = 0;
int highScore = 0;

// Function prototypes
void loadQuestions();
int selectDifficulty();
void askQuestion(struct Question q, int *score, int questionNum);
int calculateScore(int correct, int total, int difficulty);
void saveHighScore(int score);
void showResult(int score, int correct, int total, int difficulty);
void shuffleQuestions(struct Question arr[], int n);
void createSampleQuestionFile();
void loadHighScore();

int main() {
    int choice;

    srand(time(NULL));

    printf("============================================\n");
    printf("       QUIZ GAME WITH QUESTION BANK\n");
    printf("============================================\n\n");

    // Create sample question file if it doesn't exist
    FILE *check = fopen(QUESTION_FILE, "r");
    if (check == NULL) {
        printf("Question file not found. Creating sample questions...\n\n");
        createSampleQuestionFile();
    } else {
        fclose(check);
    }

    // Load questions from file
    loadQuestions();
    loadHighScore();

    if (totalQuestions == 0) {
        printf("Error: No questions loaded. Exiting.\n");
        return 1;
    }

    do {
        printf("\n============================================\n");
        printf("              MAIN MENU\n");
        printf("============================================\n");
        printf("1. Start Quiz\n");
        printf("2. View High Score\n");
        printf("3. View Total Questions Available\n");
        printf("4. Exit\n");
        printf("============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: {
                int difficulty = selectDifficulty();
                if (difficulty == 0) break;

                // Filter questions by difficulty
                struct Question filteredQuestions[MAX_QUESTIONS];
                int filteredCount = 0;

                for (int i = 0; i < totalQuestions; i++) {
                    if (questionBank[i].difficulty == difficulty) {
                        filteredQuestions[filteredCount++] = questionBank[i];
                    }
                }

                if (filteredCount == 0) {
                    printf("\nNo questions available for this difficulty level.\n");
                    break;
                }

                // Shuffle questions (randomize)
                shuffleQuestions(filteredQuestions, filteredCount);

                // Determine number of questions to ask
                int numQuestions;
                printf("\nAvailable questions for this level: %d\n", filteredCount);
                printf("How many questions would you like? (1-%d): ", filteredCount);
                scanf("%d", &numQuestions);
                getchar();

                if (numQuestions < 1 || numQuestions > filteredCount) {
                    numQuestions = filteredCount;
                }

                // Start the quiz
                int correct = 0;
                printf("\n============================================\n");
                printf("         QUIZ STARTING! GOOD LUCK!\n");
                printf("============================================\n");

                for (int i = 0; i < numQuestions; i++) {
                    askQuestion(filteredQuestions[i], &correct, i + 1);
                }

                // Calculate and show results
                int score = calculateScore(correct, numQuestions, difficulty);
                showResult(score, correct, numQuestions, difficulty);

                // Save high score if applicable
                if (score > highScore) {
                    printf("\n*** NEW HIGH SCORE! ***\n");
                    saveHighScore(score);
                    highScore = score;
                }
                break;
            }
            case 2:
                printf("\n============================================\n");
                printf("Current High Score: %d\n", highScore);
                printf("============================================\n");
                break;
            case 3:
                printf("\n============================================\n");
                printf("Total Questions in Bank: %d\n", totalQuestions);
                int easy = 0, medium = 0, hard = 0;
                for (int i = 0; i < totalQuestions; i++) {
                    if (questionBank[i].difficulty == 1) easy++;
                    else if (questionBank[i].difficulty == 2) medium++;
                    else if (questionBank[i].difficulty == 3) hard++;
                }
                printf("Easy: %d | Medium: %d | Hard: %d\n", easy, medium, hard);
                printf("============================================\n");
                break;
            case 4:
                printf("\nThank you for playing! Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Load questions from file
void loadQuestions() {
    FILE *fp = fopen(QUESTION_FILE, "r");
    if (fp == NULL) {
        printf("Error: Cannot open question file '%s'\n", QUESTION_FILE);
        return;
    }

    totalQuestions = 0;
    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, fp) != NULL && totalQuestions < MAX_QUESTIONS) {
        // Remove newline
        line[strcspn(line, "\n")] = '\0';

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Format: question|optionA|optionB|optionC|optionD|answer|difficulty
        char *token;
        struct Question q;

        token = strtok(line, "|");
        if (token == NULL) continue;
        strcpy(q.question, token);

        for (int i = 0; i < MAX_OPTIONS; i++) {
            token = strtok(NULL, "|");
            if (token == NULL) break;
            strcpy(q.options[i], token);
        }

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        q.answer = token[0];

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        q.difficulty = atoi(token);

        // Validate difficulty
        if (q.difficulty < 1 || q.difficulty > 3) {
            q.difficulty = 1;
        }

        questionBank[totalQuestions++] = q;
    }

    fclose(fp);
    printf("Successfully loaded %d questions from file.\n", totalQuestions);
}

// Select difficulty level
int selectDifficulty() {
    int choice;
    printf("\n============================================\n");
    printf("        SELECT DIFFICULTY LEVEL\n");
    printf("============================================\n");
    printf("1. Easy   (x1 multiplier)\n");
    printf("2. Medium (x2 multiplier)\n");
    printf("3. Hard   (x3 multiplier)\n");
    printf("0. Back to Main Menu\n");
    printf("============================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice >= 1 && choice <= 3) {
        return choice;
    }
    return 0;
}

// Ask a single question
void askQuestion(struct Question q, int *score, int questionNum) {
    char userAnswer;

    printf("\n--------------------------------------------\n");
    printf("Question %d: %s\n", questionNum, q.question);
    printf("--------------------------------------------\n");
    printf("  A) %s\n", q.options[0]);
    printf("  B) %s\n", q.options[1]);
    printf("  C) %s\n", q.options[2]);
    printf("  D) %s\n", q.options[3]);
    printf("\nYour answer (A/B/C/D): ");
    scanf(" %c", &userAnswer);
    getchar();

    // Convert to uppercase
    if (userAnswer >= 'a' && userAnswer <= 'd') {
        userAnswer -= 32;
    }

    if (userAnswer == q.answer) {
        printf("✓ CORRECT!\n");
        (*score)++;
    } else {
        printf("✗ WRONG! The correct answer was: %c\n", q.answer);
    }
}

// Calculate final score with difficulty multiplier
int calculateScore(int correct, int total, int difficulty) {
    int baseScore = (correct * 100) / total;
    return baseScore * difficulty; // Multiply by difficulty level
}

// Save high score to file
void saveHighScore(int score) {
    FILE *fp = fopen(HIGHSCORE_FILE, "w");
    if (fp == NULL) {
        printf("Error: Cannot save high score.\n");
        return;
    }
    fprintf(fp, "%d\n", score);
    fclose(fp);
    printf("High score saved successfully!\n");
}

// Load high score from file
void loadHighScore() {
    FILE *fp = fopen(HIGHSCORE_FILE, "r");
    if (fp == NULL) {
        highScore = 0;
        return;
    }
    fscanf(fp, "%d", &highScore);
    fclose(fp);
}

// Show final results
void showResult(int score, int correct, int total, int difficulty) {
    char *difficultyStr;
    switch (difficulty) {
        case 1: difficultyStr = "Easy"; break;
        case 2: difficultyStr = "Medium"; break;
        case 3: difficultyStr = "Hard"; break;
        default: difficultyStr = "Unknown"; break;
    }

    printf("\n============================================\n");
    printf("              QUIZ RESULTS\n");
    printf("============================================\n");
    printf("Difficulty:        %s (x%d multiplier)\n", difficultyStr, difficulty);
    printf("Questions Answered: %d\n", total);
    printf("Correct Answers:    %d\n", correct);
    printf("Wrong Answers:      %d\n", total - correct);
    printf("Accuracy:           %.1f%%\n", (float)correct / total * 100);
    printf("Final Score:        %d\n", score);
    printf("Current High Score: %d\n", highScore);
    printf("============================================\n");

    // Performance message
    float percentage = (float)correct / total * 100;
    if (percentage == 100) {
        printf("🏆 PERFECT SCORE! Outstanding!\n");
    } else if (percentage >= 80) {
        printf("🌟 Excellent! Great job!\n");
    } else if (percentage >= 60) {
        printf("👍 Good effort! Keep practicing!\n");
    } else if (percentage >= 40) {
        printf("📚 Fair. You can do better!\n");
    } else {
        printf("💪 Keep studying and try again!\n");
    }
}

// Shuffle questions using Fisher-Yates algorithm
void shuffleQuestions(struct Question arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Question temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Create a sample question file
void createSampleQuestionFile() {
    FILE *fp = fopen(QUESTION_FILE, "w");
    if (fp == NULL) {
        printf("Error: Cannot create question file.\n");
        return;
    }

    // Easy Questions (difficulty = 1)
    fprintf(fp, "What is the size of 'int' in C (on most 32/64-bit systems)?|2 bytes|4 bytes|8 bytes|1 byte|B|1\n");
    fprintf(fp, "Which function is used to print output in C?|scanf()|printf()|cout|print()|B|1\n");
    fprintf(fp, "What is the correct syntax to declare a variable in C?|int x;|variable x;|declare x;|x int;|A|1\n");
    fprintf(fp, "Which header file is needed for printf()?|stdlib.h|string.h|stdio.h|math.h|C|1\n");
    fprintf(fp, "What does '%%d' format specifier represent?|Float|Character|Integer|String|C|1\n");
    fprintf(fp, "Which operator is used for assignment in C?|==|=|:=|=>|B|1\n");
    fprintf(fp, "What is the index of the first element in a C array?|1|0|-1|Depends on array|B|1\n");

    // Medium Questions (difficulty = 2)
    fprintf(fp, "What is the output of: printf(\"%%d\", 5/2);|2.5|2|3|2.0|B|2\n");
    fprintf(fp, "Which keyword is used to prevent modification of a variable?|static|const|volatile|register|B|2\n");
    fprintf(fp, "What does malloc() return if memory allocation fails?|0|-1|NULL|Error|C|2\n");
    fprintf(fp, "What is a dangling pointer?|Pointer to NULL|Pointer to freed memory|Uninitialized pointer|Void pointer|B|2\n");
    fprintf(fp, "Which sorting algorithm has O(n log n) average case?|Bubble Sort|Selection Sort|Quick Sort|Insertion Sort|C|2\n");
    fprintf(fp, "What is the purpose of 'break' in a switch statement?|End program|Exit loop/switch|Skip iteration|None|B|2\n");
    fprintf(fp, "How do you access a structure member using a pointer?|ptr.member|ptr->member|*ptr.member|ptr::member|B|2\n");

    // Hard Questions (difficulty = 3)
    fprintf(fp, "What is the time complexity of binary search?|O(n)|O(log n)|O(n^2)|O(1)|B|3\n");
    fprintf(fp, "What does the 'volatile' keyword indicate?|Variable is constant|Variable may change unexpectedly|Variable is static|Variable is global|B|3\n");
    fprintf(fp, "What is the output of: printf(\"%%d\", sizeof(char));|0|1|2|4|B|3\n");
    fprintf(fp, "In C, what is a function pointer?|Pointer returned by function|Pointer to a function|Function that returns pointer|None|B|3\n");
    fprintf(fp, "What is the difference between stack and heap memory?|Stack is dynamic, heap is static|Stack is LIFO auto-managed, heap is manually managed|No difference|Stack is slower|B|3\n");
    fprintf(fp, "What happens with: int *p = malloc(0);|Compilation error|Undefined behavior or valid unique pointer|Returns NULL always|Segmentation fault|B|3\n");
    fprintf(fp, "What is a memory leak?|Accessing freed memory|Allocated memory never freed|Buffer overflow|Stack overflow|B|3\n");

    fclose(fp);
    printf("Sample question file created with 21 questions.\n");
}
