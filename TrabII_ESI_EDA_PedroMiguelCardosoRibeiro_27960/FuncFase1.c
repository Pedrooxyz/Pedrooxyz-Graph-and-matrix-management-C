/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  Fun��es para manipula��o de Matrizes, etapa 1 do Trabalho Pr�tico de Estruturas Avan�adas de Dados
 *
 * \author PedroRibeiro
 * \date   March 2024
 *********************************************************************/

#include "DeclaracaoFunc.h"

#pragma region Inicio

 /*

 bool ExportarMatriz(char* nomeFicheiro, int matriz[MAX_LINHAS][MAX_COLUNAS]) {
     FILE* fp = fopen(nomeFicheiro, "w");
     if (fp == NULL) return false;
     for (int i = 0; i < MAX_LINHAS; i++) {
         for (int j = 0; j < MAX_COLUNAS; j++) {
             fprintf(fp, "%d", matriz[i][j]);
             if (j < MAX_COLUNAS - 1)
                 fprintf(fp, ";");
         }
         fprintf(fp, "\n");
     }
     fclose(fp);
     printf("Dados exportados com sucesso para o arquivo: %s\n", nomeArquivo);
 }

 */

/**
 * @brief Insere um novo elemento contendo um n�mero no final de uma linha da matriz.
 *
 * Esta fun��o aloca mem�ria para um novo elemento da lista ligada e atribui o valor especificado a ele.
 * O novo elemento � inserido no final da linha especificada.
 *
 * @param linha Um apontador para a linha onde o novo elemento ser� inserido.
 * @param valor O valor a ser atribu�do ao novo elemento.
 * @return true se o novo elemento foi inserido com sucesso, false se a aloca��o de mem�ria falhou.
 */
