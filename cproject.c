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
    
    char playAgain;
    int highScore = 0; // Variable to store the highest score

    // Seed random number generator ONCE at the start
    srand(time(0)); 

    do {
        int correctSequence[100];
        int playerInput[100];
        int level = 0;
        
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
            
            // Flag to check for invalid input
            int invalidInput = 0;

            for(int i = 0; i < level; i++) {
                printf("Color %d: ", i+1);
                scanf("%d", &playerInput[i]);

                // VALIDATION: Check if input is outside 1-4
                if(playerInput[i] < 1 || playerInput[i] > 4) {
                    invalidInput = 1;
                    break; // Break the input loop
                }
            }

            // Handle Invalid Input
            if(invalidInput) {
                int currentScore = level - 1;
                // Update High Score
                if(currentScore > highScore) {
                    highScore = currentScore;
                }

                printf("\n--------------------------------\n");
                printf(" INVALID INPUT! \n");
                printf("Please enter numbers 1 to 4 only.\n");
                printf(" GAME OVER.\n");
                printf("Your Score: %d\n", currentScore);
                printf("Highest Score: %d\n", highScore); // Show High Score
                printf("--------------------------------\n");
                break; // Break the game loop
            }
            
            // Verify Correctness
            int correct = 1;
            for(int i = 0; i < level; i++) {
                if(playerInput[i] != correctSequence[i]) {
                    correct = 0;
                    break;
                }
            }
            
            if(correct == 0) {
                int currentScore = level - 1;
                // Update High Score
                if(currentScore > highScore) {
                    highScore = currentScore;
                }

                printf("\n--------------------------------\n");
                printf(" WRONG SEQUENCE! \n");
                printf(" GAME OVER.\n");
                printf("Your Score: %d\n", currentScore);
                printf("Highest Score: %d\n", highScore); // Show High Score
                printf("--------------------------------\n");
                break;
            }
            
            printf("\ncorrect\n");
            sleep(1);
        }

        // Ask to replay
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);   // space before %c clears buffer

        getchar(); // consume leftover newline so next game starts cleanly

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");
    printf("Final Highest Score: %d\n", highScore);

    return 0;
}
