#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "kdethgay.h"
typedef struct{
    char name[50];
    int score;
}Player;
typedef struct{
    char questions[100];
    char options[100];
}Questions;
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
void viewMQuestions(){
    FILE *fp=NULL;
    fp = fopen("mediumQuestions.txt", "r");
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
void viewHQuestions(){
    FILE *fp=NULL;
    fp = fopen("hardQuestion.txt", "r");
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
void viewScoreboard(){
    FILE *fp=NULL;
    fp = fopen("scoreboard.txt", "r");
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
void viewHScoreboard(){
    FILE *fp=NULL;
    fp = fopen("scoreboardhard.txt", "r");
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
void viewMScoreboard(){
    FILE *fp=NULL;
    fp = fopen("scoreboardMedium.txt", "r");
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
void loadLQuestions(int questions){
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
void loadMQuestions(int questions){
    FILE *fp=NULL;
    fp = fopen("mediumQuestions.txt", "r");
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
void loadHQuestions(int questions){
    FILE *fp=NULL;
    fp = fopen("hardQuestion.txt", "r");
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
    // writing section
    FILE *fp = NULL;
    fp = fopen("scoreboard.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Player p[100];
    
    fflush(fp);
    fclose(fp);

    // reading section
    
    int count = 0;
    fp = fopen("scoreboard.txt", "r");
    if(fp==NULL){
        printf("error ");
        exit(1);
    }
    // reading the file
    rewind(fp);
    while(fscanf(fp, "%49s %d", p[count].name,&p[count].score)== 2){
        count++;
    }
    strcpy(p[count].name, arr);
    p[count].score = score;
    count++;
    // rearranging the priority
    for(int i=0; i < count ; i++){
        for(int j=i+1;j < count  ; j++){
            if (p[j].score > p[i].score){
                Player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    fclose(fp);
    fp = fopen("scoreboard.txt", "w+");
    for(int i=0; i < count;i++){
        fprintf(fp, "%d.%s %d\n", i+1,p[i].name, p[i].score);
        fflush(fp); 
    }
    fclose(fp);
    viewScoreboard();
}
void addQuestions(char questions[]){
    FILE *fp=NULL;
    fp = fopen("questions.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Questions q;
    strcpy(q.questions, questions);
    
    fprintf(fp,"%s", q.questions);
    
    fclose(fp);
}
void addMQuestions(char questions[]){
    FILE *fp=NULL;
    fp = fopen("mediumQuestions.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Questions q;
    strcpy(q.questions, questions);
    
    fprintf(fp,"%s", q.questions);
    
    fclose(fp);
}
void addHQuestions(char questions[]){
    FILE *fp=NULL;
    fp = fopen("hardQuestion.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Questions q;
    strcpy(q.questions, questions);
    
    fprintf(fp,"%s", q.questions);
    
    fclose(fp);
}
void DeleteQuestions(int questions){
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
    int line_boundr[] = {0,5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
    55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
    105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
    155, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    int num  = 0;
    int target = line_boundr[questions];
    char questionAns[256][256];
    bool target_line = true;
    while(!feof(fp)){
        fgets(questionAns[num],256,fp);
        num++;
    }
    for(int i = line_boundr[questions]; i < num;i++){
        strcpy(questionAns[i], questionAns[i+5]);
    }
    num-=5;
    fclose(fp);
    fopen("questions.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%s", questionAns[i] );
    }
    fclose(fp);
}
