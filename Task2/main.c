#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//defines maximum length of a word and maximum wrong tries user has before losing a game
#define MAX_LENGTH 20
#define MAX_TRIES 7

void start();
void game();
void select_word(char word[MAX_LENGTH]);
bool draw_lines(char word[MAX_LENGTH], int word_length, char guesses[MAX_LENGTH], bool* winner, int* lives_used, char* current_guess);
void print_guesses(char guesses[MAX_LENGTH]);
void draw_figure(int lives_used);

int main(){
   start();
}

//function which prints welcome message and starts the game
void start(){
    printf("\n============================\nPozdravljeni v igri VISLICE!\n============================\n");
    game();
}

//main game function
void game(){
    int lives_used = -1;
    bool winner = false; //stores a boolean whether you have won or not
    char word[MAX_LENGTH]; //stores the word choosen by function select_word
    char guesses[MAX_LENGTH] = "\0"; //stores all user guesses so far

    int word_length = 0;
    char current_guess;
    select_word(word);

    //counts the word length
    for(int i = 0; word[i] != '\0'; i++){
        word_length++;
    }

    //main game loop which runs until something breaks it
    while(true){
        //sets current guess to last guess to print stuff
        for(int i = 0; i < guesses[i] != '\0'; i++){
            current_guess = guesses[i];
        }

        //checks if all letters are found, if found, sets winner to true and exits while loop immediately
        if(draw_lines(word, word_length, guesses, &winner, &lives_used, &current_guess)){
            winner = true;
            break; 
        }
        
        //checks once again if the user has used more tries than available
        if(lives_used >= MAX_TRIES){
            winner = false;
            break;
        }
        draw_figure(lives_used);
        print_guesses(guesses);

        //prints a message saying how many tries are left 
        printf("Imas se %i poskusov\n", MAX_TRIES - lives_used);
        
        current_guess = ' ';

        //prompts a user to enter a character and checks if input is good
        do {
            printf("VNESI CRKO: ");
            scanf(" %c", &current_guess);
            fflush(stdin);
        } while((int)current_guess < 97 || (int)current_guess > 122);

        //creates a string from char, to add current guess to list(string) of all guesses user has entered
        char temp[2];
        temp[0] = current_guess;
        temp[1] = '\0';
        strcat(guesses, temp);
        //printf("\n");
    }

    if(winner){
        printf("\n===========================\nCONGRATULATIONS! YOU WON :)\n===========================\n\n");
    }else{
        printf("\n====================================\nYou ran out of guesses. You lose :(\nThe word was: %s\n====================================\n\n", word);
    }
}

//function which selects a word from words available randomly
void select_word(char word[MAX_LENGTH]){
    srand(time(NULL));

    //number of words avalable
    const int WORD_COUNT = 5;
    //Array with words available to the program
    char besede[][20] = 
    {
        "banana",
        "ananas",
        "lubenica",
        "jabolko",
        "hruska"
    };
    //gets random number and does modus to get remainder and chooses word on the position of remainder in array
    int random = rand() % WORD_COUNT;

    //copies selected word to char array in game function to work with it
    strcpy(word, besede[random]);
}


//function that checks one character at a time if the user have guessed it or not (if not it prints "_", if guessed it prints a character)
bool draw_lines(char word[MAX_LENGTH], int word_length, char guesses[MAX_LENGTH], bool* winner, int* lives_used, char* current_guess){
    int counter = 0;
    bool correct_attempt = false;
    printf("BESEDA: ");
    for(int i = 0; i < word_length; i++){ // checks each letter in a word
        bool found_correct = false;
        for(int j = 0; guesses[j] != '\0'; j++){ //checks each guess
            if( (int) word[i] == (int)guesses[j]){
                printf("%c", word[i]);
                counter = counter + 1;
                found_correct = true;
            }
        }
        //if character of word and guess are the same it prints the char itself, rather than the "_"
        if((int)word[i] == (int)*current_guess) {
            correct_attempt = true;
        }
        //prints "_" if
        if(!found_correct) {
            printf("_");
        }
    }
    printf("\n");

    //checks the counter if all of the characters in a word are guessed, if so it sets winner to true
    if(counter == word_length){
        return true;
    }
    //if user failed to enter a correct character it decreases a number of lives left
    if(!correct_attempt){
        *lives_used += 1;
    }
    return false;
}

//function which prints the user's guesses
void print_guesses(char guesses[MAX_LENGTH]){
    printf("POSKUSENE CRKE: ");
    for(int i = 0; guesses[i] != '\0'; i++){
        //if statement just for correct printing of guesses and ","
        if(i == 0){
            printf("%c", guesses[0]);
        }else{
            printf(", %c", guesses[i]);
        }
    }
    printf("\n");
}

//function which draws a picture, regarding to the number of guesses/lives used
void draw_figure(int lives_used){
    if(lives_used == 1){
        printf("===================\n\n\n\n  |\n / \\\n===================\n");
    }else if(lives_used == 2){
        printf("===================\n\n  |\n  |\n  |\n  |\n / \\\n===================\n");
    }else if(lives_used == 3){
        printf("===================\n   _ _ _\n  |/\n  |\n  |\n  |\n / \\\n===================\n");
    }else if(lives_used == 4){
        printf("===================\n   _ _ _ _ _ _\n  |/         |\n  |\n  |\n  |\n / \\\n===================\n");
    }else if(lives_used == 5){
        printf("===================\n   _ _ _ _ _ _\n  |/         |\n  |          O\n  |\n  |\n / \\\n===================\n");
    }else if(lives_used == 6){
        printf("===================\n   _ _ _ _ _ _\n  |/         |\n  |          O\n  |         /|\\\n  |\n / \\\n===================\n");
    }else if(lives_used == 7){
        printf("===================\n   _ _ _ _ _ _\n  |/         |\n  |          O\n  |         /|\\\n  |         / \\\n / \\\n===================\n");
    }
}
