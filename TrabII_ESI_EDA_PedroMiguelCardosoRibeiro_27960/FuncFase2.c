/*****************************************************************//**
 * \file   FuncFase2.c
 * \brief  Funções para manipulação de Grafos, etapa 2 do Trabalho Prático de Estruturas Avançadas de Dados
 *
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "DeclaracaoFunc.h"

#pragma region FASE 2 - ex1

#pragma region FUNCOES DE INSERCAO

/**
 * @brief Insere um vértice em um grafo existente.
 *
 * @param v Apontador para o vértice a ser inserido.
 * @param grafo Apontador para o grafo onde o vértice será inserido.
 * @param res Apontador para a variável de resultado.
 * @return Apontador para o grafo atualizado.
 */
Grafo* InsereVertice(Vertice* v, Grafo* grafo, int* res) {
	//Testes:
	if (v == NULL) {
		*res = -1;
		return grafo;
	}
	if (grafo == NULL) {
		*res = 0;
		return NULL;
	}
	if (grafo->inicio == NULL) {
		grafo->inicio = v;
	}
	else {
		// Encontra o último vértice e insere o novo vértice no final
		Vertice* aux = grafo->inicio;
		while (aux->pVertice != NULL) {
			aux = aux->pVertice;
		}
		aux->pVertice = v;
	}
	v->visitado = false;
	grafo->verticesagora++;
	*res = 1;
	return grafo;
}

/**
 * @brief Insere uma adjacência em um grafo existente.
 *
 * @param g Apontador para o grafo onde a adjacência será inserida.
 * @param origem Identificador do vértice de origem da adjacência.
 * @param destino Identificador do vértice de destino da adjacência.
 * @param peso Peso da aresta.
 * @param res Apontador para a variável de resultado.
 * @return Apontador para o grafo atualizado.
 */
Grafo* InserirAdj(Grafo* g, int origem, int destino, int peso, bool* res) {
	*res = false;

	if (g == NULL) {
		*res = false;
		return g;
	}

	Vertice* aux = g->inicio;

	while (aux->cod != origem) {
		aux = aux->pVertice;
	}

	if (aux == NULL) {
		*res = false;
		return g;
	}

	Adj* novo = CriarAdj(destino, peso); //Uso da função de criação de uma Adj

	if (novo == NULL) {
		*res = false;
		return g;
	}

	// Insere a nova adjacência no vértice de origem
	if (aux->pAdj == NULL) {
		aux->pAdj = novo;
	}
	else {
		Adj* temp = aux->pAdj;
		while (temp->pAdj != NULL) {
			temp = temp->pAdj;
		}
		temp->pAdj = novo;
	}

	*res = true;
	return g;
}

#pragma endregion

#pragma region FUNCAO DE PROCURA

/**
 * @brief Retorna um apontador para o vértice com o identificador especificado no grafo.
 *
 * @param g Apontador para o grafo onde será realizada a busca.
 * @param idVertice Identificador do vértice a ser procurado.
 * @return Apontador para o vértice encontrado, ou NULL se não encontrado.
 */
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice) {
	if (g == NULL) return NULL;
	Vertice* atual = g->inicio;
	while (atual != NULL) {
		if (atual->cod == idVertice) { // Verifica se o código do vértice atual tem o id do vértice procurado
			return atual;
		}
		atual = atual->pVertice;
	}
	return NULL;
}

#pragma endregion

#pragma region FUNCOES DE ELIMINACAO

#pragma region FUNCOES DE ELIMINACAO DE ADJ

/**
 * @brief Liberta a memória alocada para uma adjacência.
 *
 * @param Adj Apontador para a adjacência a ser destruída.
 * @return true se a destruição foi bem-sucedida, false caso contrário.
 */
bool AdjacenteDestruir(Adj* Adj) {
	if (Adj == NULL) return false;
	free(Adj);
	return true;
}

