#pragma once

#include <iostream>
#include "Nodo.hpp"

class ABP
{
public:
    Nodo* raiz;
    ABP()
    {
        raiz = NULL;
    }
    ~ABP()
    {
        cout << "\n\n\t<< DESTRUINDO A ÁRVORE >>\n";
        if(raiz)
            apaga(raiz);
    }
    void preOrdem()
    {
        if(raiz)
            raiz->preOrdem();
        cout << endl;
    }
    void insere(const Aluno& aluno)
    {
        Nodo *novoNodo = NULL;
        Nodo *atualPtrNodo = raiz;

        novoNodo = new Nodo(aluno);
        if(! raiz)
        {
            raiz = novoNodo;
            return;
        }
        while(true)
        {
            if(novoNodo->aluno.chave < atualPtrNodo->aluno.chave)
            {
                if(! atualPtrNodo->ptrEsq)
                {
                    atualPtrNodo->ptrEsq = novoNodo;
                    novoNodo->pai = atualPtrNodo;
                    return;
                }
                else
                {
                    atualPtrNodo = atualPtrNodo->ptrEsq;
                }
            }
            if(novoNodo->aluno.chave > atualPtrNodo->aluno.chave)
            {
                if(! atualPtrNodo->ptrDir)
                {
                    atualPtrNodo->ptrDir = novoNodo;
                    novoNodo->pai = atualPtrNodo;
                    return;
                }
                else
                {
                    atualPtrNodo = atualPtrNodo->ptrDir;
                }
            }
        }
    }
    Nodo* buscaNodo(unsigned chave)
    {
        Nodo* atualPtrNodo = raiz;

        while(atualPtrNodo)
        {
            if(chave == atualPtrNodo->aluno.chave)
            {
                return atualPtrNodo;
            }
            else
            {
                if(chave < atualPtrNodo->aluno.chave)
                {
                    atualPtrNodo = atualPtrNodo->ptrEsq;
                }
                else
                {
                    atualPtrNodo = atualPtrNodo->ptrDir;
                }
            }
        }
        return NULL;
    }
    void imprimeAncestrais(Nodo* nodo) // Utiliza recursividade
    {
        // Caso o nodo não estiver na árvore
        if(! nodo)
        {
            cout << "Não existe o nodo!" << endl;
            return;
        }
        nodo->aluno.imprime();
        if(nodo->pai)
            imprimeAncestrais(nodo->pai);
        else
        {
            cout << endl;
            return;
        }
    }
    void rotacionaDireita()
    {
        Nodo* filhoEsqNodo = raiz->ptrEsq;

        if(! raiz->ptrEsq)
        {
            cout << "ERRO: Filho esquerdo igual a NULL" << endl;
            return;
        }
        raiz->ptrEsq = filhoEsqNodo->ptrDir;
        filhoEsqNodo->ptrDir->pai = raiz;
        filhoEsqNodo->ptrDir = raiz;
        raiz = filhoEsqNodo;
        raiz->ptrDir->pai = raiz;
        raiz->pai = NULL;
    }
    void rotacionaEsquerda()
    {
        Nodo* filhoDirNodo = raiz->ptrDir;

        if(! raiz->ptrDir)
        {
            cout << "ERRO: Filho direito igual a NULL" << endl;
            return;
        }
        raiz->ptrDir = filhoDirNodo->ptrEsq;
        filhoDirNodo->ptrEsq->pai = raiz;
        filhoDirNodo->ptrEsq = raiz;
        raiz = filhoDirNodo;
        raiz->ptrEsq->pai = raiz;
        raiz->pai = NULL;
    }
    void apaga(Nodo *ptrNodo)
    {
        if(ptrNodo->ptrEsq)
            apaga(ptrNodo->ptrEsq);
        if(ptrNodo->ptrDir)
            apaga(ptrNodo->ptrDir);
        cout << "\n\t!" << ptrNodo->aluno.nome;
        delete ptrNodo;
    }
};
