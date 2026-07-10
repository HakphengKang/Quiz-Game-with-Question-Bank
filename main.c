#include "filehandle.h"
#include <stdio.h>
#include "navigation.h"
#include "filehandle.h"
#include "ans_display.h"
#include "addquestiot.h"
#include "score_calc.h"

int main(){
    int choice;
    displayMenu();
    choice = getchoice();
    handleChoice(choice);
}