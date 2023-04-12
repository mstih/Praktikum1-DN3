#include <stdio.h>
#include <stdlib.h>

//constant with following floors allocated: P, 1, 2, 3, 4, 5.
const char FLOORS[6] = {80, 49, 50, 51, 52, 53};

//variables for functions
int current_floor;
char choice;

//functions used
void start();
void destination();
void is_choice_valid();
void move();
void close();


int main(){
    start();
    printf("TRENUTNO NADSTROPJE: %c\n", FLOORS[current_floor]);
    destination();

    //calls function to move floor until the final floor is reached
    while(FLOORS[current_floor] != choice){ 
        move();
    }
}

//function start prints welcome message, available floors and sets the current floor to P
void start(){
    current_floor = 0;
    printf("Pozdravljeni v simulatorju dvigala!\n");
    printf("Nadstropja v tem dvigalu: P, 1, 2, 3, 4, 5\n");
}

//function destination asks user to input a final floor and starts is_choice_valid to check if user has entered a floor that exists
void destination(){
    printf("Izberite nadstropje: ");
    gets(&choice);
    is_choice_valid();
}

//function is_choice_valid checks if the floor user has entered exists and runs destination function again if the floor does not exists
void is_choice_valid(){
    int counter = 0;
    for(int i = 1; i < 6; i++){ //checks each floor
        if(choice == (int)FLOORS[i]){
            counter++;
        }
    }
    if (counter != 1){
        printf("Napaka pri vnosu! Poskusite se enkrat.\n"); //prints error if floor not found and asks user for input once again
        destination();
    }
}

//function move prompts user to tell the elevator whether to move up, down or exit the elevator, accordingly to the floor currently located at
void move(){
    //variable which stores user input
    char action; 

    //prints out current floor
    printf("TRENUTNO NADSTROPJE: %c\n", FLOORS[current_floor]);

    //checks current location and gives options accordingly to the current floor
    if(current_floor == FLOORS[4]){ //CASE: TOP FLOOR
        printf("1: Dol\n2:Izstop iz dvigala\n");
        printf("Izberite premik: ");
        gets(&action);
        if(action == '1'){
            //moves elevator one floor down
            current_floor--;
        }else if(action == '2'){
            //calls function which exits the elevator
            close(); 
        }else{
            //prints error and prompts user to enter it again
            printf("Napaka! Poskusite se enkrat!\n"); 
            move();
        }
    }else if(current_floor == FLOORS[0]){ //CASE: BOTTOM FLOOR
        printf("1: Gor\n2: Izstop iz dvigala\n");
        printf("Izberite premik: ");
        gets(&action);
        if(action == '1'){
            //moves elevator one floor up
            current_floor++; 
        }else if(action == '2'){
            //calls function which exits the elevator
            close(); 
        }else{ 
            //prints error and prompts user to enter it again
            printf("Napaka! Poskusite se enkrat!\n"); 
            move();
        }
    }else{ //CASE: ANY OTHER FLOOR IN BETWEEN
        printf("1: Gor\n2: Dol\n3: Izstop iz dvigala\n");
        printf("Izberite premik: ");
        gets(&action);
        if(action == '1'){
            //moves elevator one floor up
            current_floor++;
        }else if(action == '2'){
            //moves elevator one floor down
            current_floor--;
        }else if(action == '3'){
            //calls function which exits the elevator
            close();
        }else{
            //prints error and prompts user to enter it again
            printf("Napaka! Poskusite se enkrat!\n");
            move();
        }
    }
    //prints a line to seperate each move prompt
    printf("--------------------\n");
}

//a function which prints a goodbye message and exits the program
void close(){
    printf("Prispeli ste v %c nadstropje! Nasvidenje!\n", FLOORS[current_floor]);
    exit(0);
}