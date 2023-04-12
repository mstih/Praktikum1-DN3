#include <stdio.h>

//array defines all floors the elevator can access
const char floors[] = {'P', '1', '2', '3', '4', '5'}; 

void start();
void move();
int check_floor(char floors[], char choice);
void choose_floor(char* floors[]);

//variable for the current floor
char current_floor;

int main(){
    start();
}

void start(){
    current_floor = 'P'; //sets current floor to ground to start game
    printf("Pozdravljeni v simulatorju dvigala!\n");
    move();
}


void move(){
    printf("Trenutno se nahajate v nadstropju: %c\n", current_floor);
    choose_floor(floors);
}


void choose_floor(char* floors[]){
    char choice;
    printf("Izberite nadstropje: ");
    scanf("%c", &choice);
    if(check_floor(floors, (char) choice)){
        printf("Prispeli ste v nadstropje: %c", choice);
    }else{
        printf("Nepravilen vnos nadstropja!\n");
        choose_floor(floors);
    }
    
}

//checks if floor even exists and if the user hasn't entered the current floor
int check_floor(char floors[], char choice){
    for(int i = 0; i < 6; i++){
        if(floors[i] == choice && current_floor != choice){
            return 1;
        }
    }
    return 0;
}