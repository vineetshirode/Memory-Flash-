#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



// Macro Define (ANSI Color Codes)
#define RESET   "\033[0m"
#define RED     "\033[1;41m"
#define GREEN   "\033[1;42m"
#define YELLOW  "\033[1;43m"
#define BLUE    "\033[1;44m"

// FUNCTION DEFINITIONS


// clear terminal screen function
void clearScreen() {
    system("clear");
}






// return colour based on numbers using switch case
void displayColor(int color) {
    clearScreen();
    printf("\n\n\n");
    
    switch(color) {
        case 1:
            printf(RED);
            printf("                        \n");
            printf("          RED           \n");
            printf("                        \n");
            printf(RESET);
            break;
        case 2:
            printf(GREEN);
            printf("                        \n");
            printf("         GREEN          \n");
            printf("                        \n");
            printf(RESET);
            break;
        case 3:
            printf(BLUE);
            printf("                        \n");
            printf("         BLUE           \n");
            printf("                        \n");
            printf(RESET);
            break;
        case 4:
            printf(YELLOW);
            printf("                        \n");
            printf("        YELLOW          \n");
            printf("                        \n");
            printf(RESET);
            break;
    }
    
    fflush(stdout);
    sleep(2);
}





// main function

int main() {
    int correctSequence[100];
    int playerInput[100];
    int level = 0;
    
    srand(time(0)); // seed random number generator
    
    clearScreen(); // clear terminal 

    // GAME STARTS

    printf("\n MEMORY FLASH GAME \n");
    printf("1=RED, 2=GREEN, 3=BLUE, 4=YELLOW\n");
    printf("\nPress Enter to start...");
    getchar();
    
    while(1) {
        level++;  // Level increment (in line 68 --> set to 0)
        
        clearScreen(); // clear screen so that previous colors are not visible

        printf("\n ROUND %d \n", level);

        sleep(1);// 1 sec pause
        
        // generate new color
        int randomNum = rand() % 4 + 1; 
        // store new color in correctSequence variable 
        correctSequence[level-1] = randomNum; // here we have the correct sequence array
        



        // Show only the new color
        clearScreen();
        printf("\n New color\n");
        sleep(1);
        // Display colour based on the random seed was generated
        displayColor(correctSequence[level-1]);



        
        // Get player input
        clearScreen();
        printf("\n Enter the FULL sequence:\n");
        printf("(You need %d colors)\n\n", level);//instructs player to 
        
        for(int i = 0; i < level; i++) {  // i = loop counter
            printf("Color %d: ", i+1);   // color 1: {example enters '3'}
            scanf("%d", &playerInput[i]); // store '3' in playerInput array at index i {where index i is 0}
            // loop will continue until the it reaches the *level*
            // now we have all the player inputs
            // exit
        }
        
        // Verify
        int correct = 1;
        for(int i = 0; i < level; i++) { //Check each color one by one
            if(playerInput[i] != correctSequence[i]) { // if wrong color during match enter the below if condition 
                correct = 0; //set to false
                break; // if false exit the loop 
            }
        }
        
        if(correct == 0) {
            printf("\n wrong game end\n");
            printf("total score: %d\n", level - 1);
            break;
        }
        
        printf("\ncorrect\n");
        sleep(1);
    }
    
    return 0;
}