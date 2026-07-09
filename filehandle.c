#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "kdethgay.h"
#include <ctype.h>
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
    while(fgets(questionAns, sizeof(questionAns), fp) != NULL){
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
    int score=1;
    printf("\n===================SCOREBOARD=================\n");
    while(fgets(questionAns, sizeof(questionAns), fp) != NULL){
        printf("%d.%s", score,questionAns);
        score++;
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
    int score=1;
    printf("\n===================SCOREBOARD=================\n");
    while(fgets(questionAns, sizeof(questionAns), fp) != NULL){
        printf("%d.%s", score,questionAns);
        score++;
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
    int score=1;
    printf("\n===================SCOREBOARD=================\n");
    while(fgets(questionAns, sizeof(questionAns), fp) != NULL){
        printf("%d.%s", score,questionAns);
        score++;
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
    fp = fopen("scoreboard.txt", "w");
    for(int i=0; i < count;i++){
        fprintf(fp, "%s %d\n", p[i].name, p[i].score);
        fflush(fp); 
    }
    fclose(fp);
    
}
void saveMScore(char arr[], int score){
    // writing section
    FILE *fp = NULL;
    fp = fopen("scoreboardMedium.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Player p[100];
    
    fflush(fp);
    fclose(fp);

    // reading section
    
    int count = 0;
    fp = fopen("scoreboardMedium.txt", "r");
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
    fp = fopen("scoreboardMedium.txt", "w");
    for(int i=0; i < count;i++){
        fprintf(fp, "%s %d\n", p[i].name, p[i].score);
        fflush(fp); 
    }
    fclose(fp);
}
void saveHScore(char arr[], int score){
    // writing section
    FILE *fp = NULL;
    fp = fopen("scoreboardhard.txt", "a");
    if(fp == NULL){
        printf("error");
        exit(1);
    }
    Player p[100];
    
    fflush(fp);
    fclose(fp);

    // reading section
    
    int count = 0;
    fp = fopen("scoreboardhard.txt", "r");
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
    fp = fopen("scoreboardhard.txt", "w");
    for(int i=0; i < count;i++){
        fprintf(fp, "%s %d\n",p[i].name, p[i].score);
        fflush(fp); 
    }
    fclose(fp);
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
void DeleteMQuestions(int questions){
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
    fopen("mediumQuestions.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%s", questionAns[i] );
    }
    fclose(fp);
}
void DeleteHQuestions(int questions){
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
    fopen("hardQuestion.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%s", questionAns[i] );
    }
    fclose(fp);
}
int checkHQuestions(){
    FILE *fp=NULL;
    fp = fopen("hardQuestion.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int size = 0;
    int line_bound[] = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46,
    51, 56, 61, 66, 71, 76, 81, 86, 91, 96,
    101, 106, 111, 116, 121, 126, 131, 136, 141, 146,
    151, 156, 161, 166, 171, 176, 181, 186, 191, 196};
    int line_boundr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
    55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
    105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
    155, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    int num  = 1;
    char questionAns[256];
    while(!feof(fp)){
        fgets(questionAns,256,fp);
        if(num==5){
            size++;
            num = 0;
        }
        num++;
    }
    return size;
    fclose(fp);
}
int checkMQuestions(){
    FILE *fp=NULL;
    fp = fopen("mediumQuestions.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int size = 0;
    int line_bound[] = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46,
    51, 56, 61, 66, 71, 76, 81, 86, 91, 96,
    101, 106, 111, 116, 121, 126, 131, 136, 141, 146,
    151, 156, 161, 166, 171, 176, 181, 186, 191, 196};
    int line_boundr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
    55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
    105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
    155, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    int num  = 1;
    char questionAns[256];
    while(!feof(fp)){
        fgets(questionAns,256,fp);
        if(num==5){
            size++;
            num = 0;
        }
        num++;
    }
    return size;
    fclose(fp);
}
int checkLQuestions(){
    FILE *fp=NULL;
    fp = fopen("questions.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int size = 0;
    int line_bound[] = {1, 6, 11, 16, 21, 26, 31, 36, 41, 46,
    51, 56, 61, 66, 71, 76, 81, 86, 91, 96,
    101, 106, 111, 116, 121, 126, 131, 136, 141, 146,
    151, 156, 161, 166, 171, 176, 181, 186, 191, 196};
    int line_boundr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
    55, 60, 65, 70, 75, 80, 85, 90, 95, 100,
    105, 110, 115, 120, 125, 130, 135, 140, 145, 150,
    155, 160, 165, 170, 175, 180, 185, 190, 195, 200};
    int num  = 1;
    char questionAns[256];
    while(!feof(fp)){
        fgets(questionAns,256,fp);
        if(num==5){
            size++;
            num = 0;
        }
        num++;
    }
    return size;
    fclose(fp);
}
void addLCans(char c) {
    FILE *fp;

    // Append the new character
    fp = fopen("correctans.txt", "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fputc(c, fp);
    fclose(fp);

    
}
void addMCans(char c) {
    FILE *fp;

    // Append the new character
    fp = fopen("correctansM.txt", "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fputc(c, fp);
    fclose(fp);

    
}
void addHCans(char c) {
    FILE *fp;

    // Append the new character
    fp = fopen("correctansH.txt", "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fputc(c, fp);
    fclose(fp);

    
}
int checkLCans(char ansCorrect[]){
    // Read the whole file back into the array
    FILE *fp = NULL;
    fp = fopen("correctans.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(fp, " %c", &ansCorrect[count]) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}
int checkMCans(char ansCorrect[]){
    // Read the whole file back into the array
    FILE *fp = NULL;
    fp = fopen("correctansM.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(fp, " %c", &ansCorrect[count]) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}
int checkHCans(char ansCorrect[]){
    // Read the whole file back into the array
    FILE *fp = NULL;
    fp = fopen("correctansH.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(fp, " %c", &ansCorrect[count]) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}
void load1LQuestions(){
    FILE *fp = NULL;
    fp = fopen("questions.txt", "r");
    if (fp == NULL){
        printf("error");
        exit(1);
    }
    char questions[256];
    int size = 0;
    char ansquestions[256][256];
    int num = 0;
    while(fgets(questions, 256, fp )!=NULL){
        if(num == 0){
            strcpy(ansquestions[size], questions);
            size++;
        }
        num++;
        if(num==6){
            strcpy(ansquestions[size], questions);
            num = 1;
            size++;
        }
    }
    for(int i =0;i<size; i++){
        printf("%d.%s", i+1,ansquestions[i] );
    }
    fclose(fp);
}
void load1MQuestions(){
    FILE *fp = NULL;
    fp = fopen("mediumQuestions.txt", "r");
    if (fp == NULL){
        printf("error");
        exit(1);
    }
    char questions[256];
    int size = 0;
    char ansquestions[256][256];
    int num = 0;
    while(fgets(questions, 256, fp )!=NULL){
        if(num == 0){
            strcpy(ansquestions[size], questions);
            size++;
        }
        num++;
        if(num==6){
            strcpy(ansquestions[size], questions);
            num = 1;
            size++;
        }
    }
    for(int i =0;i<size; i++){
        printf("%d.%s", i+1,ansquestions[i] );
    }
    fclose(fp);
}
void load1HQuestions(){
    FILE *fp = NULL;
    fp = fopen("hardQuestion.txt", "r");
    if (fp == NULL){
        printf("error");
        exit(1);
    }
    char questions[256];
    int size = 0;
    char ansquestions[256][256];
    int num = 0;
    while(fgets(questions, 256, fp )!=NULL){
        if(num == 0){
            strcpy(ansquestions[size], questions);
            size++;
        }
        num++;
        if(num==6){
            strcpy(ansquestions[size], questions);
            num = 1;
            size++;
        }
    }
    for(int i =0;i<size; i++){
        printf("%d.%s", i+1,ansquestions[i] );
    }
    fclose(fp);
}
void DeleteLAns(int answers){
    FILE *fp=NULL;
    fp = fopen("correctans.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int num  = 0;
    char questionAns[256];
    bool target_line = true;
    char c;
    while(fscanf(fp, "%c", &c) == 1){
        if(!isspace((unsigned char)c)){
            questionAns[num] = c;
            num++;
        }
    }
    for(int i = answers; i < num-1;i++){
        questionAns[i] = questionAns[i+1];
    }
    num-=1;
    fclose(fp);
    fp = fopen("correctans.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%c ", questionAns[i] );
    }
    fclose(fp);
}
void DeleteMAns(int answers){
    FILE *fp=NULL;
    fp = fopen("correctansM.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int num  = 0;
    char questionAns[256];
    bool target_line = true;
    char c;
    while(fscanf(fp, "%c", &c) == 1){
        if(!isspace((unsigned char)c)){
            questionAns[num] = c;
            num++;
        }
    }
    for(int i = answers; i < num;i++){
        questionAns[i] = questionAns[i+1];
    }
    num-=1;
    fclose(fp);
    fp = fopen("correctansM.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%c ", questionAns[i] );
    }
    fclose(fp);
}
void DeleteHAns(int answers){
    FILE *fp=NULL;
    fp = fopen("correctansH.txt", "r");
    if(fp==NULL){
        printf("File not open");
        exit(1);
    }
    int num  = 0;
    char questionAns[256];
    bool target_line = true;
    char c;
    while(fscanf(fp, "%c", &c) == 1){
        if(!isspace((unsigned char)c)){
            questionAns[num] = c;
            num++;
        }
    }
    for(int i = answers; i < num-1;i++){
        questionAns[i] = questionAns[i+1];
    }
    num-=1;
    fclose(fp);
    fp = fopen("correctansH.txt", "w+");
    for(int i = 0; i < num;i++){
        fprintf(fp,"%c ", questionAns[i] );
    }
    fclose(fp);
}