/**
 * @brief Elimina uma adjacência de um vértice em um grafo.
 *
 * @param g Apontador para o grafo onde a adjacência será eliminada.
 * @param origem Identificador do vértice de origem da adjacência.
 * @param destino Identificador do vértice de destino da adjacência.
 * @param res Apontador para a variável de resultado.
 * @return Apontador para o grafo atualizado.
 */
Grafo* EliminaAdj(Grafo* g, int origem, int destino, bool* res) {
	//Testes:
	if (!g) return NULL;

	if (origem || destino > g->totvertices) {
		*res = false;
		return g;
	}

	Vertice* atual = g->inicio;
	while (atual && atual->cod != origem) atual = atual->pVertice;
	if (!atual) return g;

	// Procura a adjacência no vértice de origem
	Adj* ant = NULL;
	Adj* aux = atual->pAdj;
	while (aux && aux->cod != destino) {
		ant = aux;
		aux = aux->pAdj;
	}
	if (!aux) return g;

	// Remove a adjacência do vértice de origem
	if (!ant) atual->pAdj = aux->pAdj;
	else ant->pAdj = aux->pAdj;

	// Libera a memória alocada para a adjacência removida
	AdjacenteDestruir(aux);

	*res = true;
	return g;
}

/**
 * @brief Elimina todas as adjacências de uma lista de adjacências.
 *
 * @param listaAdj Apontador para a lista de adjacências a serem eliminadas.
 * @param res Apontador para a variável de resultado.
 * @return Apontador nulo, indicando que todas as adjacências foram eliminadas.
 */
Adj* EliminaTodasAdj(Adj* listaAdj, bool* res) {
	*res = false;
	if (listaAdj == NULL) return NULL;

	Adj* aux = listaAdj;
	while (aux) {
		Adj* prox = aux->pAdj;
		AdjacenteDestruir(aux); //Uso da função de destruição da Adj apagado a memória, anteriormente alocada
		aux = prox;
	}
	*res = true;
	return NULL;
}

#pragma endregion

#pragma region FUNCOES DE ELIMINACAO DE VERTICE

/**
 * @brief Liberta a memória alocada para um vértice.
 *
 * @param v Apontador para o vértice a ser destruído.
 * @return true se a destruição foi bem-sucedida, false caso contrário.
 */
bool DestroiVertice(Vertice* v) {
	if (v == NULL) return false;
	free(v);
	return true;
}

/**
 * @brief Elimina um vértice e suas adjacências de um grafo.
 *
 * @param grafo Apontador para o grafo onde o vértice será eliminado.
 * @param codVertice Identificador do vértice a ser eliminado.
 * @param res Apontador para a variável de resultado.
 * @return Apontador para o grafo atualizado.
 */
Grafo* EliminaVertice(Grafo* grafo, int codVertice, bool* res) {
	*res = false;
	if (grafo == NULL || grafo->inicio == NULL) return grafo;

	Vertice* aux = grafo->inicio;
	Vertice* verticeAnterior = NULL;

	while (aux != NULL && aux->cod != codVertice) {
		verticeAnterior = aux;
		aux = aux->pVertice;
	}

	if (aux == NULL) return grafo;

	if (verticeAnterior == NULL) grafo->inicio = aux->pVertice;
	else verticeAnterior->pVertice = aux->pVertice;

	aux->pAdj=EliminaTodasAdj(aux->pAdj, res); //Como as Adj estão "ligadas" ao vértice e já não é preciso esse espaço ocupado
	if (*res == false) return grafo;

	DestroiVertice(aux); //Chama a função para tirar a memória alocada anteriormente
	grafo->totvertices--;
	*res = true;
	return grafo;
}

#pragma endregion

#pragma region ELIMINACAO DE GRAFO

/**
 * @brief Liberta a memória alocada para um grafo e todos os seus vértices e adjacências.
 *
 * @param grafo Apontador para o grafo a ser destruído.
 * @return true se a destruição foi bem-sucedida, false caso contrário.
 */
