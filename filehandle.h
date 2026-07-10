#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

 void loadLQuestions(int questions);
 void loadHQuestions(int questions);
 void loadMQuestions(int questions);
 void saveScore(char arr[], int score);
 void addQuestions(char questions[]);
 void addMQuestions(char questions[]);
 void addHQuestions(char questions[]);
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
void DeleteLAns(int answers);
void DeleteMAns(int answers);
void DeleteHAns(int answers);
void load1HQuestions();
void load1MQuestions();
void load1LQuestions();
void DeleteMQuestions(int questions);
void DeleteHQuestions(int questions);
 #endif
