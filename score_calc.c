#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIGHSCORE_FILE "highscore.txt"

extern int highScore;

int calculateScore(int correct, int total, int difficulty) {
    if (total == 0) {
        return 0;
    }
    
    // Calculate base percentage score (0-100)
    int baseScore = (correct * 100) / total;
    
    // Apply difficulty multiplier
    // Easy (1x), Medium (2x), Hard (3x)
    int finalScore = baseScore * difficulty;
    
    return finalScore;
}

void showResult(int score, int correct, int total, int difficulty) {
    char *difficultyStr;
    
    // Map difficulty number to string
    switch (difficulty) {
        case 1:
            difficultyStr = "Easy";
            break;
        case 2:
            difficultyStr = "Medium";
            break;
        case 3:
            difficultyStr = "Hard";
            break;
        default:
            difficultyStr = "Unknown";
            break;
    }

    // Display quiz results
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

    // Show performance feedback
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
