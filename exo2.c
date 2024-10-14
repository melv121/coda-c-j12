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

void append(number **head, int value) {
    number *new_node = create_node(value);
    if (!*head) {
        *head = new_node;
    } else {
        number *current = *head;
        while (current->next) current = current->next;
        current->next = new_node;
    }
}

void insert_after(number *prev_node, int value) {
    if (prev_node) {
        number *new_node = create_node(value);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
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
        append(&head, value);
        printf("Voulez-vous ajouter un autre nombre ? (o/n): ");
        scanf(" %c", &choice);
    } while (choice == 'o' || choice == 'O');

    printf("Liste chaînée avant l'insertion : ");
    print_list(head);

    int insert_value, position_value;
    printf("Entrez le nombre à insérer: ");
    scanf("%d", &insert_value);
    printf("Entrez le nombre après lequel insérer: ");
    scanf("%d", &position_value);

    number *current = head;
    while (current && current->value != position_value) current = current->next;

    if (current) insert_after(current, insert_value);
    else printf("Le nombre %d n'a pas été trouvé.\n", position_value);

    printf("Liste chaînée après l'insertion : ");
    print_list(head);

    free_list(head);
    return 0;
}