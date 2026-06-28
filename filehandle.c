#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    char name[50];
    int score;
}Player;
void viewQuestions(){
    FILE *fp=NULL;
    fp = fopen("questions.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    char questionAns[256];
    while(!feof(fp)){
        fgets(questionAns, sizeof(questionAns),fp);
        printf("%s", questionAns);
    }
    fclose(fp);
}
 void loadQuestions(int questions){
    FILE *fp=NULL;
    fp = fopen("questions.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int line_bound[] = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46,
    51, 56, 61, 66, 71, 76, 81, 86, 91, 96,
    101, 106, 111, 116, 121, 126, 131, 136, 141, 146,
    151, 156, 161, 166, 171, 176, 181, 186, 191, 196};
    int line_boundr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
    55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
    105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
    155, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    int num  = 1;
    int target = line_boundr[questions];
    char questionAns[256];
    bool target_line = true;
    do{
        fgets(questionAns,256,fp);
        if(num>=line_bound[questions] && num<target){
            printf("%s", questionAns);
        }
        if(num==target){
            printf("%s", questionAns);
            target_line=false;
        }
        num++;
    }while(target_line);
    fclose(fp);
}
void saveScore(char arr[], int score){
    FILE *fp = NULL;
    fp = fopen("scoreboard.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Player p[100];
    strcpy(p[0].name, arr);
    p[0].score = score;
    fprintf(fp,"%s %d\n", p[0].name, p[0].score);
    fclose(fp);

    /*
    FILE *fp = NULL;
    Player p[100];
    int count;
    fp = fopen("scoreboard.txt", "r");
    if(fp==NULL){
        printf("error ");
        exit(1);
    }
    p[count].name = arr[50];
    p[count].score = score;
    //reading the file
    while(fscanf(fp, "%49s %d", p[count].name,p[count].score)== 2){
        count++;
    }
    fclose(fp);
    fp = fopen("scoreboard.txt","a");
    */


}
