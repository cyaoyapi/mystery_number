/*
===============================================================================
    In this C-language game, the player is asked to guess a mystery number
    generated by the computer.

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    This function display the menu for the choosing of
    the game's level.
    It return the maximum for the mystery number.
*/

int game_level_menu(){
    int chosen_level = 0, max = 0;
    int bad_choice = 1;
    while(bad_choice){
        printf("=================Choix du niveau de difficulté ===========\n");
        printf("=== 1 : Entre 1 et 100 ;                               ===\n");
        printf("=== 2 : Entre 1 et 1000 ;                              ===\n");
        printf("=== 3 : Entre 1 et 10000 ;                             ===\n");
        printf("==========================================================\n");
        scanf("%d",&chosen_level);
        switch(chosen_level){
            case 1 :
                max = 100;
                bad_choice = 0;
                break;
            case 2 :
                max = 1000;
                bad_choice = 0;
                break;
            case 3 :
                max = 1000;
                bad_choice = 0;
                break;
            default :
                printf("Mauvais choix, reprenez !\n") ;
                break;
        }
    }
    return max ;
}


/*
    This is main function. The program start here.
*/
int main(int argc, char *argv[])
{
    int continue_gaming = 1;
    while(continue_gaming){
        /*
            Mystery number randomly generation
        */
        const int MIN = 1;
        int max = game_level_menu() ;
        srand(time(NULL));
        int mystery_number = (rand() % (max - MIN + 1)) + MIN;

        int gamer_chosen_number = 0, hit_counter =0;


        int continue_game_part = 1 ;
        do{
            printf("Quel est le nombre mystère ? (Entre %d et %d)\n", MIN, max);
            scanf("%d", &gamer_chosen_number);
            if(gamer_chosen_number < MIN || gamer_chosen_number > max){
                printf("Erreur de saisi : entrez un entier entre %d et %d\n", MIN, max);
                continue;
            }
            else if(gamer_chosen_number > mystery_number){
                printf("C'est moins\n");
            }
            else if(gamer_chosen_number < mystery_number){
                printf("C'est plus\n");
            }
            else{
                continue_game_part = 0; // game's part over
            }
            hit_counter++ ;
        }while(continue_game_part) ;
        printf("Bravo, vous avez trouvez le nombre mystère après %d essai(s)!\n",hit_counter);

        /*
            Asking the gamer if he desire to continue
        */
        printf("Voulez-vous faire une autre partie de jeu ? \n");
        do{
            printf("Taper 1 pour OUI et 0 pour NON\n");
            scanf("%d",&continue_gaming);

        }while(continue_gaming != 1 && continue_gaming != 0) ;
        if(!continue_gaming){
            printf("Aurevoir !");
        }
    }
    return 0;
}
