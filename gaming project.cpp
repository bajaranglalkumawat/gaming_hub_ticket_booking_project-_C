#include <stdio.h>
 #include <stdlib.h>
  #include <string.h>
   #include <time.h>

// list of fun.
  void displayWelcomeMessage();
   void logMessage(const char *message);
     void bookTicket();
      void snakeGame();
       void hangmanGame();
        void ticTacToe();
         void rockPaperScissors();

int main() {
    int choice;

    displayWelcomeMessage();

    while (1) {
               printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
             printf("Choose an option:\n");
             printf("1. Book Ticket\n");
             printf("2. Play Snake (Simple Concept)\n");
             printf("3. Play Hangman (2 Players)\n");
            printf("4. Play Tic Tac Toe (2 Players)\n");
            printf("5. Play Rock-Paper-Scissors (2 Players)\n");
              printf("6. Exit\n");
               printf("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                logMessage("Snake game started.");
                snakeGame();
                break;
            case 3:
                logMessage("Hangman game started.");
                hangmanGame();
                break;
            case 4:
                logMessage("Tic Tac Toe game started.");
                ticTacToe();
                break;
            case 5:
                logMessage("Rock-Paper-Scissors game started.");
                rockPaperScissors();
                break;
            case 6:
                logMessage("Exited the Gaming Hub.");
                printf("\nThank you for visiting the Gaming Hub! Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
                                                                        }
                                                                      }
    return 0;
                                                                      }

// file name where store all information of user 
void displayWelcomeMessage() {
    FILE *file = fopen("game_log.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
                                                                       }

    fprintf(file, "\n=<*>==<*>==<*>==<*>==<*>==<*>==<>\n");
    fprintf(file, " Welcome to the Gaming Hub!  \n");
    fprintf(file, "=<*>==<*>==<*>==<*>==<*>==<*>==<>\n");
    fclose(file);

    printf("\t\t\t\t=<*>==<*>==<*>==<*>==<*>==<*>==<>\n");
    printf("\n\t\t\t\t Welcome to the Gaming Hub!\n");
    printf("\t\t\t\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n");
    printf("\nThank you for visiting the Gaming Hub.\nEnjoy your games and have fun!\n");
                                                         }


void logMessage(const char *message) {
    FILE *file = fopen("game_log.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
                                                                             }
    fprintf(file, "%s\n", message);
    fclose(file);
                                                                              }

//  thise fun. is used for ticket booking of gaming hum  
void bookTicket() {
    char name[50]; 
	 char email[50] ; 
	  char game[20];
       int age; 
	    int  ticketID;

      printf("\nEnter your name: ");
         scanf(" %s", name);
           printf("Enter your age: ");
            scanf("%d", &age);
         printf("Enter your email: ");
         scanf(" %s", email);
         printf("Choose a game (Snake, Hangman, Tic Tac Toe, Rock-Paper-Scissors): ");
    scanf(" %s", game);

    srand(time(0));
    ticketID = rand() % 10000 + 1;  

    FILE *file = fopen("game_log.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
                                                                             }

       fprintf(file, "Ticket ID: %d\nName: %s\nAge: %d\nEmail: %s\nGame: %s\n\n", ticketID, name, age, email, game);
       fclose(file);

     printf("\nThank you for booking, %s!\n", name);
      printf("Your Ticket ID is: %d\n", ticketID);
       printf("Enjoy your game: %s\n", game);

    logMessage("Ticket booked.");
                                                             }

//  1.code of snake game 
void snakeGame() {
    int player1_pos = 0, player2_pos = 0;
    int dice;
    char roll;

    printf("\t\t\t\tWelcome to Snake Game (Dice-based Simulation)!\n");
    printf("First player to reach 50 wins!\n");

    while (player1_pos < 50 && player2_pos < 50) {
        printf("\nPlayer 1, press 'r' to roll the dice: ");
        scanf(" %c", &roll);
        if (roll == 'r') {
            dice = (rand() % 6) + 1;
            printf("Player 1 rolled: %d\n", dice);
            player1_pos += dice;
            printf("Player 1 position: %d\n", player1_pos);
                                                              }

        if (player1_pos >= 50) {
            printf("\nPlayer 1 wins the Snake game!\n");
            break;
                                                            }

        printf("Player 2, press 'r' to roll the dice: ");
        scanf(" %c", &roll);
        if (roll == 'r') {
            dice = (rand() % 6) + 1;
            printf("Player 2 rolled: %d\n", dice);
            player2_pos += dice;
            printf("Player 2 position: %d\n", player2_pos);
                                                             }

        if (player2_pos >= 50) {
            printf("\nPlayer 2 wins the Snake game!\n");
            break;
                                                             }
                                                             }

    logMessage("Snake game ended.");
                                                            }

// 2. code of hangman 
void hangmanGame() {
    char word[100], guess;
    int attempts = 6;
    char guessedWord[100];
    int wordLength, correctGuesses = 0;

    printf("Player 1, enter a word for Player 2 to guess: ");
    scanf("%s", word);
    system("clear || cls");

    wordLength = strlen(word);
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
                                                         }
    guessedWord[wordLength] = '\0';

    printf("Player 2, start guessing the word!\n");
    while (attempts > 0 && correctGuesses < wordLength) {
        printf("\nCurrent word: %s\n", guessedWord);
        printf("Attempts left: %d\n", attempts);
        printf("Enter your guess: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && guessedWord[i] == '_') {
                guessedWord[i] = guess;
                correctGuesses++;
                found = 1;
                                                    }
                                                   }

        if (!found) {
            attempts--;
            printf("Incorrect guess!\n");
        } else {
            printf("Correct guess!\n");
                                                     }
                                                     }

    if (correctGuesses == wordLength) {
        printf("\nCongratulations Player 2! You guessed the word: %s\n", word);
    } else {
        printf("\nGame Over! The word was: %s\n", word);
                                                      }

    logMessage("Hangman game ended.");
                                                         }

