/*****************************************************************//**
 * \file   DeclaracaoFunc.h
 * \brief  Declara��o das fun��es necess�rias � realiza��o do TP - EDA
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#pragma once
#include "EstruturasDados.h"

#pragma region Declara��o das fun��es da Fase 1

//Altera o valor de um elemento da matriz
bool AlterarValor(Elemento* matriz, int numParaMudar, int numNovo);

//Insere um elemento no final da linha da matriz.
bool InsereElemento(Linha* linha, int valor);

//Insere uma nova linha na matriz.
bool InsereLinha(Linha** matriz, int* valores, int numColunas);

//Insere uma nova coluna no final de todas as linhas da matriz.
bool InserirColunaFim(Linha* matriz, int* valoresColuna, int tamanho);

//Insere uma nova coluna em uma posi��o espec�fica de todas as linhas da matriz.
bool InserirColuna(Linha* matriz, int* valoresColuna, int posicao);

//Remove uma linha da matriz.
bool RemoveLinha(Linha** matriz, int pos);

//Remove uma coluna de todas as linhas da matriz.
bool RemoverColuna(Linha* matriz, int posicao);

//Calcula a soma m�xima dos valores na matriz.
int SomaMaxima(Linha* matriz);

//Mostra os elementos da matriz na sa�da padr�o.
void MostraMatriz(Linha* matriz);

//Carrega a matriz no ficheiro
Linha* CarregarMatriz(char* nomeArquivo);

#pragma endregion

#pragma region Declara��o das fun��es da Fase 2

//Mostra os elementos do grafo na sa�da padr�o.
void MostrarGrafo(Grafo* g);

//Insere um novo v�rtice no grafo.
Grafo* InsereVertice(Vertice* v, Grafo* grafo, int* res);

//Insere uma nova adjac�ncia no grafo.
Grafo* InserirAdj(Grafo* g, int origem, int destino, int peso, bool* res);

//Procura e retorna um v�rtice com o ID especificado no grafo.
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice);

//Destroi a estrutura de dados representando uma adjac�ncia.
bool AdjacenteDestruir(Adj* Adj);

//Elimina uma adjac�ncia espec�fica do grafo.
Grafo* EliminaAdj(Grafo* g, int origem, int codAdj, bool* res);

//Elimina todas as adjac�ncias de um v�rtice.
Adj* EliminaTodasAdj(Adj* listaAdj, bool* res);

//Destroi a estrutura de dados representando um v�rtice.
bool DestroiVertice(Vertice* v);

//Elimina um v�rtice espec�fico do grafo.
Grafo* EliminaVertice(Grafo* grafo, int codVertice, bool* res);

//Destroi toda a estrutura de dados representando o grafo.
bool DestruirGrafo(Grafo* grafo);

//Guarda um grafo, como matriz de adjac�ncia, num ficheiro bin�rio
bool GuardarGrafo(Grafo* g, char* nomeFicheiro);

//Constr�i um grafo a partir de um arquivo.
Grafo* ConstruirGrafo(char* nomeFicheiro);

//Libera a mem�ria alocada para a matriz.
bool LibertarMatriz(Linha* matriz);

//Encontra caminhos poss�veis entre dois v�rtices no grafo.
bool EncontrarCaminhos(Grafo* grafo, int origem, int destino);

//Realiza uma busca em profundidade para encontrar caminhos no grafo.
bool BuscaProfundidade(Grafo* grafo, Vertice* vertice, Vertice* destino, int* caminho, int pos);

//Inicializa o estado de visita��o dos v�rtices do grafo.
bool InicializarVisitados(Grafo* grafo);

//Mostra o caminho encontrado na sa�da padr�o.
void MostrarCaminho(int* caminho, int tamanho);

//Exporta o caminho encontrado para um arquivo.
int ExportarCaminhoParaFicheiro(int* caminho, int tamanho);

//Mostra a soma e o caminho entre dois v�rtices no grafo.
void MostraSomaECaminho(Grafo* grafo, int origem, int destino);

//Calcula a soma m�xima das linhas da matriz.
int SomaMaximaCaminhos(Grafo* grafo, int* nLinha);

//Imprime as linhas especificadas de um arquivo na sa�da padr�o.
void ImprimirLinhas(char* nomeFicheiro, int* linhas, int tamanho);

#pragma endregion