bool DestruirGrafo(Grafo* grafo) {
	if (grafo == NULL) return false;

	Vertice* atual = grafo->inicio;
	while (atual != NULL) {
		// Armazena o próximo vértice antes de liberar o atual, de modo a não haver a perda dos próximos vértice
		Vertice* proximoVertice = atual->pVertice;
		Adj* adjAtual = atual->pAdj;
		while (adjAtual != NULL) {
			Adj* pAdj = adjAtual->pAdj;
			AdjacenteDestruir(adjAtual); //Uso da função de destruir Adj
			adjAtual = pAdj;
		}
		DestroiVertice(atual); //Uso da função de destruir Vértice
		atual = proximoVertice;
	}

	free(grafo);
	return true;
}

#pragma enregion

#pragma endregion

#pragma endregion

#pragma region PRESERVACAO DO GRAFO

/**
 * @brief Guarda um grafo em um ficheiro binário.
 *
 * @param g apontador para o grafo a ser salvo.
 * @param nomeFicheiro Nome do ficheiro binário onde o grafo será guardado.
 * @return true se o grafo foi guardado com sucesso, false caso contrário.
 */
bool GuardarGrafo(Grafo* g, char* nomeFicheiro) {
	if (g == NULL || g->inicio == NULL || nomeFicheiro == NULL) return false;

	FILE* fp = fopen(nomeFicheiro, "wb");
	if (fp == NULL) return false;

	Vertice* atual = g->inicio;
	while (atual != NULL) { // Itera sobre os vértices
		fwrite(&(atual->valor), sizeof(int), 1, fp); // Escreve o valor do vértice
		Adj* adjAtual = atual->pAdj;
		while (adjAtual != NULL) { // Itera sobre as adj
			fwrite(&(adjAtual->peso), sizeof(int), 1, fp); // Escreve o peso da adj
			adjAtual = adjAtual->pAdj;		
		}
		atual = atual->pVertice;
	}

	fclose(fp);
	return true;
}

#pragma endregion

#pragma endregion

#pragma region FASE 2 - ex3

#pragma region CONSTRUÇÃO DE GRAFO

/**
 * @brief Constrói um grafo a partir de um ficheiro contendo uma matriz de adjacência.
 *
 * @param nomeFicheiro Nome do ficheiro contendo a matriz de adjacência.
 * @return Apontador para o grafo construído, ou NULL em caso de erro.
 */
Grafo* ConstruirGrafo(char* nomeFicheiro) {
	Linha* matriz = CarregarMatriz(nomeFicheiro);
	if (matriz == NULL) return NULL;
	Grafo* grafo = CriarGrafo(0);
	Linha* linhaAtual = matriz;
	int indiceVertice = 0;
	int res = 0;
	int i = 0;

	while (linhaAtual != NULL) { // Percorre cada linha da matriz
		Vertice* novoVertice = CriarVertice(indiceVertice++, i * 5);
		grafo = InsereVertice(novoVertice, grafo, &res);
		i++;
		Elemento* elementoAtual = linhaAtual->inicio;
		int indiceAdj = 0;
		bool aux;
		while (elementoAtual != NULL) { // Percorre os elementos da linha atual
			if (elementoAtual->valor != 0) {
				grafo = InserirAdj(grafo, indiceVertice - 1, indiceAdj, elementoAtual->valor, &aux);
			}
			elementoAtual = elementoAtual->proximo;
			indiceAdj++;
		}

		linhaAtual = linhaAtual->proxima;
	}
	LibertarMatriz(matriz); // Libera a memória alocada para a matriz
	return grafo;
}

#pragma endregion

#pragma region LIBERTAR MATRIZ DE APOIO

/**
 * @brief Liberta a memória alocada para uma matriz de adjacência.
 *
 * @param matriz Apontador para a estrutura de dados representando a matriz.
 */