// 3. code of tic tac toe 

void ticTacToe() {
    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
    int player = 1, choice;
    char mark;
    int moves = 0, win = 0;

    printf("\t\t\t\tWelcome to Tic Tac Toe (2 Players)!\n");

    while (moves < 9 && !win) {
        printf("\n %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

        printf("\nPlayer %d, enter a number to place your mark: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
            moves++;
            player = (player % 2) + 1;

            // Check win conditions
            for (int i = 0; i < 3; i++) {
                if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                    (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                    win = 1;
                               }
                               }
  if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
(board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
  win = 1;
            }
        } else {
            printf("\nInvalid move! Try again.\n");
                                             }
                                               }

    if (win) {
  printf("\nPlayer %d wins the Tic Tac Toe game!\n", (player % 2) + 1);
    } else {
        printf("\nIt's a draw!\n");
                                            }

logMessage("Tic Tac Toe game ended.");
}

// 4. code of rock Paper Scissors
void rockPaperScissors() {
    char player1[20],   player2[20];
    char move1[10],   move2[10];

           printf("Enter Player 1's name: ");
         scanf("%s", player1);
    
       printf("Enter Player 2's name: ");
         scanf("%s", player2); 

        printf("%s, enter your move (rock, paper, scissors): ", player1);
        scanf("%s", move1);
    
       printf("%s, enter your move (rock, paper, scissors): ", player2);
       scanf("%s", move2);

        if (strcmp(move1, move2) == 0) {
        printf("\nIt's a draw!\n");
 } else if ((strcmp(move1, "rock") == 0 && strcmp(move2, "scissors") == 0) ||
     (strcmp(move1, "scissors") == 0 && strcmp(move2, "paper") == 0) ||
     (strcmp(move1, "paper") == 0 && strcmp(move2, "rock") == 0)) {
     printf("\n%s wins!\n", player1);
} else {
        printf("\n%s wins!\n", player2);
                              }
logMessage("Rock-Paper-Scissors game ended.");
}

