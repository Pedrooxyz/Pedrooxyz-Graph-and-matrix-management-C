/*****************************************************************//**
 * \file   CriacaoVertice.c
 * \brief  Funcao de cria��o de um V�rtice
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo v�rtice com um identificador e valor espec�ficos.
 *
 * @param id Identificador do v�rtice.
 * @param valor Valor associado ao v�rtice.
 * @return Apontador para o v�rtice criado.
 */
Vertice* CriarVertice(int id, int valor) {
	Vertice* novo = (Vertice*)malloc(sizeof(Vertice)); //Aloca a mem�ria necess�ria para o V�rtice
	novo->cod = id;
	novo->valor = valor;
	novo->visitado = false;
	novo->pAdj = NULL;
	novo->pVertice = NULL;
	//Inicia as vari�veis da struct
	return novo;
}