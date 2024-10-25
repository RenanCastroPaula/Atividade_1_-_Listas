#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da lista encadeada
typedef struct {
    Node* head;
} ListaEncadeada;

// Função para criar a lista
void criarLista(ListaEncadeada* lista) {
    lista->head = NULL;
    printf("Lista criada.\n");
}

// Função para inserir elementos na lista em ordem crescente
void inserirLista(ListaEncadeada* lista, int data) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    novo_node->data = data;
    novo_node->next = NULL;

    if (lista->head == NULL || lista->head->data >= novo_node->data) {
        novo_node->next = lista->head;
        lista->head = novo_node;
    } else {
        Node* atual = lista->head;
        while (atual->next != NULL && atual->next->data < novo_node->data) {
            atual = atual->next;
        }
        novo_node->next = atual->next;
        atual->next = novo_node;
    }
    printf("Elemento %d inserido na lista.\n", data);
}

// Função para exibir os elementos da lista
void exibirLista(ListaEncadeada* lista) {
    Node* atual = lista->head;
    printf("Elementos da lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->data);
        atual = atual->next;
    }
    printf("NULL\n");
}

// Função para verificar se a lista está vazia
bool verificarVazia(ListaEncadeada* lista) {
    return lista->head == NULL;
}

// Função para buscar um elemento na lista
bool buscarLista(ListaEncadeada* lista, int data) {
    Node* atual = lista->head;
    while (atual != NULL) {
        if (atual->data == data) {
            return true;
        }
        atual = atual->next;
    }
    return false;
}

// Função para excluir um elemento da lista
bool excluirLista(ListaEncadeada* lista, int data) {
    Node* atual = lista->head;
    Node* anterior = NULL;

    while (atual != NULL && atual->data != data) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", data);
        return false; // Elemento não encontrado
    }

    if (anterior == NULL) {
        lista->head = atual->next; // O elemento a ser excluído é o primeiro
    } else {
        anterior->next = atual->next; 
    }

    free(atual); // Libera a memória do nó excluído
    printf("Elemento %d excluído da lista.\n", data);
    return true;
}

// Função para liberar a lista
void liberarLista(ListaEncadeada* lista) {
    Node* atual = lista->head;
    Node* proximo;

    while (atual != NULL) {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }
    lista->head = NULL; // Torna a lista vazia
    printf("Lista liberada.\n");
}


int main() {
    ListaEncadeada lista;
    criarLista(&lista);

    inserirLista(&lista, 5);
    inserirLista(&lista, 3);
    inserirLista(&lista, 7);
    inserirLista(&lista, 1);

    exibirLista(&lista); 

    printf("Lista vazia? %s\n", verificarVazia(&lista) ? "Sim" : "Não");
    printf("Buscar 5? %s\n", buscarLista(&lista, 5) ? "Encontrado" : "Não encontrado");
    printf("Buscar 9? %s\n", buscarLista(&lista, 9) ? "Encontrado" : "Não encontrado");

    excluirLista(&lista, 3);
    exibirLista(&lista);

    liberarLista(&lista);
    printf("Lista vazia? %s\n", verificarVazia(&lista) ? "Sim" : "Não");

    return 0;
}