bool LibertarMatriz(Linha* matriz) {
	if (matriz == NULL)return false;
	Linha* linhaAtual = matriz;
	while (linhaAtual != NULL) {
		// Inicia a liberação dos elementos da linha atual
		Elemento* elementoAtual = linhaAtual->inicio;
		while (elementoAtual != NULL) {
			Elemento* elementoTemp = elementoAtual;
			// Avança para o próximo elemento antes de liberar o atual, para nao perder os próximos elementos
			elementoAtual = elementoAtual->proximo;
			free(elementoTemp);
		}
		// Armazena a linha atual temporariamente antes de avançar para a próxima
		Linha* linhaTemp = linhaAtual;
		linhaAtual = linhaAtual->proxima;
		free(linhaTemp);
	}
	return true;
}

#pragma endregion

#pragma endregion

#pragma region FASE 2 - ex4

#pragma region DFT

/**
 * @brief Encontra caminhos entre dois vértices em um grafo usando DFT.
 *
 * @param grafo Apontador para o grafo onde os caminhos serão buscados.
 * @param origem Identificador do vértice de origem.
 * @param destino Identificador do vértice de destino.
 * @return true se algum caminho foi encontrado, false caso contrário.
 */
bool EncontrarCaminhos(Grafo* grafo, int origem, int destino) {
	//Encontra os dois vertices (da origem e do destino)
	Vertice* vOrigem = OndeEstaVerticeGrafo(grafo, origem);
	Vertice* vDestino = OndeEstaVerticeGrafo(grafo, destino);

	if (vOrigem == NULL || vDestino == NULL) return false;

	int* caminho = (int*)malloc(grafo->totvertices * sizeof(int));

	if (caminho == NULL) return false;

	caminho[0] = vOrigem->cod;

	// Realiza a busca em DFT para encontrar o caminho entre os vértices
	bool caminhoEncontrado = BuscaProfundidade(grafo, vOrigem, vDestino, caminho, 1);

	return caminhoEncontrado;
}

/**
 * @brief Realiza uma busca DFT (em profundidade) a partir de um vértice em um grafo para encontrar um caminho até um vértice destino.
 *
 * @param grafo Apontador para o grafo onde a busca será realizada.
 * @param vertice Apontador para o vértice atual.
 * @param destino Apontador para o vértice destino.
 * @param caminho Apontador que armazena o caminho encontrado até o momento.
 * @param pos Posição atual no vetor de caminho.
 * @return true se um caminho até o destino foi encontrado, false caso contrário.
 */
bool BuscaProfundidade(Grafo* grafo, Vertice* vertice, Vertice* destino, int* caminho, int pos, bool *enc) {
	vertice->visitado = true;

	// Verifica se o vértice atual é o destino
	if (vertice == destino) {
		MostrarCaminho(caminho, pos);// Mostra o caminho encontrado
		ExportarCaminhoParaFicheiro(caminho, pos, enc);// Exporta o caminho para um ficheiro
		enc = false;
	}

	Adj* adjacente = vertice->pAdj;
	while (adjacente != NULL) {
		if (!adjacente->visitado) {
			Vertice* vizinho = OndeEstaVerticeGrafo(grafo, adjacente->cod);
			if (vizinho != NULL && !vizinho->visitado) {
				caminho[pos] = vizinho->cod;
				//Recursividade da função, realiza a função a partir do vertice adjacente
				if (BuscaProfundidade(grafo, vizinho, destino, caminho, pos + 1,enc)) {
					enc = true;
					return true;
				}
			}
		}
		adjacente = adjacente->pAdj;
	}

	vertice->visitado = false;
	return false;
}

bool caminhoJaExportado = false; //Varíavel global criada para que a presente variável seja sempre falsa antes que a função a baixo "corra"

