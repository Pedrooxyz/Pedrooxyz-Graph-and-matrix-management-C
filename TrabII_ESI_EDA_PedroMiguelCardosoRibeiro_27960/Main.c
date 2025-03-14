/**
 * @brief Fun��o principal do programa.
 *
 * Esta fun��o testa v�rias opera��es relacionadas com grafos e matrizes, incluindo cria��o,
 * inser��o, visualiza��o, altera��o de valores, elimina��o de adjac�ncias e v�rtices,
 * carregamento de matriz a partir de um ficheiro, e buscas em grafos.
 *
 * @return int Retorna 0 em caso de sucesso.
 */

#pragma comment(lib,"BibCriacoes.lib")
#include "EstruturasDados.h"
#include "DeclaracaoFunc.h"



int main() {

    Linha* matriz = NULL;

    int matrizzzz[MAX_LINHAS][MAX_COLUNAS] = {
       {7, 53, 183, 439, 863},
       {497, 383, 563, 79, 973},
       {287, 63, 343, 169, 583},
       {627, 343, 773, 959, 943},
       {767, 473, 103, 699, 303}
    };

    //ExportarMatriz("matriz.txt", matrizzzz);

    int valores1[] = { 14, 22, 63, 75, 216 };
    InsereLinha(&matriz, valores1, 5);

    int valores2[] = { 64, 54, 65, 543, 35 };
    InsereLinha(&matriz, valores2, 5);

    int valores3[] = { 73, 38, 923, 343, 54 };
    InsereLinha(&matriz, valores3, 5);

    printf("FASE 1:\n\n");

    printf("Matriz criada:\n");
    MostraMatriz(matriz);
    printf("\n\n");
    printf("Carregamento da Matriz:\n");

    Linha* matriz2 = CarregarMatriz("MatrizTeste.txt");
    if (matriz2 != NULL) {
        printf("Matriz carregada do ficheiro:\n");
        MostraMatriz(matriz2);
    }
    else {
        printf("Falha ao carregar a matriz do ficheiro.\n");
    }

    printf("\n\n");
    printf("Alterar valor:\n");

    bool sucesso = AlterarValor(matriz, 75, 100);
    if (sucesso) printf("Valor alterado com sucesso.\n");
    MostraMatriz(matriz);

    printf("\n\n");

    Linha* matriz3 = NULL;
    InsereLinha(&matriz3, valores1, 5);
    InsereLinha(&matriz3, valores2, 5);
    bool removido = RemoveLinha(&matriz3, 1);
    if (removido) printf("Linha removida com sucesso.\n");

    printf("\n\n");

    Linha* novaMatriz = NULL;
    int valores10[] = { 5, 8, 3 };
    int valores20[] = { 10, 2, 7 };
    int valores30[] = { 6, 4, 9 };
    InsereLinha(&novaMatriz, valores10, 3);
    InsereLinha(&novaMatriz, valores20, 3);
    InsereLinha(&novaMatriz, valores30, 3);
    int somaMaxima = SomaMaxima(novaMatriz);
    if (somaMaxima == -1) {
        printf("Erro: Matriz n�o inicializada corretamente.\n");
    }
    else {
        printf("A soma m�xima dos valores na nova matriz �: %d\n", somaMaxima);
    }

    printf("\n\n");

    int valoresColuna[] = { 1, 2, 4 };
    int posicao = 2;
    if (InserirColuna(matriz, valoresColuna, posicao)) printf("\nColuna inserida com sucesso!\n");
    printf("Matriz ap�s adicionar a coluna:\n");
    MostraMatriz(matriz);

    printf("\n\n");

    int pos = 2;
    if (RemoverColuna(matriz, posicao)) printf("\nColuna removida com sucesso!\n");
    printf("Matriz ap�s remover a coluna:\n");
    MostraMatriz(matriz);


    printf("\n\n");
    printf("FUNCOES DE CRIA��O INSER��O E DE MOSTRAR");

    Grafo* meuGrafo = CriarGrafo(4);
    if (meuGrafo == NULL) printf("Erro ao criar o grafo.\n");

    int resultado;
    for (int i = 0; i < 4; i++) {
        Vertice* novoVertice = CriarVertice(i, i * 5);
        meuGrafo = InsereVertice(novoVertice, meuGrafo, &resultado);
        if (resultado != 1) printf("Erro ao inserir v�rtice %d.\n", i);
    }

    bool res;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                meuGrafo = InserirAdj(meuGrafo, i, j, 1, &res); // Peso 1
                if (!res) printf("Erro ao inserir adjac�ncia entre %d e %d.\n", i, j);

            }
        }
    }

    MostrarGrafo(meuGrafo);

    printf("\n\n");
    printf("FUNCAO DE PROCURA\n\n");

    int idProcurado = 2;
    Vertice* verticeProcurado = OndeEstaVerticeGrafo(meuGrafo, idProcurado);
    if (verticeProcurado != NULL) {
        printf("O v�rtice com ID %d foi encontrado.\n", idProcurado);
    }
    else {
        printf("O v�rtice com ID %d n�o foi encontrado.\n", idProcurado);
    }

    printf("\n\n");
    printf("FUNCOES DE ELIMINA��O DE ADJ\n\n");

    int o = 2;
    int d = 3;
    meuGrafo = EliminaAdj(meuGrafo, o, d, &res);
    if (res) {
        printf("Adjac�ncia de %d a %d eliminada com sucesso.\n", o, d);
    }
    else {
        printf("Erro ao eliminar a adjac�ncia de %d a %d.\n", o, d);
    }

    MostrarGrafo(meuGrafo);


    printf("\n\n");
    printf("FUNCOES DE ELIMINA��O DE VERTICE\n\n");

    int vElim = 1;
    meuGrafo = EliminaVertice(meuGrafo, vElim, &res);
    if (res) {
        printf("Vertice %d eliminado com sucesso.\n\n", vElim);
    }
    else {
        printf("Erro a eliminar vert�ce\n\n");
    }

    MostrarGrafo(meuGrafo);

    printf("\n\n");
    printf("FUNCAO DE PRESERVA��O DE UM FICHEIRO");

    if (GuardarGrafo(meuGrafo, "guardar.bin")) printf("Preserva��o feita com sucesso\n\n");

    printf("\n\n");
    printf("FUNCAO DE CARREGAMENTO DE MATTRIZ DE UM FICHEIRO\n\n");


    char nomeFicheiro[] = "MatrizTeste.txt";

    Grafo* grafo = ConstruirGrafo(nomeFicheiro);
    if (grafo == NULL) {
        printf("Erro ao construir o grafo.\n");
        return 1;
    }
    printf("Grafo constru�do a partir da matriz:\n");
    MostrarGrafo(grafo);

    printf("FUNCAO DE BUSCAR EM LARGURA\n\n");

    printf("Caminhos poss�veis de 1 a 4:\n");

    InicializarVisitados(grafo);
    EncontrarCaminhos(grafo, 1, 4);

    printf("\n\n");
    printf("SOMA DE UM CAMINHO ESPECIFICA\n\n");

    MostraSomaECaminho(grafo, 1, 4);

    return 0;
}
