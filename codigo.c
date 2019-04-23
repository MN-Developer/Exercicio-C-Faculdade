#include <stdio.h>
#include <stdlib.h>

#define N 200

struct estoque {
	char produto[N];
	char fornecedor[N];
	double valor_compra;
	double valor_venda;
	int quantidade;
	struct estoque*prox;
};

typedef struct estoque Estoque;

Estoque * inicializar_lista(){
	
	Estoque *estq = (Estoque *) malloc(sizeof(Estoque));
	
	if(estq ==NULL){
		exit(0);
	}
	estq->prox = NULL;
	
	return (estq);
	
	
}

void adicionar(Estoque *estq){
	printf("Digite o Nome do Produto\n");
	scanf("%s", &estq->produto);
	printf("Digite o nome do Fornecedor:\n");
	scanf("%s",&estq->fornecedor);
	printf("Qual o valor da compra?\n");
	scanf("%f", &estq->valor_compra);
	printf("Qual a quantidade do produto?\n");
	scanf("%i", &estq->quantidade);
	printf("Qual o valor da venda?\n");
	scanf("%f", &estq->valor_venda);
}

void imprimir(Estoque * stq){
	if(stq != NULL){
		Estoque * aux = stq;
		while(aux != NULL){
			printf("%s, %s, %d, %f, %f\n",
				aux->produto, aux->fornecedor,
				aux->quantidade,
				aux->valor_compra,
				aux->valor_venda);
			aux = aux->prox;
		}
	}
}

void inserir_na_lista(Estoque * estq){
	Estoque * aux = inicializar_lista();
	adicionar(aux);
	
	if(estq == NULL){
		estq == aux;
	}else{
		Estoque * tmp;
		tmp = estq;
		while(tmp->prox != NULL){
			tmp=tmp->prox;
		}
		
		tmp->prox = aux;
		
	}
}

void salvar_txt(){
	
	FILE *pont_arq; // cria variÃ¡vel ponteiro para o arquivo


  //abrindo o arquivo com tipo de abertura w
	pont_arq = fopen("resultado_ex14.txt", "w");

  //testando se o arquivo foi realmente criado
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
		return 1;
	}

  //usando fprintf para armazenar a string no arquivo
	fprintf(pont_arq, "%d", imprimir());

  //usando fclose para fechar o arquivo
	fclose(pont_arq);

	printfln("resultado:  %d",imprimir());

	printf("Dados gravados com sucesso!");

	getch();
	return(0);
}

int main(int argc, char *argv[]) {
	Estoque * meu_estoque = inicializar_lista();
	adicionar(meu_estoque);
	meu_estoque->prox = inicializar_lista();
	adicionar(meu_estoque->prox);
	imprimir(meu_estoque);
	return 0;
}