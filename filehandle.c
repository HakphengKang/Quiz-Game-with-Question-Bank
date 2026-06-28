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
        fprintf(fp, "%s %d\n", p[i].name, p[i].score);
        fflush(fp); 
    }
    fclose(fp);
}
int main(){
    char arr[50];
    int score;
    printf("enter: ");
    scanf("%s %d", arr, &score);
    saveScore(arr, score );
}
