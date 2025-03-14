/*****************************************************************//**
 * \file   CriacaoVertice.c
 * \brief  Funcao de criação de um Vértice
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo vértice com um identificador e valor específicos.
 *
 * @param id Identificador do vértice.
 * @param valor Valor associado ao vértice.
 * @return Apontador para o vértice criado.
 */
Vertice* CriarVertice(int id, int valor) {
	Vertice* novo = (Vertice*)malloc(sizeof(Vertice)); //Aloca a memória necessária para o Vértice
	novo->cod = id;
	novo->valor = valor;
	novo->visitado = false;
	novo->pAdj = NULL;
	novo->pVertice = NULL;
	//Inicia as variáveis da struct
	return novo;
}