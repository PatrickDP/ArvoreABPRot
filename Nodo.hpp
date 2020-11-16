#pragma once

#include <iostream>
#include "Aluno.hpp"

using namespace std;

class Nodo
{
public:
    Nodo* ptrDir;
    Nodo* ptrEsq;
    Nodo* pai;
    Aluno aluno;

    Nodo()
    {
        ptrDir = NULL;
        ptrEsq = NULL;
        pai = NULL;
    }
    Nodo(const Aluno& novoAluno)
    {
        ptrDir = NULL;
        ptrEsq = NULL;
        pai = NULL;
        aluno = novoAluno;
    }
    ~Nodo() {}

    void preOrdem()
    {
        aluno.imprime();
        if(ptrEsq)
            ptrEsq->preOrdem();
        if(ptrDir)
            ptrDir->preOrdem();
    }
};
