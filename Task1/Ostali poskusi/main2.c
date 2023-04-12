#include <stdio.h>
#include <stdlib.h>

const char FLOORS[6] = {'P', '1', '2', '3', '4', '5'};

void start(int* current_floor_index, char* current_floor, char* choice);
void choose(char* choice);
void move(int* current_floor_index, char* current_floor, char* choice);
void is_choice_valid(char* choice);
void close(char* current_floor);


int main(){
    int current_floor_index;
    char current_floor;
    char choice;
    start(&current_floor_index, &current_floor, &choice);
}

void start(int* current_floor_index, char* current_floor, char* choice){
    *current_floor_index = 0;
    *current_floor = FLOORS[*current_floor_index];
    printf("Pozdravljeni v simulatorju dvigala!\n");
    printf("Trenutno se nahajate v nadstropju: %c\n", *current_floor);
    choose(&choice);

    while(*current_floor != *choice){
        move(&current_floor_index, &current_floor, &choice);
    }
    
}

void move(int* current_floor_index, char* current_floor, char* choice){
    char action;
    printf("Nahajate se v nadstropju: %c\n", *current_floor); 
    if(*current_floor == '5'){
        printf("0: Dol\n1: Izstop iz dvigala\n");
        printf("Izberite premik:\n");
        scanf("%c", &action);
        if(action == '0'){
            *current_floor_index--;
            *current_floor = FLOORS[*current_floor_index];
        }else if(action == '1'){
            close(&current_floor);
        }else{
            printf("Napaka! Poskusite se enkrat!\n");
            move(&current_floor_index, &current_floor, &choice);
        }
    }else if(*current_floor == 'P'){
        printf("0: Gor\n1: Izstop iz dvigala\n");
        printf("Izberite premik:\n");
        scanf("%c", action);
        if(action == '0'){
            *current_floor_index++;
            *current_floor = FLOORS[*current_floor_index];
        }else if(action == '1'){
            close(&current_floor);
        }else{
            printf("Napaka pri vnosu! Poskusite se enkrat!\n");
            move(&current_floor_index, &current_floor, &choice);
        }
    }else{
        printf("0: Gor\n1: Dol\n2: Izstop iz dvigala\n");
        printf("Izberite premik:\n");
        scanf("%c", action);
        if(action == '0'){
            *current_floor_index++;
            *current_floor = FLOORS[*current_floor_index];
        }else if(action == '1'){
            *current_floor_index--;
            *current_floor = FLOORS[*current_floor_index];
        }else if(action == '2'){
            close(&current_floor);
        }else{
            printf("Napaka pri vnosu! Poskusite se enkrat!\n");
            move(&current_floor_index, &current_floor, &choice);
        }
    }
}

void choose(char* choice){
    printf("Izberite nadstropje (1, 2, 3, 4, 5): ");
    scanf("%c", &choice);
    is_choice_valid(&choice);
}

void is_choice_valid(char* choice){
    for(int i = 0; i < 6; i++){
        printf("Nadstropje: %c || Choice: %c\n", FLOORS[i], *choice);
        if((char)*choice == FLOORS[i] && *choice != 'P'){
            printf("Sta enaka");
        }
    }
    choose(&choice);
}

void close(char* current_floor){
    printf("Izstopili ste iz dvigala v %c nadstropju! Nasvidenje!", *current_floor);
    exit(0);
}