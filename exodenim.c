#include <stdio.h>

void print_rules() {
    printf("Bienvenue dans le jeu de Nim !\n");
    printf("Il y a un tas d'objets.\n");
    printf("À chaque tour, un joueur peut retirer entre 1 et 3 objets.\n");
    printf("Le joueur qui retire le dernier objet gagne.\n");
}

int main() {
    int total_objects = 20; 
    int player_turn = 1; 
    int objects_to_remove;

    print_rules();

    while (total_objects > 0) {
        printf("\nIl reste %d objets.\n", total_objects);
        printf("Joueur %d, combien d'objets voulez-vous retirer (1-3) ? ", player_turn);
        scanf("%d", &objects_to_remove);

        
        while (objects_to_remove < 1 || objects_to_remove > 3 || objects_to_remove > total_objects) {
            printf("Veuillez entrer un nombre valide d'objets à retirer (1-3) : ");
            scanf("%d", &objects_to_remove);
        }

        total_objects -= objects_to_remove;

        if (total_objects <= 0) {
            printf("\nJoueur %d a gagné !\n", player_turn);
            break;
        }

        
        player_turn = (player_turn == 1) ? 2 : 1;
    }

    return 0;
}
