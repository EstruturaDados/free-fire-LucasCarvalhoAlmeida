#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_STRING 50

typedef struct {
    char nome[TAM_STRING];
    char tipo[TAM_STRING];
    int quantidade;
    int ativo; // 1 = ocupado, 0 = vazio
} Item;

void listarItens(Item mochila[]) {
    printf("\n=== ITENS DA MOCHILA ===\n");

    int vazio = 1;
    for (int i = 0; i < MAX_ITENS; i++) {
        if (mochila[i].ativo) {
            vazio = 0;
            printf("\nItem %d:\n", i + 1);
            printf("  Nome: %s\n", mochila[i].nome);
            printf("  Tipo: %s\n", mochila[i].tipo);
            printf("  Quantidade: %d\n", mochila[i].quantidade);
        }
    }

    if (vazio)
        printf("\nNenhum item cadastrado!\n");
}

void adicionarItem(Item mochila[]) {
    int pos = -1;

    // acha uma posição vazia
    for (int i = 0; i < MAX_ITENS; i++) {
        if (!mochila[i].ativo) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nA mochila está cheia!\n");
        return;
    }

    printf("\n=== Adicionar Item ===\n");

    printf("Nome: ");
    getchar(); // limpa buffer
    fgets(mochila[pos].nome, TAM_STRING, stdin);
    mochila[pos].nome[strcspn(mochila[pos].nome, "\n")] = '\0';

    printf("Tipo: ");
    fgets(mochila[pos].tipo, TAM_STRING, stdin);
    mochila[pos].tipo[strcspn(mochila[pos].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[pos].quantidade);

    mochila[pos].ativo = 1;

    printf("\nItem adicionado com sucesso!\n");
}

void removerItem(Item mochila[]) {
    char nomeBusca[TAM_STRING];
    getchar(); // limpar o enter pendente

    printf("\n=== Remover Item ===\n");
    printf("Digite o nome do item: ");
    fgets(nomeBusca, TAM_STRING, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < MAX_ITENS; i++) {
        if (mochila[i].ativo && strcmp(mochila[i].nome, nomeBusca) == 0) {
            mochila[i].ativo = 0;
            printf("\nItem removido!\n");
            return;
        }
    }

    printf("\nItem não encontrado!\n");
}

int main() {
    Item mochila[MAX_ITENS];

    // Inicializar
    for (int i = 0; i < MAX_ITENS; i++)
        mochila[i].ativo = 0;

    int opcao;

    do {
        printf("\n=== MENU DA MOCHILA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem(mochila);
                break;
            case 2:
                removerItem(mochila);
                break;
            case 3:
                listarItens(mochila);
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 4);

    return 0;
}