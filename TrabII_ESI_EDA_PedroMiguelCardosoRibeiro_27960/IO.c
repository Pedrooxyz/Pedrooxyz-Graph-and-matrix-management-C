/*****************************************************************//**
 * \file   IO.c
 * \brief  Funções de output que estão na etapa 1 e 2 do Trabalho Prático de Estruturas Avançadas de Dados
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "DeclaracaoFunc.h"

#pragma region FASE 1 - ex6

/**
 * @brief Mostra a matriz.
 *
 * Esta função percorre todas as linhas da matriz e imprime os elementos de cada linha na saída padrão.
 *
 * @param matriz Um apontador para o início da lista ligada que representa a matriz.
 */
void MostraMatriz(Linha* matriz) {
    Linha* linha = matriz;
    while (linha != NULL) {
        Elemento* elemento = linha->inicio;
        while (elemento != NULL) { //Avança de vértice para vértice
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
* Esta função imprime na tela a representação do grafo,
* mostrando os vértices e as suas adjacências.
*
* @param g Ponteiro para o grafo a ser mostrado.
*/
void MostrarGrafo(Grafo* g) {
	if (g == NULL || g->inicio == NULL) {
		printf("Grafo vazio.\n");
		return;
	}

	Vertice* atual = g->inicio;
	while (atual != NULL) { // Ciclo que percorre os vértices
		printf("Vértice %d (valor:%d) -> ", atual->cod, atual->valor);
		if (atual->pAdj == NULL) {
			printf("Sem adjacências\n");
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
 * @brief Mostra o caminho encontrado no formato de uma lista de vértices.
 *
 * @param caminho Apontador que contem os identificadores dos vértices no caminho encontrado.
 * @param tamanho O número de vértices no caminho.
 */
void MostrarCaminho(int* caminho, int tamanho) {
	printf("Caminho encontrado: ");
	for (int i = 0; i < tamanho; i++) { // Percorre caminho e imprime cada vértice
		printf("%d ", caminho[i]);
	}
	printf("\n");
}

#pragma endregion

#pragma region FASE 2 - MOSTRA SOMA E CAMINHO (ex 6)

/**
 * @brief Mostra os caminhos possíveis de um vértice de origem a um vértice de destino no grafo,
 *        a soma máxima dos valores dos vértices nesses caminhos, e exporta essas informações para um ficheiro.
 *
 * @param grafo Apontador para o grafo onde os vértices estão localizados.
 * @param origem Identificador do vértice de origem.
 * @param destino Identificador do vértice de destino.
 */
void MostraSomaECaminho(Grafo* grafo, int origem, int destino) {
	int* nLinha = malloc(grafo->totvertices * sizeof(int));
	if (nLinha == NULL) {
		printf("Erro ao alocar memória para nLinha.\n");
		return;
	}

	int soma = SomaMaximaCaminhos(grafo, nLinha);
	printf("Caminhos possíveis:\n\n");
	EncontrarCaminhos(grafo, origem, destino); //Funcao necessáriaa para serem imprimidos no ficheiro os caminhos
	printf("\n\n");
	printf("A soma máxima é %d\n", soma); //Mostra a soma máxima
	printf("A(s) linha(s) com a maior soma é/são: ");
	for (int i = 0; i < 100 && nLinha[i] != 0; i++) {
		printf("%d ", nLinha[i]);
	}
	printf("\n");
	ImprimirLinhas("Caminho.txt", nLinha, grafo->totvertices); //mostra os caminhos das somas máximas
}

#pragma endregion

#pragma region FASE 2 - IMPRIME LINHAS (ex 5)

/**
 * @brief Imprime no ecrã as linhas especificadas de um ficheiro.
 *
 * @param nomeFicheiro O nome do ficheiro a ser lido.
 * @param linhas Um apontador contendo os números das linhas a serem impressas.
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
			// Atualiza a próxima linha desejada
			linhaDesejada = linhas[i];
			i++;
		}
		linhaAtual++;
	}

	fclose(fp);
}

#pragma endregion
