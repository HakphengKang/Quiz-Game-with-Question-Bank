#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "kdethgay.h"
#include "addquestiot.h"

char getOption()
{
    char option;

    while (1)
    {
        printf("What's the correct answer to your questions?\n");
        printf("Enter option (A-D): ");
        scanf(" %c", &option);
        getchar(); // Remove newline

        option = toupper(option);

        if (option >= 'A' && option <= 'D')
        {   
            return option;
        }

        printf("Invalid input! Please enter A, B, C, or D.\n");
    }
}

void addQuestiot(){
    char questions[100];
    char option[100];
    char options[500] = "";
    char line[120];
    int length;

    while(1)
{
    printf("Enter your desired question: ");
    fgets(questions, sizeof(questions), stdin);

    // Check if input is too long
    length = strlen(questions);

    if(length == 0 || questions[length - 1] != '\n')
    {
        printf("Input is too long! Please try again.\n");

        while(getchar() != '\n');   // Clear remaining input
        continue;
    }

    // Remove newline
    questions[length - 1] = '\0';

    length = strlen(questions);

    // Must end with '?'
    if(questions[length - 1] != '?')
    {
        printf("Question must end with '?'.\n");
        continue;
    }

    // Must have at least 3 characters before '?'
    if(length < 4)
    {
        printf("Question must contain at least 3 characters before '?'.\n");
        continue;
    }

    break;      // Valid question
}
 strcpy(options, "\n");

    for(int i = 0; i < 4; i++)
    {
        printf("Enter option %c: ", 'A' + i);
        fgets(option, sizeof(option), stdin);

        sprintf(line, "%c. %s", 'A' + i, option);
        strcat(options, line);
    }
     char selectedOption = getOption();

    printf("You selected: %c\n", selectedOption);


    // Combine question and options
    strcat(questions, options);
int difficulty;
    while(1)
{
    printf("\nChoose Difficulty\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Choice: ");

    if(scanf("%d", &difficulty) != 1)
    {
        printf("Invalid input! Enter a number.\n");

        while(getchar() != '\n');
        continue;
    }

    getchar();

    if(difficulty >= 1 && difficulty <= 3)
        break;

    printf("Invalid difficulty! Please enter 1, 2, or 3.\n");
    }

    if(difficulty == 1)
    {
        addQuestions(questions);
        addLCans(selectedOption);
        printf("Questions added successfully!\n");
    }
    else if(difficulty == 2)
    {
        addMQuestions(questions);
        addMCans(selectedOption);
        printf("Questions added successfully!\n");
    }
    else
    {
        addHQuestions(questions);
        addHCans(selectedOption);
        printf("Questions added successfully!\n");
    }
}
