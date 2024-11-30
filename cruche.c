#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main(){
    int c;
    etat etatInitial={0,0};etat etatfinal;
    int choix;
    int a, b;
    clock_t start, end;
    double cpu_time_used;
    printf("Entrer votre etat finale souhaitee : \n Entrer 'x':");
    scanf("%d", &a);
    printf("\n Entrer 'y':");
    scanf("%d", &b);

    etatfinal.x=a;
    etatfinal.y=b;

    do {
        printf("\n\nMenu:\n");
        printf("1. Recherche en largeur\n");
        printf("2. Recherche en profondeur\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
         n=0;
         listeNoeuds.debut =listeNoeuds.fin =NULL;
        switch (choix) {
            case 1:
                printf("\n");
                start = clock();
                n=RechercheLargeur( etatInitial , etatfinal , genereSuccesseurs);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\nle temps d'execution du recherche en largeur: %f seconds", cpu_time_used);
                break;
            case 2:
                printf("\n");
                start = clock();
                c=Rechercheprofondeur( etatInitial , etatfinal , genereSuccesseursprofond);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\nle temps d'execution du recherche en profondeur: %f seconds", cpu_time_used);
                break;
            case 3:
                printf("Programme terminé.\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);
        return 0;
}
