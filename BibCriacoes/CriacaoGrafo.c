/*****************************************************************//**
 * \file   CriacaoGrafo.c
 * \brief  Funcao de criação de um grafo
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo grafo com um número específico de vértices.
 *
 * @param v Número de vértices do grafo.
 * @return Apontador para o grafo criado.
 */
Grafo* CriarGrafo(int v) {
	Grafo* novo = (Grafo*)malloc(sizeof(Grafo)); //Aloca a memória necessária para o grafo
	novo->inicio = NULL;
	novo->verticesagora = 0;
	novo->totvertices = v;
	//Inicia as variáveis da struct
	return(novo);
}

