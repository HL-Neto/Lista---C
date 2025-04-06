#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 60

typedef struct listaEncadeada {
    char disciplina[50];
    struct listaEncadeada *prox;
} ListaEncadeada;

typedef struct {
    int rgm;
    ListaEncadeada *disciplinas;
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

int buscaSequencial(Lista *lista, int rgm_busca) {
    for (int i = 0; i <= lista->ultimaPosicao; i++) {
        if (lista->vetor[i].rgm == rgm_busca) {
            return i;
        }
    }
    return -1;
}



int removerContatoPorNome(Lista *lista, int rgm) {
    int indice = buscaSequencial(lista, rgm);
    if (indice != -1) {
        lista->ultimaPosicao--;
        printf("RGM excluido\n");
        return 0;
    } else {
        printf("RGM nao encontrado\n");
        return -1;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int resposta;
    Lista novaLista = criar();

    do {
        printf("\nMenu\n 1.INCLUIR\n 2.BUSCAR\n 3.MOSTRAR\n 4.REMOVER\n 5.SAIR\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                if (listaCheia(&novaLista)) {
                    printf("A lista esta cheia!\n");
                } else {
                    Aluno novoAluno;
                    char respostaDisciplina;

                    printf("Qual o RGM que voce deseja adicionar? ");
                    scanf("%d", &novoAluno.rgm);
                    novoAluno.disciplinas = NULL;

                    do {
                        ListaEncadeada *novo = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
                        printf("Me diga a disciplina do aluno matriculado: ");
                        scanf("%s", novo->disciplina);
                        novo->prox = NULL;

                        if (novoAluno.disciplinas == NULL) {
                            novoAluno.disciplinas = novo;
                        } else {
                            ListaEncadeada *ultimo = novoAluno.disciplinas;
                            while (ultimo->prox != NULL) ultimo = ultimo->prox;
                            ultimo->prox = novo;
                        }

                        printf("Mais disciplinas? (s/n): ");
                        scanf(" %c", &respostaDisciplina);
                    } while (respostaDisciplina == 's' || respostaDisciplina == 'S');

                    novaLista.vetor[++novaLista.ultimaPosicao] = novoAluno;
                    printf("Aluno atualizado!!\n");
                }
                break;

            case 2:
                if (listaVazia(&novaLista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    int rgm_busca;
                    printf("Digite o RGM: ");
                    scanf("%d", &rgm_busca);
                    int busca = buscaSequencial(&novaLista, rgm_busca);
                    if (busca == -1) {
                        printf("Nao existe.\n");
                    } else {
                    	int i = 0;
                    	ListaEncadeada *disc = novaLista.vetor[i].disciplinas;
                        printf("Matricula %d, RGM %d, Disciplinas:", busca + 1, rgm_busca);
                        while (disc != NULL) {
                            printf("%s ", disc->disciplina);
                            disc = disc->prox;
                        }
                        printf("\n");
                    }
                }
                break;

            case 3:
                if (listaVazia(&novaLista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    for (int i = 0; i <= novaLista.ultimaPosicao; i++) {
                        printf("Matricula: %d, RGM: %d\n", i + 1, novaLista.vetor[i].rgm);
                        ListaEncadeada *disc = novaLista.vetor[i].disciplinas;
                        printf("Disciplinas: ");
                        while (disc != NULL) {
                            printf("%s ", disc->disciplina);
                            disc = disc->prox;
                        }
                        printf("\n");
                    }
                }
                break;

            case 4:
                if (listaVazia(&novaLista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    int rgm;
                    printf("Qual o RGM? ");
                    scanf("%d", &rgm);
                    removerContatoPorNome(&novaLista, rgm);
                }
                break;

            case 5:
                printf("Sair\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (resposta != 5);


    return 0;
}
