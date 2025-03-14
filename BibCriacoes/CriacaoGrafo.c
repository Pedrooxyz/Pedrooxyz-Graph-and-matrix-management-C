/*****************************************************************//**
 * \file   CriacaoGrafo.c
 * \brief  Funcao de cria��o de um grafo
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo grafo com um n�mero espec�fico de v�rtices.
 *
 * @param v N�mero de v�rtices do grafo.
 * @return Apontador para o grafo criado.
 */
Grafo* CriarGrafo(int v) {
	Grafo* novo = (Grafo*)malloc(sizeof(Grafo)); //Aloca a mem�ria necess�ria para o grafo
	novo->inicio = NULL;
	novo->verticesagora = 0;
	novo->totvertices = v;
	//Inicia as vari�veis da struct
	return(novo);
}

