#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <string.h> 
#include "filehandle.h"
#include <stdlib.h>
#include "addquestiot.h"
#include <stdbool.h>
#include "score_calc.h"
#include "ans_display.h"
void loopMenu(void);
void displayMenu() {
    printf("=== QUIZ SYSTEM ===\n");
    printf("1. Start Quiz\n");
    printf("2. View Questions\n");
    printf("3. Add Question\n");
    printf("4. Delete Question\n");
    printf("5. View Scoreboard\n");
    printf("6. Exit\n");
}
void flushInput(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // flush bad input
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
            continue;
        }
        flushInput();
        if(choice >=1 && choice <=6){
            valid++;
        }else{
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }while(valid!=1);
    return choice;
}
 

void handleChoice(int choice) {
    switch(choice) {
        case 1: {
            int choice;
            int valid = 0;
            char name[50];
            int score;
            int questions;
            bool correct_choice = false;
            getValidName(name);
            printf("Starting Quiz...\n");
            printf("what do you choose?\n");
            printf("1.Low difficulty\n");
            printf("2.Medium difficulty\n");
            printf("3.hard difficulty\n");
            do{
                int toy;
                
                printf("Enter your choice(1-3): ");
                if (scanf("%d", &choice) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }
                if(choice >= 1 && choice <= 3){
                    score = displayQuestions(choice,'0');
                    valid = 1;
                    if(choice==1){
                        questions = checkLQuestions();
                        displayScore(score,questions,name);
                        saveScore(name,score);
                        printf("Do you want to view the scoreboard?\n");
                        printf("1 to view, 2 to go main menu, 3 to exit\n");
                        
                        do{
                            printf("please choose: ");
                            if (scanf("%d", &toy) != 1) {
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            printf("invalid choice please choose again!\n");
                            continue;
                            }
                            if(toy==1){
                                viewScoreboard();
                                correct_choice = true;
                            }else if(toy==2){
                                loopMenu();
                                correct_choice = true;
                            }else if(toy==3){
                                exit(1);
                                correct_choice = true;
                            }else{
                                printf("invalid choice please choose again!\n");
                            }
                        }while(!correct_choice);

                    }else if (choice == 2){
                        questions = checkMQuestions();
                        displayScore(score,questions,name);
                        saveMScore(name,score);
                        printf("Do you want to view the scoreboard?\n");
                        printf("1 to view, 2 to go main menu, 3 to exit\n");
                        
                        do{
                            printf("please choose: ");
                            if (scanf("%d", &toy) != 1) {
                                int c;
                                while ((c = getchar()) != '\n' && c != EOF);
                                printf("invalid choice please choose again!\n");
                                continue;
                            }
                            if(toy==1){
                                viewMScoreboard();
                                correct_choice = true;
                            }else if(toy==2){
                                loopMenu();
                                correct_choice = true;
                            }else if(toy==3){
                                exit(1);
                                correct_choice = true;
                            }else{
                                printf("invalid choice please choose again!\n");
                            }
                        }while(!correct_choice);
                        
                    }else{
                        questions = checkHQuestions();
                        displayScore(score,questions,name);
                        saveHScore(name,score);
                        printf("Do you want to view the scoreboard?\n");
                        printf("1 to view, 2 to go main menu, 3 to exit\n");
                        
                        do{
                            printf("please choose: ");
                            if (scanf("%d", &toy) != 1) {
                                int c;
                                while ((c = getchar()) != '\n' && c != EOF);
                                printf("invalid choice please choose again!\n");
                                continue;
                            }
                            if(toy==1){
                                viewHScoreboard();
                                correct_choice = true;
                            }else if(toy==2){
                                loopMenu();
                                correct_choice = true;
                            }else if(toy==3){
                                exit(1);
                                correct_choice = true;
                            }else{
                                printf("invalid choice please choose again!\n");
                            }
                        }while(!correct_choice);
                    }
                    
                }else{
                    printf(" Invalid choice! Please enter a number between 1 and 3.\n");
                }
            }while(valid!=1);
            break;

        }

        case 2:{
            int vadid=0;
            int choices;
            int Pref;
            do {
                printf("\n===================SELECTION===================\n");
                printf("Enter the question difficulty you want to view:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter choice: ");
                if (scanf("%d", &choices) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }

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
                    printf("\nPlease only input the digit from 1-3\n");
                }
            } while (vadid!=1);
            int didway=0;
            do{
                printf("\n============SELECTION===========\n");
                printf("Enter 1 if stay, enter 2 if exit\n");
                printf("Please choose: ");
                if (scanf("%d", &Pref) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }
                
                if(Pref == 1){
                    loopMenu();
                    didway++;
                }else if (Pref == 2){
                    exit(1);
                    didway++;
                }else{
                    printf("Please only enter the digit 1-2\n");
                }

            }while(didway!=1);
            break;
        }

        case 3:{
            int Pref;
            addQuestiot();
            int didway=0;
            do{
                printf("\n============SELECTION===========\n");
                printf("Enter 1 to stay, enter 2 to exit\n");
                printf("Please choose: ");
                printf("\n============SELECTION===========\n");
                printf("Enter 1 if stay, enter 2 if exit\n");
                printf("Please choose: ");
                if (scanf("%d", &Pref) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }
                
                if(Pref == 1){
                    loopMenu();
                    didway++;
                }else if (Pref == 2){
                    exit(1);
                    didway++;
                }else{
                    printf("Please enter only the digit 1 or 2\n");
                }

            }while(didway!=1);
            break;

        }

        case 4:{
            int vadid=0;
            int choices;
            int Pref;
            int didway = 0;
            do {
                bool correct = false;
                printf("\n==========================DELETE-SELECTION=======================\n");
                printf("Enter the question difficulty you want to delete your questions on:\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter choice: ");
                if (scanf("%d", &choices) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }

                if(choices==1){
                    load1LQuestions();
                    printf("\nWhat questions do you want to delete?\n");
                    int size;
                    int choice;
                    size = checkLQuestions();
                    do{
                        printf("Enter your choice(1-%d): ", size);
                        if (scanf("%d", &choice) != 1) {
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF); 
                            printf("Invalid choice! Please enter a number between 1 and 3.\n");
                            continue;
                        }

                        if(choice<=size && choice>0 ){
                            DeleteQuestions(choice-1);
                            DeleteLAns(choice-1);
                            printf("Question successfully deleted!");
                            correct = true;
                        }else{
                            correct = false;
                            printf("Please only input the digit from the viewed questions!\n");
                        }
                    }while(!correct);
                    vadid = 1;
                }else if (choices ==2){
                    load1MQuestions();
                    printf("\nWhat questions do you want to delete?\n");
                    int size;
                    int choice;
                    size = checkMQuestions();
                    do{
                        printf("Enter your choice(1-%d): ", size);
                        if (scanf("%d", &choice) != 1) {
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF); 
                            printf("Invalid choice! Please enter a number between 1 and 3.\n");
                            continue;
                        }
                        if(choice<=size && choice>0 ){
                            DeleteMQuestions(choice-1);
                            DeleteMAns(choice-1);
                            printf("Question successfully deleted!");
                            correct = true;
                        }else{
                            correct = false;
                            printf("Please only input the digit from the viewed questions!\n");
                        }
                    }while(!correct);
                    vadid = 1;
                }else if (choices == 3){
                    load1HQuestions();
                    printf("\nWhat questions do you want to delete?\n");
                    int size;
                    int choice;
                    size = checkHQuestions();
                    do{
                        printf("Enter your choice(1-%d): ", size);
                        if (scanf("%d", &choice) != 1) {
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF); 
                            printf("Invalid choice! Please enter a number between 1 and 3.\n");
                            continue;
                        }
                        if(choice<=size && choice>0 ){
                            DeleteHQuestions(choice-1);
                            DeleteHAns(choice-1);
                            printf("Question successfully deleted!");
                            correct = true;
                        }else{
                            correct = false;
                            printf("Please only input the digit from the viewed questions!\n");
                        }
                    }while(!correct);
                    vadid = 1;
                }else{
                    vadid = 0;
                    printf("Please only input the digit from 1-3\n");
                }
            } while (vadid!=1);
            do{
                printf("\n============SELECTION===========\n");
                printf("Enter 1 to stay, enter 2 to exit\n");
                printf("Please choose: ");
                if (scanf("%d", &Pref) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }
                if(Pref == 1){
                    loopMenu();
                    didway++;
                }else if (Pref == 2){
                    exit(1);
                    didway++;
                }else{
                    printf("Please enter only the digit 1 or 2\n");
                }

            }while(didway!=1);
            break;

        }

        case 5:{

            int vadid=0;
            int choices;
            int Pref;
            do {
                printf("\n===================SCOREBOARD SELECTION=====================\n");
                printf("enter the question difficulty you want to view your scoreboard\n");
                printf("1. Easy\n");
                printf("2. Medium\n");
                printf("3. Hard\n");
                printf("Enter choice: ");
                if (scanf("%d", &choices) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }

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
                printf("Please choose: ");
                if (scanf("%d", &Pref) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); 
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    continue;
                }
                
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
    int choice;
    displayMenu();
    choice = getchoice();
    handleChoice(choice);
}

