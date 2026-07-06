#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "kdethgay.h"
#include "addquestiot.h"
void addQuestiot(){
    char questions[100];
    char option[100];
    char options[500] = "";
    char line[120];
    int length;

    printf("Enter ur desire question: ");
    fgets(questions, sizeof(questions), stdin);

    length = strlen(questions);
    if (length == 0 || questions[length - 1] != '\n') {
        printf("invalid or error\n");
        
    } else {
        questions[length - 1] = '\0'; 
    }

    length = strlen(questions);
    if (length == 0 || questions[length - 1] != '?') {
        printf("invalid or error\n");
    }

    strcpy(options, "\n");

    for(int i = 0; i < 4; i++){
        printf("Enter option %c: ", i + 65);
        fgets(option, sizeof(option), stdin);
        sprintf(line, "%c. %s", i + 65, option);
        strcat(options, line);
    }
    strcat(questions, options);
    int difficulty;

printf("\nChoose Difficulty\n");
printf("1. Easy\n");
printf("2. Medium\n");
printf("3. Hard\n");
printf("Choice: ");
scanf("%d", &difficulty);
getchar();  // important to clear newline

if(difficulty == 1)
{
    addQuestions(questions);
}
else if(difficulty == 2)
{
    addMQuestions(questions);
}
else if(difficulty == 3)
{
    addHQuestions(questions);
}
else
{
    printf("Invalid difficulty!\n");
}
}
int main(){
    addQuestiot();
}