bool InsereElemento(Linha* linha, int valor) {
    Elemento* novo = CriarNumero(valor);
    if (linha->inicio == NULL) {
        linha->inicio = novo;
    }
    else {
        Elemento* aux = linha->inicio;
        while (aux->proximo != NULL) { //Avan�a at� ao ultimo v�rtice
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    return true;
}

#pragma endregion

#pragma region FASE 1 - ex2

/**
 * @brief Carrega uma matriz a partir de um ficheiro.
 *
 * Esta fun��o l� os valores de uma matriz armazenada em um ficheiro e cria uma lista ligada com essa matriz.
 * Cada linha do ficheiro representa uma linha da matriz, com os valores separados por ponto e v�rgula (;).
 *
 * @param nomeFicheiro O nome do ficheiro que cont�m os dados da matriz a ser carregada.
 * @return Um apontador para a lista ligada que representa a matriz carregada, ou NULL se houver falha ao abrir o ficheiro.
 *
 * @note Esta fun��o assume que o arquivo est� no formato correto, com valores separados por ponto e v�rgula e uma linha por linha.
 * Se ocorrer algum erro durante a leitura do ficheiro ou aloca��o de mem�ria, a fun��o retorna NULL.
 */
Linha* CarregarMatriz(char* nomeFicheiro) {
    FILE* fp = fopen(nomeFicheiro, "r");
    if (fp == NULL) return NULL;
    Linha* matriz = NULL;
    int valores[MAX];
    int numColunas = 0;
    int valor;
    char ch;
    while (fscanf(fp, "%d", &valor) == 1) { //Avan�a dentro da pr�pria linha
        valores[numColunas] = valor;
        numColunas++;
        if (fscanf(fp, "%c", &ch) == EOF || ch == '\n') { //Avan�a de linha
            if (!InsereLinha(&matriz, valores, numColunas)) { 
                fclose(fp);
                return NULL;
            }
            numColunas = 0;
        }
    }
    fclose(fp);
    return matriz;
}

#pragma endregion

#pragma region FASE 1 - ex3

/**
 * @brief Altera um valor espec�fico em todos os elementos de uma matriz.
 *
 * Esta fun��o percorre todos os elementos da lista ligada e substitui um valor espec�fico por outro.
 *
 * @param matriz Um apontador para o in�cio da lista ligada.
 * @param numParaMudar O valor a ser alterado em todos os elementos da matriz.
 * @param numNovo O novo valor que substituir� o valor a ser alterado.
 * @return true se pelo menos um valor foi alterado com sucesso, false se a matriz estiver vazia.
  */
bool AlterarValor(Elemento* matriz, int numParaMudar, int numNovo) {
    if (matriz == NULL) return false;
    Linha* linhaAtual = matriz;
    bool aux = false;
    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->inicio;
        while (elementoAtual != NULL) { 
            if (elementoAtual->valor == numParaMudar) { //Encontra o vertice com o n�mero para mudar
                elementoAtual->valor = numNovo; //D� ao valor o numero novo
                aux = true;
            }
            elementoAtual = elementoAtual->proximo;
        }
        linhaAtual = linhaAtual->proxima;
    }
    return aux;
}

#pragma endregion

#pragma region FASE 1 - ex4

/**
 * @brief Insere uma nova linha na matriz na lista ligada.
 *
 * Esta fun��o aloca mem�ria para uma nova linha da matriz e insere os valores especificados nessa linha.
 * A nova linha � adicionada ao final da matriz.
 *
 * @param matriz Um apontador para o apontaador do in�cio da lista ligada.
 * @param valores Um array de inteiros contendo os valores a serem inseridos na nova linha.
 * @param numColunas O n�mero de colunas na nova linha.
 * @return true se a nova linha foi inserida com sucesso, false se houve falha na aloca��o de mem�ria.
 */
bool InsereLinha(Linha** matriz, int* valores, int numColunas) {
    Linha* novaLinha = (Linha*)malloc(sizeof(Linha));
    if (novaLinha == NULL) return false;
    novaLinha->inicio = NULL;
    novaLinha->proxima = NULL;

    for (int i = 0; i < numColunas; i++) {
        InsereElemento(novaLinha, valores[i]); //Insere Elemento a Elemento
    }

    Linha** aux = matriz;
    while (*aux != NULL) {
        aux = &((*aux)->proxima);
    }
    *aux = novaLinha;
    return true;
}

/**
 * @brief Insere uma nova coluna no final de todas as linhas da matriz.
 *
 * Esta fun��o percorre todas as linhas da matriz e insere os valores especificados como uma nova coluna no final de cada linha.
 *
 * @param matriz Um apontador para o in�cio da lista ligada que representa a matriz.
 * @param valoresColuna Um array de inteiros que contem os valores a serem inseridos como uma nova coluna.
 * @param tamanho O n�mero de elementos no array de valoresColuna.
 */
bool InserirColunaFim(Linha* matriz, int* valoresColuna, int tamanho) {
    if (matriz == NULL) return false;
    Linha* linhaAtual = matriz;
    int i = 0;
    while (linhaAtual != NULL && i < tamanho) { //Viaja at� ao ultimo elemento de cada linha
        InsereElemento(linhaAtual, valoresColuna[i]); //Insere um elemento l�
        i++;
        linhaAtual = linhaAtual->proxima;
    }
    return true;
}

/**
 * @brief Insere uma nova coluna na posi��o especificada em todas as linhas da matriz representada por uma lista ligada.
 *
 * Esta fun��o percorre todas as linhas da matriz e insere os valores especificados como uma nova coluna na posi��o indicada.
 *
 * @param matriz Um apontador para o in�cio da lista ligada que representa a matriz.
 * @param valoresColuna Um array de inteiros que contem os valores a serem inseridos como uma nova coluna.
 * @param posicao A posi��o na qual a nova coluna ser� inserida.
 *
 * @return true se a nova coluna foi inserida com sucesso em todas as linhas, false se houve falha na aloca��o de mem�ria.
 */
bool InserirColuna(Linha* matriz, int* valoresColuna, int posicao) {
    Linha* linhaAtual = matriz;
    int i = 0;
    int tamanho = 0;
    while (valoresColuna[tamanho] != -1) tamanho++;
    while (linhaAtual != NULL && i < tamanho) {
        Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
        if (novo == NULL) return false;
        novo->valor = valoresColuna[i];
        novo->proximo = NULL;
        Elemento* elementoAtual = linhaAtual->inicio;
        Elemento* anterior = NULL;
        int cont = 0;
        while (elementoAtual != NULL && cont < posicao) { // Percorre a linha at� a posi��o desejada
            anterior = elementoAtual;
            elementoAtual = elementoAtual->proximo;
            cont++;
        }
        if (anterior == NULL) { // Insere o novo elemento na posi��o correta
            novo->proximo = linhaAtual->inicio;
            linhaAtual->inicio = novo;
        }
        else {
            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }
        i++;
        linhaAtual = linhaAtual->proxima;
    }
}

#pragma endregion

#pragma region FASE 1 - ex5

/**
 * @brief Remove uma linha da lista ligada.
 *
 * Esta fun��o remove a linha na posi��o especificada da matriz.
 *
 * @param matriz Um apontador para o apontador do in�cio da lista ligada.
 * @param pos A posi��o da linha a ser removida.
 * @return true se a linha foi removida com sucesso, false se a posi��o especificada for inv�lida ou se a matriz estiver vazia.
 */
bool RemoveLinha(Linha** matriz, int pos) {
    Linha* temp = *matriz;
    Linha* anterior = NULL;
    while (temp != NULL && pos > 0) {    // Percorre a lista de linhas at� a posi��o especificada
        anterior = temp;
        temp = temp->proxima;
        pos--;
    }
    if (temp == NULL) return false; 

    // Remove a linha da matriz
    if (anterior == NULL) *matriz = temp->proxima; 
    else {
        anterior->proxima = temp->proxima;
    }

    // Libera a mem�ria dos elementos da linha removida
    Elemento* atual = temp->inicio;
    while (atual != NULL) {
        Elemento* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(temp);
    return true;
}

/**
 * @brief Remove a coluna na posi��o especificada de todas as linhas da matriz.
 *
 * Esta fun��o percorre todas as linhas da matriz e remove o elemento na posi��o indicada.
 *
 * @param matriz Um apontador para o in�cio da lista ligada que representa a matriz.
 * @param posicao A posi��o da coluna a ser removida.
 * @return true se a coluna foi removida com sucesso de todas as linhas, false se a posi��o especificada for inv�lida ou se a matriz estiver vazia.
 */
bool RemoverColuna(Linha* matriz, int posicao) {
    Linha* linhaAtual = matriz;

    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->inicio;
        Elemento* anterior = NULL;
        int contElemento = 0;

        // Percorre os elementos da linha at� a posi��o especificada
        while (elementoAtual != NULL && contElemento < posicao) {
            anterior = elementoAtual;
            elementoAtual = elementoAtual->proximo;
            contElemento++;
        }
        if (elementoAtual == NULL) return false;

        // Remove o elemento da coluna
        if (anterior == NULL) {
            linhaAtual->inicio = elementoAtual->proximo;
            free(elementoAtual);
        }
        else {
            anterior->proximo = elementoAtual->proximo;
            free(elementoAtual);
        }
        linhaAtual = linhaAtual->proxima;
    }
    return true;
}

#pragma endregion

#pragma region FASE 1 - ex7

/**
 * @brief Calcula a soma dos valores m�ximos de cada linha em uma matriz.
 *
 * Esta fun��o percorre todas as linhas da matriz e calcula a soma dos valores m�ximos de cada linha.
 *
 * @param matriz Um apontador para o in�cio da lista ligada.
 * @return A soma dos valores m�ximos de todas as linhas da matriz, ou -1 se a matriz estiver vazia.
 */
int SomaMaxima(Linha* matriz) {
    int soma = 0;
    if (matriz == NULL) return -1;
    Linha* linha = matriz;
    while (linha != NULL) {
        Elemento* elemento = linha->inicio;
        int maximo = 0;

        // Encontra o valor m�ximo na linha atual
        while (elemento != NULL) {
            if (elemento->valor > maximo) {
                maximo = elemento->valor;
            }
            elemento = elemento->proximo;
        }

        // Soma o valor m�ximo encontrado na linha atual
        soma += maximo;

        // Avan�a para a pr�xima linha
        if (linha->proxima == NULL) break;
        linha = linha->proxima;
    }
    return soma;
}

#pragma endregion
