#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // To use the bool type
#include <time.h> // To use the time() function
#include <ctype.h> // For isdigit()

int main(void)
{
    // Seed the random number generator (so that it's random each time program is run)
    srand(time(NULL));

    // Generate a random number and assign it to a variable
    int r = rand() % 101;

    // Print game rules
    printf("This is a number guessing game. You have to guess a number between 0 - 100. There will be hints to guide you. Good luck!\n");

    // Prompt for user input using loop
    int number;
    int attempts = 0;
    bool guess = false;
    
    while (guess != true)
    {
        printf("What is your guess: ");
        scanf("%i", &number);
        attempts++;

        // Error handling
        if (!isdigit(number))
        {
            printf("Please enter a valid number.\n");
            return 1;
        }
        if (number < 0 || number > 100)
        {
            printf("Please enter a valid number.\n");
            return 2;
        }

        // Print results
        if (number == r)
        {
            printf("You guessed the number %i correctly! You did it in %i attempts.\n", r, attempts);
            guess = true;
            return 0;
        }
        else if (number < r)
        {
            printf("Your guess %i is lower than the number. Guess again!\n", number);
        }
        else
        {
            printf("Your guess %i is higher than the number. Guess again!\n", number);
        }
    }
}