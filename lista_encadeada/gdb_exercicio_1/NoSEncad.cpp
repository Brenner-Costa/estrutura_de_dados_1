#include "NoSEncad.h"


NoSEncad::NoSEncad(): info(0), proximo(nullptr) 
{}


NoSEncad::NoSEncad(int valor):info(valor),proximo(nullptr)
{}


NoSEncad::NoSEncad(int valor, NoSEncad* p):info(valor), proximo(p)
{}


int  NoSEncad::ObterValor()
{
    return info;
}
        
void NoSEncad::AlteraValor(int valor)
{
    this->info = valor;
}

        
NoSEncad* NoSEncad::ObterProximo()
{
    return this->proximo;

}
        
void  NoSEncad::AlteraProximo(NoSEncad* p)
{
    this->proximo = p;
}

        
NoSEncad::~NoSEncad()
{ }