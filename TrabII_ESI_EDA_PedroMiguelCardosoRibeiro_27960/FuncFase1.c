/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  Funções para manipulação de Matrizes, etapa 1 do Trabalho Prático de Estruturas Avançadas de Dados
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
 * @brief Insere um novo elemento contendo um número no final de uma linha da matriz.
 *
 * Esta função aloca memória para um novo elemento da lista ligada e atribui o valor especificado a ele.
 * O novo elemento é inserido no final da linha especificada.
 *
 * @param linha Um apontador para a linha onde o novo elemento será inserido.
 * @param valor O valor a ser atribuído ao novo elemento.
 * @return true se o novo elemento foi inserido com sucesso, false se a alocação de memória falhou.
 */
bool InsereElemento(Linha* linha, int valor) {
    Elemento* novo = CriarNumero(valor);
    if (linha->inicio == NULL) {
        linha->inicio = novo;
    }
    else {
        Elemento* aux = linha->inicio;
        while (aux->proximo != NULL) { //Avança até ao ultimo vértice
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
 * Esta função lê os valores de uma matriz armazenada em um ficheiro e cria uma lista ligada com essa matriz.
 * Cada linha do ficheiro representa uma linha da matriz, com os valores separados por ponto e vírgula (;).
 *
 * @param nomeFicheiro O nome do ficheiro que contém os dados da matriz a ser carregada.
 * @return Um apontador para a lista ligada que representa a matriz carregada, ou NULL se houver falha ao abrir o ficheiro.
 *
 * @note Esta função assume que o arquivo está no formato correto, com valores separados por ponto e vírgula e uma linha por linha.
 * Se ocorrer algum erro durante a leitura do ficheiro ou alocação de memória, a função retorna NULL.
 */
Linha* CarregarMatriz(char* nomeFicheiro) {
    FILE* fp = fopen(nomeFicheiro, "r");
    if (fp == NULL) return NULL;
    Linha* matriz = NULL;
    int valores[MAX];
    int numColunas = 0;
    int valor;
    char ch;
    while (fscanf(fp, "%d", &valor) == 1) { //Avança dentro da própria linha
        valores[numColunas] = valor;
        numColunas++;
        if (fscanf(fp, "%c", &ch) == EOF || ch == '\n') { //Avança de linha
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
 * @brief Altera um valor específico em todos os elementos de uma matriz.
 *
 * Esta função percorre todos os elementos da lista ligada e substitui um valor específico por outro.
 *
 * @param matriz Um apontador para o início da lista ligada.
 * @param numParaMudar O valor a ser alterado em todos os elementos da matriz.
 * @param numNovo O novo valor que substituirá o valor a ser alterado.
 * @return true se pelo menos um valor foi alterado com sucesso, false se a matriz estiver vazia.
  */
bool AlterarValor(Elemento* matriz, int numParaMudar, int numNovo) {
    if (matriz == NULL) return false;
    Linha* linhaAtual = matriz;
    bool aux = false;
    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->inicio;
        while (elementoAtual != NULL) { 
            if (elementoAtual->valor == numParaMudar) { //Encontra o vertice com o número para mudar
                elementoAtual->valor = numNovo; //Dá ao valor o numero novo
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
 * Esta função aloca memória para uma nova linha da matriz e insere os valores especificados nessa linha.
 * A nova linha é adicionada ao final da matriz.
 *
 * @param matriz Um apontador para o apontaador do início da lista ligada.
 * @param valores Um array de inteiros contendo os valores a serem inseridos na nova linha.
 * @param numColunas O número de colunas na nova linha.
 * @return true se a nova linha foi inserida com sucesso, false se houve falha na alocação de memória.
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
 * Esta função percorre todas as linhas da matriz e insere os valores especificados como uma nova coluna no final de cada linha.
 *
 * @param matriz Um apontador para o início da lista ligada que representa a matriz.
 * @param valoresColuna Um array de inteiros que contem os valores a serem inseridos como uma nova coluna.
 * @param tamanho O número de elementos no array de valoresColuna.
 */
bool InserirColunaFim(Linha* matriz, int* valoresColuna, int tamanho) {
    if (matriz == NULL) return false;
    Linha* linhaAtual = matriz;
    int i = 0;
    while (linhaAtual != NULL && i < tamanho) { //Viaja até ao ultimo elemento de cada linha
        InsereElemento(linhaAtual, valoresColuna[i]); //Insere um elemento lá
        i++;
        linhaAtual = linhaAtual->proxima;
    }
    return true;
}

/**
 * @brief Insere uma nova coluna na posição especificada em todas as linhas da matriz representada por uma lista ligada.
 *
 * Esta função percorre todas as linhas da matriz e insere os valores especificados como uma nova coluna na posição indicada.
 *
 * @param matriz Um apontador para o início da lista ligada que representa a matriz.
 * @param valoresColuna Um array de inteiros que contem os valores a serem inseridos como uma nova coluna.
 * @param posicao A posição na qual a nova coluna será inserida.
 *
 * @return true se a nova coluna foi inserida com sucesso em todas as linhas, false se houve falha na alocação de memória.
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
        while (elementoAtual != NULL && cont < posicao) { // Percorre a linha até a posição desejada
            anterior = elementoAtual;
            elementoAtual = elementoAtual->proximo;
            cont++;
        }
        if (anterior == NULL) { // Insere o novo elemento na posição correta
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
 * Esta função remove a linha na posição especificada da matriz.
 *
 * @param matriz Um apontador para o apontador do início da lista ligada.
 * @param pos A posição da linha a ser removida.
 * @return true se a linha foi removida com sucesso, false se a posição especificada for inválida ou se a matriz estiver vazia.
 */
bool RemoveLinha(Linha** matriz, int pos) {
    Linha* temp = *matriz;
    Linha* anterior = NULL;
    while (temp != NULL && pos > 0) {    // Percorre a lista de linhas até a posição especificada
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

    // Libera a memória dos elementos da linha removida
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
 * @brief Remove a coluna na posição especificada de todas as linhas da matriz.
 *
 * Esta função percorre todas as linhas da matriz e remove o elemento na posição indicada.
 *
 * @param matriz Um apontador para o início da lista ligada que representa a matriz.
 * @param posicao A posição da coluna a ser removida.
 * @return true se a coluna foi removida com sucesso de todas as linhas, false se a posição especificada for inválida ou se a matriz estiver vazia.
 */
bool RemoverColuna(Linha* matriz, int posicao) {
    Linha* linhaAtual = matriz;

    while (linhaAtual != NULL) {
        Elemento* elementoAtual = linhaAtual->inicio;
        Elemento* anterior = NULL;
        int contElemento = 0;

        // Percorre os elementos da linha até a posição especificada
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
 * @brief Calcula a soma dos valores máximos de cada linha em uma matriz.
 *
 * Esta função percorre todas as linhas da matriz e calcula a soma dos valores máximos de cada linha.
 *
 * @param matriz Um apontador para o início da lista ligada.
 * @return A soma dos valores máximos de todas as linhas da matriz, ou -1 se a matriz estiver vazia.
 */
int SomaMaxima(Linha* matriz) {
    int soma = 0;
    if (matriz == NULL) return -1;
    Linha* linha = matriz;
    while (linha != NULL) {
        Elemento* elemento = linha->inicio;
        int maximo = 0;

        // Encontra o valor máximo na linha atual
        while (elemento != NULL) {
            if (elemento->valor > maximo) {
                maximo = elemento->valor;
            }
            elemento = elemento->proximo;
        }

        // Soma o valor máximo encontrado na linha atual
        soma += maximo;

        // Avança para a próxima linha
        if (linha->proxima == NULL) break;
        linha = linha->proxima;
    }
    return soma;
}

#pragma endregion
