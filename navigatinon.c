#include <stdio.h>
#include <ctype.h>

void loopMenu() {
    int choice;
    char userAnswer;
    
    while (1) {
        printf("\n========================================\n");
        printf("        MAIN MENU\n");
        printf("========================================\n");
        printf("  1. Start Quiz\n");
        printf("  2. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        
        if (choice == 2) {
            printf("\nGoodbye!\n");
            return;
        }
        
        if (choice != 1) {
            printf("\n❌ Invalid choice! Press Enter to continue...");
            getchar();
            continue;
        }
        
        // Start Quiz - ONLY ASKS FOR ANSWER
        printf("\n========================================\n");
        printf("        ANSWER PROMPT\n");
        printf("========================================\n");
        printf("\nEnter your answer (A-D): ");
        scanf(" %c", &userAnswer);
        while (getchar() != '\n');
        
        userAnswer = toupper(userAnswer);
        if (userAnswer < 'A' || userAnswer > 'D') {
            printf("\n❌ Invalid answer! Must be A, B, C, or D.\n");
            continue;
        }
        
    }
}

int main() {
    loopMenu();
    return 0;
}