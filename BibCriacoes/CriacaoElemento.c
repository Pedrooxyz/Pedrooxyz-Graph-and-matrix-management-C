/*****************************************************************//**
 * \file   CriacaoElemento.c
 * \brief  Funcao de criação de um elemento
 * 
 * \author PedroRibeiro nº27960 LESI
 * \date   May 2024
 *********************************************************************/

#include "EstruturasDados.h"

/**
 * @brief Cria um novo elemento contendo um número.
 *
 * Esta função aloca memória para um novo elemento da lista ligada e atribui o valor especificado a ele.
 *
 * @param num O número a ser atribuído ao novo elemento.
 * @return Um apontador para o novo elemento criado, ou NULL se a alocação de memória falhar.
 */
Elemento* CriarNumero(int num) {
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento)); //Aloca a memória necessária para um elemento
    if (aux == NULL) return aux;
    aux->valor = num;
    aux->proximo = NULL;
    //Inicia as variáveis da struct
    return aux;
}