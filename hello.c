#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 連結リストについての学習

// ノードの定義
typedef struct Node{
    int data;
    struct Node *next;
}Node;


Node *create_node(int value){
    // ノード分の領域を確保
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL){
        perror("領域確保に失敗");
        exit(EXIT_FAILURE);
    }
    new_node -> data = value;
    new_node -> next = NULL;

    return new_node;
}

void add_to_node(Node **head_ref, int value){
    Node *new_node = create_node(value);

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    Node *current = *head_ref;
    while (current -> next != NULL){
        current = current -> next;
    }
    current -> next = new_node;
    
}

void print_node(Node *head){
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current -> next;
    }
    printf("NULL\n");
    
}


void free_memory(Node *head){
    Node *current = head;
    Node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}


int main(void)
{
    Node *head = NULL;

    add_to_node(&head, 56);
    add_to_node(&head, 10);
    add_to_node(&head, 78);
    print_node(head);

    free_memory(head);

    return 0;
}