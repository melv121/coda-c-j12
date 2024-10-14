#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;

struct s_number {
    int value;
    number *next;
};


number* create_node(int value) {
    number *new_node = (number *)malloc(sizeof(number));
    if (!new_node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void append(number **head, int value) {
    number *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        number *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


void print_list(number *head) {
    number *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    number *head = NULL;
    int value;
    char choice;

    do {
        printf("Entrez un nombre: ");
        scanf("%d", &value);
        append(&head, value);

        printf("Voulez-vous ajouter un autre nombre ? (o/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'o' || choice == 'O');

    printf("Liste chaînée : ");
    print_list(head);

    number *current = head;
    while (current != NULL) {
        number *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}