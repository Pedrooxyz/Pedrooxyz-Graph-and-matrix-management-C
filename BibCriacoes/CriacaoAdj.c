/*****************************************************************//**
 * \file   CriacaoAdj.c
 * \brief  Funcao de cria��o de uma Adjacencia
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria uma nova adjac�ncia com um identificador e peso espec�ficos.
 *
 * @param id Identificador do v�rtice adjacente.
 * @param peso Peso da aresta.
 * @return Apontador para a adjac�ncia criada.
 */
Adj* CriarAdj(int id, int peso) {
	Adj* novo = (Adj*)malloc(sizeof(Adj)); //Aloca a mem�ria necess�ria para o V�rtice
	novo->cod = id;
	novo->visitado = false;
	novo->peso = peso;
	novo->pAdj = NULL;
	//Inicia as vari�veis da struct
	return novo;
}