#pragma once

#include <iostream>

using namespace std;

class Aluno
{
public:
    unsigned chave;
    string nome;

    Aluno()
    {
        chave = 0;
        nome = "Dummy";
    }
    Aluno(unsigned chave, const string &nome)
    {
        this->chave = chave;
        this->nome = nome;
    }
    ~Aluno() {}

    void imprime() const
    {
        cout << "<" << chave << "," << nome << "> ";
    }

};
