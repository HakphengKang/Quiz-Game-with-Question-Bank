#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <string.h> 
#include "kdethgay.h"
#include <stdlib.h>
void loopMenu(void);
void displayMenu() {
    printf("=== QUIZ SYSTEM ===\n");
    printf("1. Start Quiz\n");
    printf("2. View Scoreboard\n");
    printf("3. Add Question\n");
    printf("4. Delete Question\n");
    printf("5. View Questions\n");
    printf("6. Exit\n");
}
void getValidName(char *name) {
    int valid = 0;
    
    while (!valid) {
        printf("Please Enter Your Name (no spaces or digits allowed): ");
        scanf(" %[^\n]", name);
        
        // Check if name is empty
        if (strlen(name) == 0) {
            printf(" Error: Name cannot be empty! Please try again.\n\n");
            continue;
        }
        
        int hasSpace = 0;
        int hasDigit = 0;
        int hasSpecialChar = 0;
        
        // Check each character in the name
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] == ' ') {
                hasSpace = 1;
            } else if (isdigit(name[i])) {
                hasDigit = 1;
            } else if (!isalpha(name[i]) && name[i] != '-' && name[i] != '\'') {
                // Check for special characters (allow hyphen and apostrophe)
                hasSpecialChar = 1;
            }
        }
        
        // Display appropriate error messages
        if (hasSpace && hasDigit) {
            printf(" Error: Name cannot contain spaces OR digits! Please try again.\n\n");
        } else if (hasSpace) {
            printf(" Error: Name cannot contain spaces! Please try again.\n\n");
        } else if (hasDigit) {
            printf(" Error: Name cannot contain digits! Please try again.\n\n");
        } else if (hasSpecialChar) {
            printf(" Error: Name can only contain letters, hyphens, and apostrophes! Please try again.\n\n");
        } else {
            valid = 1;  // No errors, exit loop
            printf(" Name accepted!\n\n");
        }
    }
}
int getchoice(){
    int choice;
    int valid = 0;
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice >=1 && choice <=6){
            valid++;
        }else{
            printf(" Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }while(valid!=1);
}
 

void handleChoice(int choice) {
    switch(choice) {
        case 1: 
            int choice;
            int valid = 0;
            printf("Starting Quiz...\n");
            printf("what do you choose?\n");
            printf("1.High difficulty\n");
            printf("2.Medium difficulty\n");
            printf("3.Low difficulty\n");
            do{
                printf("Enter your choice(1-3): ");
                scanf("%d", &choice);
                if(choice >= 1 && choice <= 3){
                    valid = 1;
                    if(choice == 1){
                        printf("You chose High difficulty.\n");
                    }else if(choice == 2){
                        printf("You chose Medium difficulty.\n");
                    }else if(choice == 3){
                        printf("You chose Low difficulty.\n");
                    }
                }else{
                    printf(" Invalid choice! Please enter a number between 1 and 3.\n");
                }
            }while(valid!=1);
            break;

        case 2:{
            int vadid=0;
            int choices;
            int Pref;
            do {
                printf("\n===================SELECTION===================\n");
                printf("enter the question difficulty you want to view:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter choice: ");
                scanf("%d", &choices);

                if(choices==1){
                    viewQuestions();
                    vadid = 1;
                }else if (choices ==2){
                    viewMQuestions();
                    vadid = 1;
                }else if (choices == 3){
                    viewHQuestions();
                    vadid = 1;
                }else{
                    vadid = 0;
                }
            } while (vadid!=1);
            int didway=0;
            do{
                printf("\n============SELECTION===========\n");
                printf("enter 1 if stay, enter 2 if exit\n");
                scanf("%d", &Pref);
                
                if(Pref == 1){
                    loopMenu();
                    didway++;
                }else if (Pref == 2){
                    exit(1);
                    didway++;
                }else{
                    printf("Please enter only enter the digit 1 or 2\n");
                }

            }while(didway!=1);
            break;
        }

        case 3:
            printf("Adding Question...\n");
            loopMenu();
            break;

        case 4:
            printf("Deleting Question...\n");
            loopMenu();
            break;

        case 5:{

            int vadid=0;
            int choices;
            int Pref;
            do {
                printf("\n===================SELECTION===================\n");
                printf("enter the question difficulty you want to view:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter choice: ");
                scanf("%d", &choices);

                if(choices==1){
                    viewScoreboard();
                    vadid = 1;
                }else if (choices ==2){
                    viewMScoreboard();
                    vadid = 1;
                }else if (choices == 3){
                    viewHScoreboard();
                    vadid = 1;
                }else{
                    vadid = 0;
                }
            } while (vadid!=1);
            int didway=0;
            do{
                printf("\n============SELECTION===========\n");
                printf("enter 1 if stay, enter 2 if exit\n");
                scanf("%d", &Pref);
                
                if(Pref == 1){
                    loopMenu();
                    didway++;
                }else if (Pref == 2){
                    exit(1);
                    didway++;
                }else{
                    printf("Please enter only enter the digit 1 or 2\n");
                }

            }while(didway!=1);
            break;
        }

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
    }
}
void loopMenu(){
    char name[50];
    int choice;
    displayMenu();
    choice = getchoice();
    getValidName(name);
    handleChoice(choice);
}
int main(){
    handleChoice(5);
}
