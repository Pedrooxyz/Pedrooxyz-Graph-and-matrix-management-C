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
	struct Elemento* proximo;  /**< Ponteiro para o pr�ximo elemento na linha. */
} Elemento;

/**
 * @brief Estrutura para representar uma linha da matriz.
 */
typedef struct Linha {
	Elemento* inicio;         /**< Ponteiro para o primeiro elemento da linha. */
	struct Linha* proxima;    /**< Ponteiro para a pr�xima linha na matriz. */
} Linha;

#pragma endregion

#pragma region FASE 2 - ex1

/**
 * @brief Estrutura para representar os v�rtices adjacentes.
 */
typedef struct Adj {
	int cod;         /**< C�digo do v�rtice adjacente */
	int peso;        /**< Peso da aresta que liga o v�rtice atual ao v�rtice adjacente */
	bool visitado;   /**< Flag para verificar se o v�rtice adjacente foi visitado */
	struct Adj* pAdj; /**< Aponta para o pr�ximo v�rtice adjacente */
} Adj;

/**
 * @brief Estrutura para representar os v�rtices do grafo.
 */
typedef struct Vertice {
	int cod;             /**< C�digo do v�rtice */
	int valor;           /**< Valor associado ao v�rtice */
	bool visitado;       /**< Flag para verificar se o v�rtice foi visitado */
	struct Adj* pAdj;    /**< Aponta para o primeiro v�rtice adjacente */
	struct Vertice* pVertice; /**< Aponta para o pr�ximo v�rtice no grafo */
} Vertice;

/**
 * @brief Estrutura para representar o grafo.
 */
typedef struct Grafo {
	Vertice* inicio;    /**< Aponta para o primeiro v�rtice no grafo */
	int verticesagora;  /**< N�mero atual de v�rtices no grafo */
	int totvertices;    /**< N�mero total de v�rtices permitidos no grafo */
} Grafo;

#pragma endregion

Elemento* CriarNumero(int num);
Grafo* CriarGrafo(int v);
Vertice* CriarVertice(int id);
Adj* CriarAdj(int id, int peso);
