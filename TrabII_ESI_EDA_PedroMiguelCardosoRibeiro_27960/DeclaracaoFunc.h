/*****************************************************************//**
 * \file   DeclaracaoFunc.h
 * \brief  Declaração das funções necessárias à realização do TP - EDA
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#pragma once
#include "EstruturasDados.h"

#pragma region Declaração das funções da Fase 1

//Altera o valor de um elemento da matriz
bool AlterarValor(Elemento* matriz, int numParaMudar, int numNovo);

//Insere um elemento no final da linha da matriz.
bool InsereElemento(Linha* linha, int valor);

//Insere uma nova linha na matriz.
bool InsereLinha(Linha** matriz, int* valores, int numColunas);

//Insere uma nova coluna no final de todas as linhas da matriz.
bool InserirColunaFim(Linha* matriz, int* valoresColuna, int tamanho);

//Insere uma nova coluna em uma posição específica de todas as linhas da matriz.
bool InserirColuna(Linha* matriz, int* valoresColuna, int posicao);

//Remove uma linha da matriz.
bool RemoveLinha(Linha** matriz, int pos);

//Remove uma coluna de todas as linhas da matriz.
bool RemoverColuna(Linha* matriz, int posicao);

//Calcula a soma máxima dos valores na matriz.
int SomaMaxima(Linha* matriz);

//Mostra os elementos da matriz na saída padrão.
void MostraMatriz(Linha* matriz);

//Carrega a matriz no ficheiro
Linha* CarregarMatriz(char* nomeArquivo);

#pragma endregion

#pragma region Declaração das funções da Fase 2

//Mostra os elementos do grafo na saída padrão.
void MostrarGrafo(Grafo* g);

//Insere um novo vértice no grafo.
Grafo* InsereVertice(Vertice* v, Grafo* grafo, int* res);

//Insere uma nova adjacência no grafo.
Grafo* InserirAdj(Grafo* g, int origem, int destino, int peso, bool* res);

//Procura e retorna um vértice com o ID especificado no grafo.
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice);

//Destroi a estrutura de dados representando uma adjacência.
bool AdjacenteDestruir(Adj* Adj);

//Elimina uma adjacência específica do grafo.
Grafo* EliminaAdj(Grafo* g, int origem, int codAdj, bool* res);

//Elimina todas as adjacências de um vértice.
Adj* EliminaTodasAdj(Adj* listaAdj, bool* res);

//Destroi a estrutura de dados representando um vértice.
bool DestroiVertice(Vertice* v);

//Elimina um vértice específico do grafo.
Grafo* EliminaVertice(Grafo* grafo, int codVertice, bool* res);

//Destroi toda a estrutura de dados representando o grafo.
bool DestruirGrafo(Grafo* grafo);

//Guarda um grafo, como matriz de adjacência, num ficheiro binário
bool GuardarGrafo(Grafo* g, char* nomeFicheiro);

//Constrói um grafo a partir de um arquivo.
Grafo* ConstruirGrafo(char* nomeFicheiro);

//Libera a memória alocada para a matriz.
bool LibertarMatriz(Linha* matriz);

//Encontra caminhos possíveis entre dois vértices no grafo.
bool EncontrarCaminhos(Grafo* grafo, int origem, int destino);

//Realiza uma busca em profundidade para encontrar caminhos no grafo.
bool BuscaProfundidade(Grafo* grafo, Vertice* vertice, Vertice* destino, int* caminho, int pos);

//Inicializa o estado de visitação dos vértices do grafo.
bool InicializarVisitados(Grafo* grafo);

//Mostra o caminho encontrado na saída padrão.
void MostrarCaminho(int* caminho, int tamanho);

//Exporta o caminho encontrado para um arquivo.
int ExportarCaminhoParaFicheiro(int* caminho, int tamanho);

//Mostra a soma e o caminho entre dois vértices no grafo.
void MostraSomaECaminho(Grafo* grafo, int origem, int destino);

//Calcula a soma máxima das linhas da matriz.
int SomaMaximaCaminhos(Grafo* grafo, int* nLinha);

//Imprime as linhas especificadas de um arquivo na saída padrão.
void ImprimirLinhas(char* nomeFicheiro, int* linhas, int tamanho);

#pragma endregion