/**
 * @brief Exporta o caminho encontrado para um ficheiro.
 *
 * @param caminho Apontador contendo os identificadores dos vértices no caminho encontrado.
 * @param tamanho O número de vértices no caminho.
 * @return int Retorna 1 se o caminho foi exportado com sucesso, -1 se houve erro na abertura do ficheiro.
 */
int ExportarCaminhoParaFicheiro(int* caminho, int tamanho) {
	// Abre o ficheiro "Caminho.txt" em modo de escrita ("w") ou de adição ("a") consoante o valor de caminhoJaExportado
	FILE* fp = fopen("Caminho.txt", caminhoJaExportado ? "a" : "w");
	if (fp == NULL) return -1;
	for (int i = 0; i < tamanho; i++) {
		fprintf(fp, "%d;", caminho[i]);
	}
	fprintf(fp, "\n");

	fclose(fp);
	caminhoJaExportado = true;

	return 1;
}

#pragma endregion

#pragma region METE NÃO VISITADO

/**
 * @brief Inicializa todos os vértices do grafo como não visitados.
 *
 * @param grafo Apontador para o grafo que terá seus vértices inicializados.
 */
bool InicializarVisitados(Grafo* grafo) {
	if (grafo == NULL)return false;
	Vertice* atual = grafo->inicio;
	while (atual != NULL) {
		// Percorre todos os vértices do grafo e marca cada um como não visitado
		atual->visitado = false;
		atual = atual->pVertice;
	}
	return true;
}

#pragma endregion

#pragma region SOMA CAMINHO

/**
 * @brief Calcula a soma dos valores dos vértices em um caminho.
 *
 * @param grafo Apontador para o grafo onde os vértices estão localizados.
 * @param caminho Apontador que contem os identificadores dos vértices no caminho.
 * @param tam O número de vértices no caminho.
 * @return int A soma dos valores dos vértices no caminho, ou -1 se o caminho for inválido.
 */
int SomaCaminho(Grafo* grafo, int* caminho, int tam) {
	if (*caminho == NULL) return -1;
	int soma = 0;
	for (int i = 0; i < tam; i++) {
		if (caminho[i]) { // Encontra o vértice no grafo e adiciona seu valor à soma
			Vertice* aux = OndeEstaVerticeGrafo(grafo, caminho[i]);
			soma += aux->valor;
		}
	}
	return soma;
}

#pragma endregion

#pragma endregion

#pragma region FASE 2 - ex5

/**
 * @brief Calcula a soma máxima dos valores dos vértices em todos os caminhos lidos de um ficheiro.
 *
 * @param grafo Apontador para o grafo onde os vértices estão localizados.
 * @param nLinha Apontador para armazenar os índices das linhas com a maior soma.
 * @return int A soma máxima dos valores dos vértices nos caminhos, ou -1 se ocorrer um erro.
 */
int SomaMaximaCaminhos(Grafo* grafo, int* nLinha) {
	FILE* fp = fopen("Caminho.txt", "r");
	if (fp == NULL) return -1;

	int maiorSoma = 0;
	int valor;
	int soma = 0;
	int i = 0;
	int u = 0;

	while (fscanf(fp, "%d;", &valor) != EOF) {
		Vertice* aux = OndeEstaVerticeGrafo(grafo, valor);
		if (aux == NULL) {
			fclose(fp);
			return -1;
		}
		soma += aux->valor; // Adicionar o valor do vértice à soma

		char e;
		fscanf(fp, "%c", &e); // Ler o próximo caracter porque pode ser um número ou '\n')
		if (e == '\n' || feof(fp)) { // Se o caracter for '\n' ou o final do arquivo, atualizar a maior soma
			u++;
			if (soma > maiorSoma) {
				nLinha[i] = u;
				i++;
				maiorSoma = soma;
			}
			soma = 0; // Reinicia a soma para a próxima linha
		}
		else {
			ungetc(e, fp); // Devolve o caracter lido para o buffer para que seja lido na próxima iteração
		}
	}

	fclose(fp);
	return maiorSoma;
}

#pragma endregion


