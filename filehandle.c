#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int line_bound[10] = {1,6,11,16,21,26,31,36,41,46};
    int line_boundr[10] = {5,10,15,20,25,30,35,40,45,50};
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
int main(){
    loadQuestions(1);
    loadQuestions(2);
}