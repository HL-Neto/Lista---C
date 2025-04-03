#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 60

typedef struct {
    int rgm;
} Aluno;

typedef struct {
    Aluno vetor[MAX];
    int ultimaPosicao;
} Lista;

Lista criar() {
    Lista lista;
    lista.ultimaPosicao = -1;
    return lista;
}

int listaVazia(Lista *lista) {
    return (lista->ultimaPosicao == -1);
}

int listaCheia(Lista *lista) {
    return (lista->ultimaPosicao == MAX - 1);
}

int tamanhoAtualLista(Lista *lista) {
    return lista->ultimaPosicao + 1;
}

int buscaSequencial(Lista *lista, int rgm_busca) {
    int i = 0;
    while (i <= lista->ultimaPosicao) {
        if (lista->vetor[i].rgm == rgm_busca) {
            return i;
        }
        i++;
    }
    return -1;
}

int removerContatoPorNome(Lista *lista, int rgm) {
    int indice = buscaSequencial(lista, rgm);
    if (indice != -1) {
        for (int i = indice; i < lista->ultimaPosicao; i++) {
            lista->vetor[i] = lista->vetor[i + 1];
        }
        lista->ultimaPosicao--;
        printf("RGM excluido\n");
        return 0;
    } else {
        return -1;
    }
}

int main() {
    int resposta;
    Lista novaLista = criar();

    do {
        printf("Menu\n 1.INCLUIR\n 2.BUSCAR\n 3.MOSTRAR\n 4.REMOVER \n");
        printf("escolha uma opcao:\n");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                if (listaCheia(&novaLista)) {
                    printf("A lista está cheia e não dá para adicionar novos contatos!\n");
                } else {
                    Aluno novo_rgm; 
                    printf("Qual o rgm que você deseja adicionar?:\n");
                    scanf("%d", &novo_rgm.rgm);
                    novaLista.vetor[++novaLista.ultimaPosicao] = novo_rgm;
                    printf("Aluno adicionado\n");
                }
                break;

            case 2:
                if (listaVazia(&novaLista)) {
                    printf("A lista está vazia.\n");
                } else {
                    int rgm_busca;
                    printf("Digite o rgm:\n");
                    scanf("%d", &rgm_busca);
                    int busca = buscaSequencial(&novaLista, rgm_busca);
                    if (busca == -1) {
                        printf("não existe;\n");
                    } else {
                        printf("matricula %d rgm %d\n", busca, rgm_busca);
                    }
                }
                break;

            case 3:
                if (listaVazia(&novaLista)) {
                    printf("A lista está vazia.\n");
                } else {
                    for (int i = 0; i <= novaLista.ultimaPosicao; i++) {
                        printf("matricula : %d rgm : %d\n", i + 1, novaLista.vetor[i].rgm);
                    }
                }
                break;

            case 4:
                printf("Qual o rgm?:\n");
                int rgm; 
                scanf("%d", &rgm);
                removerContatoPorNome(&novaLista, rgm);
                break;

            case 5:
                printf("Sair\n");
                break;
        }
    } while (resposta != 5);

    return 0;
}
