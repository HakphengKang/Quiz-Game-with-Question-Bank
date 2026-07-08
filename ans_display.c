#include <stdio.h>
#include "score_calc.h"
#include <string.h>
#include <stdbool.h>
#include "kdethgay.h"

int displayQuestions(int difficulty,char c) {
    char userAnswer;
    int score;
    int size;
    bool havechar = false;
    char lowAnswers[100];
    char mediumAnswers[100];
    char hardAnswers[100];
    bool nochar = false;
    
    if(c=='0'){
        havechar = false;
        nochar = true;
    }else{
        havechar = true;
        
    }
    while(nochar){
        if(difficulty==1){
                size = checkLQuestions();
                checkLCans(lowAnswers);
                nochar = false;
            }else if(difficulty==2){
                size = checkMQuestions();
                checkMCans(mediumAnswers);
                nochar = false;
            }else{
                size = checkHQuestions();
                size = checkHCans(hardAnswers);
                nochar = false;
        }
    } 
    while(havechar){
        if(difficulty==1){
            size = checkLQuestions();
            addLCans(c);
            size = checkLCans(lowAnswers);
            havechar = false;
        }else if(difficulty==2){
            size = checkMQuestions();
            addMCans(c);
            size = checkLCans(mediumAnswers);
            havechar = false;
        }else{
            size = checkHQuestions();
            addHCans(c);
            size = checkLCans(hardAnswers);
            havechar = false;
        }
    }
    if(difficulty==1){
        for (int i = 0; i < size; i++){
            loadLQuestions(i);
            printf("Enter Your Answer (A-D): ");
            scanf(" %c", &userAnswer);
    
            if (userAnswer >= 'a' && userAnswer <= 'd') {
                userAnswer -= 32;
            }
            if (userAnswer == lowAnswers[i]){
                score = calScore();
            }
        }

    }else if(difficulty==2){
        for (int i = 0; i < size; i++){
            loadMQuestions(i);
            printf("Enter Your Answer (A-D): ");
            scanf(" %c", &userAnswer);
            if (userAnswer >= 'a' && userAnswer <= 'd') {
                userAnswer -= 32;
            }
    
            if (userAnswer == mediumAnswers[i]){
                score = calScore();
            }
        }

    }else{
        for (int i=0;i<size;i++){
            loadHQuestions(i);
            printf("Enter Your Answer(A-D): ");
            scanf(" %c", &userAnswer);
            if (userAnswer >= 'a' && userAnswer <= 'd') {
                userAnswer -= 32;
            }
    
            if (userAnswer == hardAnswers[i]){
                score = calScore();
            }
        }

    }
    return score;
}
int main(){
    char c;
    int score;
    printf("main: ");
    scanf("%c", &c);
    score = displayQuestions(1,c);
    printf("%d", score);
}