#include	<stdio.h>
#include	<string.h>
#include	<locale.h>

#define MAX 100

// Definição básica dos elementos na lista
typedef struct {
    char nome[50];
} Aluno;

typedef struct {
    Aluno vetor[MAX];
    int ultimaPosicao;
} Lista;

// Criar lista vazia
Lista criar() {
    Lista lista;
    lista.ultimaPosicao = -1;
    return lista;
}

// Verificações básicas da lista
int listaVazia(Lista *lista) {
    return (lista->ultimaPosicao == -1);
}

int listaCheia(Lista *lista) {
    return (lista->ultimaPosicao == MAX - 1);
}

int tamanhoAtualLista(Lista *lista) {
    return lista->ultimaPosicao + 1;
}



int main(){
	int resposta;
	Lista novaLista = criar();
do{

	printf("Menu\n 1.Criar Aluno\n 2.Listar alubos\n 3.Pesquisar aluno\n 4.Excluir aluno\n 5.Sair\n");
	printf("escolha uma opcao:\n");
	scanf("%d", &resposta);
	getchar();
	
	switch(resposta){
		case 1:
			if (listaCheia(&novaLista)) {
                        printf("A lista está cheia e não dá para adicionar novos contatos!\n");
                    } else {
                        Aluno novoAluno;
                        printf("Qual o nome do contato que você deseja adicionar?:\n");
                        fgets(novoAluno.nome, 50, stdin);
                        novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';

                        novaLista.vetor[++novaLista.ultimaPosicao] = novoAluno;
                        printf("Aluno adicionado!\n");
                    }
                    break;
		
		case 2:
			if (listaVazia(&novaLista)) {
                        printf("A lista está vazia.\n");
                    } else {
                        for (int i = 0; i <= novaLista.ultimaPosicao; i++) {
                            printf("%d. %s\n", i + 1, novaLista.vetor[i].nome);
                        }
                    }
                    break;
		
		case 3:
			printf("Pesquisar aluno");
			break;
		
		case 4:
			printf("Excluir aluno");
			break;
		
		case 5:
			printf("Sair");
			break;
	}
} while (resposta != 5);
}		

