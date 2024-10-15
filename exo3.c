#include <stdio.h>
#include <stdlib.h>

typedef struct s_number {
    int value;
    struct s_number *next; 
} number;

number* create_node(int value) {
    number *new_node = malloc(sizeof(number));
    if (!new_node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void insert_sorted(number **head, int value) {
    number *new_node = create_node(value);
    if (!*head || (*head)->value >= value) {
        new_node->next = *head;
        *head = new_node;
    } else {
        number *current = *head;
        while (current->next && current->next->value < value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void print_list(number *head) {
    for (number *current = head; current; current = current->next) {
        printf("%d -> ", current->value);
    }
    printf("NULL\n");
}

void free_list(number *head) {
    number *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    number *head = NULL;
    char choice;
    do {
        int value;
        printf("Entrez un nombre: ");
        scanf("%d", &value);
        insert_sorted(&head, value);
        printf("Voulez-vous ajouter un autre nombre ? (o/n): ");
        scanf(" %c", &choice);
    } while (choice == 'o' || choice == 'O');

    printf("Liste chaînée triée : ");
    print_list(head);

    free_list(head);
    return 0;
}


    