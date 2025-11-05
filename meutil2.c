#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototype
void playGame(int difficultyRange, int maxAttempts);

int main() {
    // Seed the random number generator
    srand(time(0));

    int choice;
    do {
        printf("\n=== NUMBER GUESSING GAME DELUXE ===\n");
        printf("1. Easy Mode (1-50, Unlimited attempts)\n");
        printf("2. Hard Mode (1-100, 7 attempts only!)\n");
        printf("0. Exit\n");
        printf("===================================\n");
        printf("Select difficulty: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playGame(50, 0); // Easy
                break;
            case 2:
                playGame(100, 7); // Hard
                break;
            case 0:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}

// --- The Core Game Logic ---
void playGame(int difficultyRange, int maxAttempts) {
    int secretNumber = (rand() % difficultyRange) + 1;
    int guess;
    int attemptsTaken = 0;

    printf("\n>>> I have chosen a number between 1 and %d. <<<\n", difficultyRange);
    if (maxAttempts > 0) {
        printf(">>> You have %d attempts to find it! <<<\n", maxAttempts);
    }

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attemptsTaken++;

        if (guess == secretNumber) {
            printf("CONGRATULATIONS! You found it in %d attempts!\n", attemptsTaken);
        } else if (guess > secretNumber) {
            printf("Too High!\n");
        } else {
            printf("Too Low!\n");
        }

        // Game Over Logic for Hard Mode
        if (maxAttempts > 0 && attemptsTaken >= maxAttempts && guess != secretNumber) {
             printf("GAME OVER! You ran out of attempts. The number was %d.\n", secretNumber);
             break;
        }

    } while (guess != secretNumber);
}
