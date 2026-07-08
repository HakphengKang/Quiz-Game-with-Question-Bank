#ifndef QUIZ_GAY_DETH_H
#define QUIZ_GAY_DETH_H
<<<<<<< HEAD
 void loadQuestions(int questions);
 void displayQuestion(int choice);
=======
 void loadLQuestions(int questions);
 void loadHQuestions(int questions);
 void loadMQuestions(int questions);
 void saveScore(char arr[], int score);
 void addQuestions(char questions[]);
 void DeleteQuestions(int questions);
 void viewScoreboard();
 void viewQuestions();
 void viewHQuestions();
void viewMQuestions();
void viewHScoreboard();
void viewMScoreboard();
int checkHQuestions();
int checkMQuestions();
int checkLQuestions();
void saveMScore(char arr[], int score);
void saveHScore(char arr[], int score);
void addLCans(char c);
int checkLCans(char ansCorrect[]);
void addMCans(char c);
void addHCans(char c);
int checkHCans(char ansCorrect[]);
int checkMCans(char ansCorrect[]);
 #endif
