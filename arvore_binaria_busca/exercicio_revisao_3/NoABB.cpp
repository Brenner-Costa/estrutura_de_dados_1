
#include "NoABB.h"

#include <iostream>
using namespace std;


NoABB::NoABB(int chave) {
    this->chave = chave;
    this->esq = NULL;
    this->dir = NULL;
}

NoABB::~NoABB() {
    //cout << "Destrutor chamado para chave " << chave << endl;
}

int NoABB::getChave() {
    return chave;
}

NoABB *NoABB::getEsq() {
    return esq;
}

NoABB *NoABB::getDir() {
    return dir;
}

void NoABB::setChave(int chave) {
    this->chave = chave;
}

void NoABB::setEsq(NoABB *esq) {
    this->esq = esq;
}

void NoABB::setDir(NoABB *dir) {
    this->dir = dir;
}
