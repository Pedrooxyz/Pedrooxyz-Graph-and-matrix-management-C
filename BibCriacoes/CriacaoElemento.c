/*****************************************************************//**
 * \file   CriacaoElemento.c
 * \brief  Funcao de cria��o de um elemento
 * 
 * \author PedroRibeiro n�27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo elemento contendo um n�mero.
 *
 * Esta fun��o aloca mem�ria para um novo elemento da lista ligada e atribui o valor especificado a ele.
 *
 * @param num O n�mero a ser atribu�do ao novo elemento.
 * @return Um apontador para o novo elemento criado, ou NULL se a aloca��o de mem�ria falhar.
 */
Elemento* CriarNumero(int num) {
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento)); //Aloca a mem�ria necess�ria para um elemento
    if (aux == NULL) return aux;
    aux->valor = num;
    aux->proximo = NULL;
    //Inicia as vari�veis da struct
    return aux;
}