/*****************************************************************//**
 * \file   FuncFase2.c
 * \brief  Fun��es para manipula��o de Grafos, etapa 2 do Trabalho Pr�tico de Estruturas Avan�adas de Dados
 *
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "DeclaracaoFunc.h"

#pragma region FASE 2 - ex1

#pragma region FUNCOES DE INSERCAO

/**
 * @brief Insere um v�rtice em um grafo existente.
 *
 * @param v Apontador para o v�rtice a ser inserido.
 * @param grafo Apontador para o grafo onde o v�rtice ser� inserido.
 * @param res Apontador para a vari�vel de resultado.
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
		// Encontra o �ltimo v�rtice e insere o novo v�rtice no final
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
 * @brief Insere uma adjac�ncia em um grafo existente.
 *
 * @param g Apontador para o grafo onde a adjac�ncia ser� inserida.
 * @param origem Identificador do v�rtice de origem da adjac�ncia.
 * @param destino Identificador do v�rtice de destino da adjac�ncia.
 * @param peso Peso da aresta.
 * @param res Apontador para a vari�vel de resultado.
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

	Adj* novo = CriarAdj(destino, peso); //Uso da fun��o de cria��o de uma Adj

	if (novo == NULL) {
		*res = false;
		return g;
	}

	// Insere a nova adjac�ncia no v�rtice de origem
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
 * @brief Retorna um apontador para o v�rtice com o identificador especificado no grafo.
 *
 * @param g Apontador para o grafo onde ser� realizada a busca.
 * @param idVertice Identificador do v�rtice a ser procurado.
 * @return Apontador para o v�rtice encontrado, ou NULL se n�o encontrado.
 */
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice) {
	if (g == NULL) return NULL;
	Vertice* atual = g->inicio;
	while (atual != NULL) {
		if (atual->cod == idVertice) { // Verifica se o c�digo do v�rtice atual tem o id do v�rtice procurado
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
 * @brief Liberta a mem�ria alocada para uma adjac�ncia.
 *
 * @param Adj Apontador para a adjac�ncia a ser destru�da.
 * @return true se a destrui��o foi bem-sucedida, false caso contr�rio.
 */
bool AdjacenteDestruir(Adj* Adj) {
	if (Adj == NULL) return false;
	free(Adj);
	return true;
}

/**
 * @brief Elimina uma adjac�ncia de um v�rtice em um grafo.
 *
 * @param g Apontador para o grafo onde a adjac�ncia ser� eliminada.
 * @param origem Identificador do v�rtice de origem da adjac�ncia.
 * @param destino Identificador do v�rtice de destino da adjac�ncia.
 * @param res Apontador para a vari�vel de resultado.
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

	// Procura a adjac�ncia no v�rtice de origem
	Adj* ant = NULL;
	Adj* aux = atual->pAdj;
	while (aux && aux->cod != destino) {
		ant = aux;
		aux = aux->pAdj;
	}
	if (!aux) return g;

	// Remove a adjac�ncia do v�rtice de origem
	if (!ant) atual->pAdj = aux->pAdj;
	else ant->pAdj = aux->pAdj;

	// Libera a mem�ria alocada para a adjac�ncia removida
	AdjacenteDestruir(aux);

	*res = true;
	return g;
}

/**
 * @brief Elimina todas as adjac�ncias de uma lista de adjac�ncias.
 *
 * @param listaAdj Apontador para a lista de adjac�ncias a serem eliminadas.
 * @param res Apontador para a vari�vel de resultado.
 * @return Apontador nulo, indicando que todas as adjac�ncias foram eliminadas.
 */
Adj* EliminaTodasAdj(Adj* listaAdj, bool* res) {
	*res = false;
	if (listaAdj == NULL) return NULL;

	Adj* aux = listaAdj;
	while (aux) {
		Adj* prox = aux->pAdj;
		AdjacenteDestruir(aux); //Uso da fun��o de destrui��o da Adj apagado a mem�ria, anteriormente alocada
		aux = prox;
	}
	*res = true;
	return NULL;
}

#pragma endregion

#pragma region FUNCOES DE ELIMINACAO DE VERTICE

/**
 * @brief Liberta a mem�ria alocada para um v�rtice.
 *
 * @param v Apontador para o v�rtice a ser destru�do.
 * @return true se a destrui��o foi bem-sucedida, false caso contr�rio.
 */
bool DestroiVertice(Vertice* v) {
	if (v == NULL) return false;
	free(v);
	return true;
}

/**
 * @brief Elimina um v�rtice e suas adjac�ncias de um grafo.
 *
 * @param grafo Apontador para o grafo onde o v�rtice ser� eliminado.
 * @param codVertice Identificador do v�rtice a ser eliminado.
 * @param res Apontador para a vari�vel de resultado.
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

	aux->pAdj=EliminaTodasAdj(aux->pAdj, res); //Como as Adj est�o "ligadas" ao v�rtice e j� n�o � preciso esse espa�o ocupado
	if (*res == false) return grafo;

	DestroiVertice(aux); //Chama a fun��o para tirar a mem�ria alocada anteriormente
	grafo->totvertices--;
	*res = true;
	return grafo;
}

#pragma endregion

#pragma region ELIMINACAO DE GRAFO

/**
 * @brief Liberta a mem�ria alocada para um grafo e todos os seus v�rtices e adjac�ncias.
 *
 * @param grafo Apontador para o grafo a ser destru�do.
 * @return true se a destrui��o foi bem-sucedida, false caso contr�rio.
 */
bool DestruirGrafo(Grafo* grafo) {
	if (grafo == NULL) return false;

	Vertice* atual = grafo->inicio;
	while (atual != NULL) {
		// Armazena o pr�ximo v�rtice antes de liberar o atual, de modo a n�o haver a perda dos pr�ximos v�rtice
		Vertice* proximoVertice = atual->pVertice;
		Adj* adjAtual = atual->pAdj;
		while (adjAtual != NULL) {
			Adj* pAdj = adjAtual->pAdj;
			AdjacenteDestruir(adjAtual); //Uso da fun��o de destruir Adj
			adjAtual = pAdj;
		}
		DestroiVertice(atual); //Uso da fun��o de destruir V�rtice
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
 * @brief Guarda um grafo em um ficheiro bin�rio.
 *
 * @param g apontador para o grafo a ser salvo.
 * @param nomeFicheiro Nome do ficheiro bin�rio onde o grafo ser� guardado.
 * @return true se o grafo foi guardado com sucesso, false caso contr�rio.
 */
bool GuardarGrafo(Grafo* g, char* nomeFicheiro) {
	if (g == NULL || g->inicio == NULL || nomeFicheiro == NULL) return false;

	FILE* fp = fopen(nomeFicheiro, "wb");
	if (fp == NULL) return false;

	Vertice* atual = g->inicio;
	while (atual != NULL) { // Itera sobre os v�rtices
		fwrite(&(atual->valor), sizeof(int), 1, fp); // Escreve o valor do v�rtice
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

#pragma region CONSTRU��O DE GRAFO

/**
 * @brief Constr�i um grafo a partir de um ficheiro contendo uma matriz de adjac�ncia.
 *
 * @param nomeFicheiro Nome do ficheiro contendo a matriz de adjac�ncia.
 * @return Apontador para o grafo constru�do, ou NULL em caso de erro.
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
	LibertarMatriz(matriz); // Libera a mem�ria alocada para a matriz
	return grafo;
}

#pragma endregion

#pragma region LIBERTAR MATRIZ DE APOIO

/**
 * @brief Liberta a mem�ria alocada para uma matriz de adjac�ncia.
 *
 * @param matriz Apontador para a estrutura de dados representando a matriz.
 */
bool LibertarMatriz(Linha* matriz) {
	if (matriz == NULL)return false;
	Linha* linhaAtual = matriz;
	while (linhaAtual != NULL) {
		// Inicia a libera��o dos elementos da linha atual
		Elemento* elementoAtual = linhaAtual->inicio;
		while (elementoAtual != NULL) {
			Elemento* elementoTemp = elementoAtual;
			// Avan�a para o pr�ximo elemento antes de liberar o atual, para nao perder os pr�ximos elementos
			elementoAtual = elementoAtual->proximo;
			free(elementoTemp);
		}
		// Armazena a linha atual temporariamente antes de avan�ar para a pr�xima
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
 * @brief Encontra caminhos entre dois v�rtices em um grafo usando DFT.
 *
 * @param grafo Apontador para o grafo onde os caminhos ser�o buscados.
 * @param origem Identificador do v�rtice de origem.
 * @param destino Identificador do v�rtice de destino.
 * @return true se algum caminho foi encontrado, false caso contr�rio.
 */
bool EncontrarCaminhos(Grafo* grafo, int origem, int destino) {
	//Encontra os dois vertices (da origem e do destino)
	Vertice* vOrigem = OndeEstaVerticeGrafo(grafo, origem);
	Vertice* vDestino = OndeEstaVerticeGrafo(grafo, destino);

	if (vOrigem == NULL || vDestino == NULL) return false;

	int* caminho = (int*)malloc(grafo->totvertices * sizeof(int));

	if (caminho == NULL) return false;

	caminho[0] = vOrigem->cod;

	// Realiza a busca em DFT para encontrar o caminho entre os v�rtices
	bool caminhoEncontrado = BuscaProfundidade(grafo, vOrigem, vDestino, caminho, 1);

	return caminhoEncontrado;
}

/**
 * @brief Realiza uma busca DFT (em profundidade) a partir de um v�rtice em um grafo para encontrar um caminho at� um v�rtice destino.
 *
 * @param grafo Apontador para o grafo onde a busca ser� realizada.
 * @param vertice Apontador para o v�rtice atual.
 * @param destino Apontador para o v�rtice destino.
 * @param caminho Apontador que armazena o caminho encontrado at� o momento.
 * @param pos Posi��o atual no vetor de caminho.
 * @return true se um caminho at� o destino foi encontrado, false caso contr�rio.
 */
bool BuscaProfundidade(Grafo* grafo, Vertice* vertice, Vertice* destino, int* caminho, int pos, bool *enc) {
	vertice->visitado = true;

	// Verifica se o v�rtice atual � o destino
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
				//Recursividade da fun��o, realiza a fun��o a partir do vertice adjacente
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

bool caminhoJaExportado = false; //Var�avel global criada para que a presente vari�vel seja sempre falsa antes que a fun��o a baixo "corra"

/**
 * @brief Exporta o caminho encontrado para um ficheiro.
 *
 * @param caminho Apontador contendo os identificadores dos v�rtices no caminho encontrado.
 * @param tamanho O n�mero de v�rtices no caminho.
 * @return int Retorna 1 se o caminho foi exportado com sucesso, -1 se houve erro na abertura do ficheiro.
 */
int ExportarCaminhoParaFicheiro(int* caminho, int tamanho) {
	// Abre o ficheiro "Caminho.txt" em modo de escrita ("w") ou de adi��o ("a") consoante o valor de caminhoJaExportado
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

#pragma region METE N�O VISITADO

/**
 * @brief Inicializa todos os v�rtices do grafo como n�o visitados.
 *
 * @param grafo Apontador para o grafo que ter� seus v�rtices inicializados.
 */
bool InicializarVisitados(Grafo* grafo) {
	if (grafo == NULL)return false;
	Vertice* atual = grafo->inicio;
	while (atual != NULL) {
		// Percorre todos os v�rtices do grafo e marca cada um como n�o visitado
		atual->visitado = false;
		atual = atual->pVertice;
	}
	return true;
}

#pragma endregion

#pragma region SOMA CAMINHO

/**
 * @brief Calcula a soma dos valores dos v�rtices em um caminho.
 *
 * @param grafo Apontador para o grafo onde os v�rtices est�o localizados.
 * @param caminho Apontador que contem os identificadores dos v�rtices no caminho.
 * @param tam O n�mero de v�rtices no caminho.
 * @return int A soma dos valores dos v�rtices no caminho, ou -1 se o caminho for inv�lido.
 */
int SomaCaminho(Grafo* grafo, int* caminho, int tam) {
	if (*caminho == NULL) return -1;
	int soma = 0;
	for (int i = 0; i < tam; i++) {
		if (caminho[i]) { // Encontra o v�rtice no grafo e adiciona seu valor � soma
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
 * @brief Calcula a soma m�xima dos valores dos v�rtices em todos os caminhos lidos de um ficheiro.
 *
 * @param grafo Apontador para o grafo onde os v�rtices est�o localizados.
 * @param nLinha Apontador para armazenar os �ndices das linhas com a maior soma.
 * @return int A soma m�xima dos valores dos v�rtices nos caminhos, ou -1 se ocorrer um erro.
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
		soma += aux->valor; // Adicionar o valor do v�rtice � soma

		char e;
		fscanf(fp, "%c", &e); // Ler o pr�ximo caracter porque pode ser um n�mero ou '\n')
		if (e == '\n' || feof(fp)) { // Se o caracter for '\n' ou o final do arquivo, atualizar a maior soma
			u++;
			if (soma > maiorSoma) {
				nLinha[i] = u;
				i++;
				maiorSoma = soma;
			}
			soma = 0; // Reinicia a soma para a pr�xima linha
		}
		else {
			ungetc(e, fp); // Devolve o caracter lido para o buffer para que seja lido na pr�xima itera��o
		}
	}

	fclose(fp);
	return maiorSoma;
}

#pragma endregion


