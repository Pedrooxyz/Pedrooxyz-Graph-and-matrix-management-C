/*****************************************************************//**
 * \file   IO.c
 * \brief  Fun��es de output que est�o na etapa 1 e 2 do Trabalho Pr�tico de Estruturas Avan�adas de Dados
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "DeclaracaoFunc.h"

#pragma region FASE 1 - ex6

/**
 * @brief Mostra a matriz.
 *
 * Esta fun��o percorre todas as linhas da matriz e imprime os elementos de cada linha na sa�da padr�o.
 *
 * @param matriz Um apontador para o in�cio da lista ligada que representa a matriz.
 */
void MostraMatriz(Linha* matriz) {
    Linha* linha = matriz;
    while (linha != NULL) {
        Elemento* elemento = linha->inicio;
        while (elemento != NULL) { //Avan�a de v�rtice para v�rtice
            printf("%d ", elemento->valor);
            elemento = elemento->proximo;
        }
        printf("\n");
        linha = linha->proxima;
    }
}

#pragma endregion

#pragma region FASE 2 - FUNCAO MOSTRA GRAFO

/**
* @brief Mostra o grafo.
*
* Esta fun��o imprime na tela a representa��o do grafo,
* mostrando os v�rtices e as suas adjac�ncias.
*
* @param g Ponteiro para o grafo a ser mostrado.
*/
void MostrarGrafo(Grafo* g) {
	if (g == NULL || g->inicio == NULL) {
		printf("Grafo vazio.\n");
		return;
	}

	Vertice* atual = g->inicio;
	while (atual != NULL) { // Ciclo que percorre os v�rtices
		printf("V�rtice %d (valor:%d) -> ", atual->cod, atual->valor);
		if (atual->pAdj == NULL) {
			printf("Sem adjac�ncias\n");
		}
		else { //Tendo Adj ...
			Adj* adjAtual = atual->pAdj;
			while (adjAtual != NULL) { // Percorre as Adj
				printf("(%d, peso %d) ", adjAtual->cod, adjAtual->peso);
				adjAtual = adjAtual->pAdj;
			}
			printf("\n");
		}
		atual = atual->pVertice;
	}
}

#pragma endregion

#pragma region FASE 2 - MOSTRA CAMINHO (ex 5)

/**
 * @brief Mostra o caminho encontrado no formato de uma lista de v�rtices.
 *
 * @param caminho Apontador que contem os identificadores dos v�rtices no caminho encontrado.
 * @param tamanho O n�mero de v�rtices no caminho.
 */
void MostrarCaminho(int* caminho, int tamanho) {
	printf("Caminho encontrado: ");
	for (int i = 0; i < tamanho; i++) { // Percorre caminho e imprime cada v�rtice
		printf("%d ", caminho[i]);
	}
	printf("\n");
}

#pragma endregion

#pragma region FASE 2 - MOSTRA SOMA E CAMINHO (ex 6)

/**
 * @brief Mostra os caminhos poss�veis de um v�rtice de origem a um v�rtice de destino no grafo,
 *        a soma m�xima dos valores dos v�rtices nesses caminhos, e exporta essas informa��es para um ficheiro.
 *
 * @param grafo Apontador para o grafo onde os v�rtices est�o localizados.
 * @param origem Identificador do v�rtice de origem.
 * @param destino Identificador do v�rtice de destino.
 */
void MostraSomaECaminho(Grafo* grafo, int origem, int destino) {
	int* nLinha = malloc(grafo->totvertices * sizeof(int));
	if (nLinha == NULL) {
		printf("Erro ao alocar mem�ria para nLinha.\n");
		return;
	}

	int soma = SomaMaximaCaminhos(grafo, nLinha);
	printf("Caminhos poss�veis:\n\n");
	EncontrarCaminhos(grafo, origem, destino); //Funcao necess�riaa para serem imprimidos no ficheiro os caminhos
	printf("\n\n");
	printf("A soma m�xima � %d\n", soma); //Mostra a soma m�xima
	printf("A(s) linha(s) com a maior soma �/s�o: ");
	for (int i = 0; i < 100 && nLinha[i] != 0; i++) {
		printf("%d ", nLinha[i]);
	}
	printf("\n");
	ImprimirLinhas("Caminho.txt", nLinha, grafo->totvertices); //mostra os caminhos das somas m�ximas
}

#pragma endregion

#pragma region FASE 2 - IMPRIME LINHAS (ex 5)

/**
 * @brief Imprime no ecr� as linhas especificadas de um ficheiro.
 *
 * @param nomeFicheiro O nome do ficheiro a ser lido.
 * @param linhas Um apontador contendo os n�meros das linhas a serem impressas.
 * @param tamanho O tamanho do apontador de linhas.
 */
void ImprimirLinhas(char* nomeFicheiro, int* linhas, int tamanho) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		printf("Erro ao abrir o ficheiro %s.\n", nomeFicheiro);
		return;
	}

	int linhaAtual = 1;
	int linhaDesejada = linhas[0];
	int i = 1;

	char buffer[1000]; // Buffer para armazenar temporariamente cada linha
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		if (linhaAtual == linhaDesejada) {
			printf("%s", buffer); // Imprime a linha atual se for uma das desejadas
			// Atualiza a pr�xima linha desejada
			linhaDesejada = linhas[i];
			i++;
		}
		linhaAtual++;
	}

	fclose(fp);
}

#pragma endregion
