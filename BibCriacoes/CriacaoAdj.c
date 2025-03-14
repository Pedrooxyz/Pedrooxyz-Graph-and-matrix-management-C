/*****************************************************************//**
 * \file   CriacaoAdj.c
 * \brief  Funcao de criação de uma Adjacencia
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria uma nova adjacência com um identificador e peso específicos.
 *
 * @param id Identificador do vértice adjacente.
 * @param peso Peso da aresta.
 * @return Apontador para a adjacência criada.
 */
Adj* CriarAdj(int id, int peso) {
	Adj* novo = (Adj*)malloc(sizeof(Adj)); //Aloca a memória necessária para o Vértice
	novo->cod = id;
	novo->visitado = false;
	novo->peso = peso;
	novo->pAdj = NULL;
	//Inicia as variáveis da struct
	return novo;
}