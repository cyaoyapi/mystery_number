#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /*
        Mystery number randomly generation
    */
    const int MAX = 100, MIN = 1;
    srand(time(NULL));
    int mystery_number = (rand() % (MAX - MIN + 1)) + MIN;

    int gamer_choice = 0;


    /*
        Game over
    */
    int cpt = 1 ;
    while(cpt){
        printf("Quel est le nombre mystère ? (Entre %d et %d)\n", MIN, MAX);
        scanf("%d", &gamer_choice);
        if(gamer_choice < MIN || gamer_choice > MAX){
            printf("Erreur de saisi : entrez un entier entre %d et %d\n", MIN, MAX);
        }
        else if(gamer_choice > mystery_number){
            printf("C'est moins\n");
        }
        else if(gamer_choice < mystery_number){
            printf("C'est plus\n");
        }
        else{
            cpt = 0;
        }
    }
    printf("Bravo, vous avez trouvez le nombre mystère !\n");

    return 0;
}
