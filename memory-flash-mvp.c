#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define RESET   "\033[0m"
#define RED     "\033[1;41m"
#define GREEN   "\033[1;42m"
#define YELLOW  "\033[1;43m"
#define BLUE    "\033[1;44m"


void clearScreen() {
    system("clear");
}



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





int main() {
    int correctSequence[100];
    int playerInput[100];
    int level = 0;
    
    srand(time(0)); 
    
    clearScreen(); 


    printf("\n MEMORY FLASH GAME \n");
    printf("1=RED, 2=GREEN, 3=BLUE, 4=YELLOW\n");
    printf("\nPress Enter to start...");
    getchar();
    
    while(1) {
        level++;  
        
        clearScreen(); 

        printf("\n ROUND %d \n", level);

        sleep(1);
        
        int randomNum = rand() % 4 + 1; 
        
        correctSequence[level-1] = randomNum; 

        
        clearScreen();
        printf("\n New color\n");
        sleep(1);
        displayColor(correctSequence[level-1]);

    
        clearScreen();
        printf("\n Enter the FULL sequence:\n");
        printf("(You need %d colors)\n\n", level);
        

        for(int i = 0; i < level; i++) {  
            printf("Color %d: ", i+1);   
            scanf("%d", &playerInput[i]); 
        }
        
        
        int correct = 1;
        for(int i = 0; i < level; i++) { 
            if(playerInput[i] != correctSequence[i]) {  
                correct = 0; 
                break; 
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