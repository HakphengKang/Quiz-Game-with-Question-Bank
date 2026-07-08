#include "kdethgay.h"
#include <stdio.h>
#include "navigation.h"
#include "kdethgay.h"
#include "ans_display.h"
#include "addquestiot.h"
#include "score_calc.h"

int main(){
    int choice;
    displayMenu();
    choice = getchoice();
    handleChoice(choice);
}