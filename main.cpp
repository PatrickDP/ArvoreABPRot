#include <iostream>
#include <locale>
#include "Abp.hpp"
using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Aluno a1(1,"a1");
    Aluno a2(2,"a2");
    Aluno a3(3,"a3");
    Aluno a4(4,"a4");
    Aluno a5(5,"a5");
    Aluno a6(6,"a6");
    Aluno a7(7,"a7");
    Aluno a8(8,"a8");
    Aluno a9(9,"a9");
    Aluno a10(10,"a10");
    Aluno a11(11,"a11");
    Aluno a12(12,"a12");

    ABP abp;

    cout << "\t << Inserção do pai e seus descendentes na árvore binária e impressão >>\n\n"; // OK

    abp.insere(a8);
    abp.insere(a5);
    abp.insere(a3);
    abp.insere(a12);
    abp.insere(a9);
    abp.insere(a4);
    abp.insere(a11);
    abp.insere(a2);
    abp.insere(a6);
    abp.insere(a10);
    abp.insere(a1);
    abp.insere(a7);

    abp.preOrdem(); // 8, 5, 3, 2, 1, 4, 6, 7, 12, 9, 11, 10

    cout << "\n\t\t\t << Busca impressão dos filhos e ancestrais >>\n\n";

    abp.imprimeAncestrais(abp.buscaNodo(10)); // 10, 11, 9, 12, 8
    abp.imprimeAncestrais(abp.buscaNodo(1)); // 1, 2, 3, 5, 8

    cout << "\n\t << Rotaciona à direita, imprime a árvore e ancestrais dos nodos específicos >>\n\n";

    abp.rotacionaDireita();

    abp.preOrdem(); // 5, 3, 2, 1, 4, 8, 6, 7, 12, 9, 11, 10

    cout << endl;

    abp.imprimeAncestrais(abp.buscaNodo(10)); // 10, 11, 9, 12, 8, 5
    abp.imprimeAncestrais(abp.buscaNodo(1)); // 1, 2, 3, 5

    cout << "\n<< Rotaciona à esquerda duas vezes, imprime a árvore e ancestrais dos nodos específicos >>\n\n";

    abp.rotacionaEsquerda();
    abp.rotacionaEsquerda();

    abp.preOrdem(); // 12, 8, 5, 3, 2, 1, 4, 6, 7, 9, 11, 10

    cout << endl;

    abp.imprimeAncestrais(abp.buscaNodo(10)); // 10, 11, 9, 8, 12
    abp.imprimeAncestrais(abp.buscaNodo(1)); // 1, 2, 3, 5, 8, 12

    return 0;
}
