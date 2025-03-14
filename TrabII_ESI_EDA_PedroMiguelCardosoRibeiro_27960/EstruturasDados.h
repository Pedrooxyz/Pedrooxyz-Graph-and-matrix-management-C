#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define c 5
#define MAX 100
#define MAX_LINHAS 5
#define MAX_COLUNAS 5

#pragma warning (disable:4996)

#pragma region FASE 1 - ex1

/**
 * @brief Estrutura para representar um elemento de uma linha da matriz.
 */
typedef struct Elemento {
	int valor;                 /**< Valor do elemento. */
	struct Elemento* proximo;  /**< Ponteiro para o próximo elemento na linha. */
} Elemento;

/**
 * @brief Estrutura para representar uma linha da matriz.
 */
typedef struct Linha {
	Elemento* inicio;         /**< Ponteiro para o primeiro elemento da linha. */
	struct Linha* proxima;    /**< Ponteiro para a próxima linha na matriz. */
} Linha;

#pragma endregion

#pragma region FASE 2 - ex1

/**
 * @brief Estrutura para representar os vértices adjacentes.
 */
typedef struct Adj {
	int cod;         /**< Código do vértice adjacente */
	int peso;        /**< Peso da aresta que liga o vértice atual ao vértice adjacente */
	bool visitado;   /**< Flag para verificar se o vértice adjacente foi visitado */
	struct Adj* pAdj; /**< Aponta para o próximo vértice adjacente */
} Adj;

/**
 * @brief Estrutura para representar os vértices do grafo.
 */
typedef struct Vertice {
	int cod;             /**< Código do vértice */
	int valor;           /**< Valor associado ao vértice */
	bool visitado;       /**< Flag para verificar se o vértice foi visitado */
	struct Adj* pAdj;    /**< Aponta para o primeiro vértice adjacente */
	struct Vertice* pVertice; /**< Aponta para o próximo vértice no grafo */
} Vertice;

/**
 * @brief Estrutura para representar o grafo.
 */
typedef struct Grafo {
	Vertice* inicio;    /**< Aponta para o primeiro vértice no grafo */
	int verticesagora;  /**< Número atual de vértices no grafo */
	int totvertices;    /**< Número total de vértices permitidos no grafo */
} Grafo;

#pragma endregion

Elemento* CriarNumero(int num);
Grafo* CriarGrafo(int v);
Vertice* CriarVertice(int id);
Adj* CriarAdj(int id, int peso);
