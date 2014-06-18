#ifndef ARVOREHUFFMAN_H
#define ARVOREHUFFMAN_H
#include <vector>
#include "Cell.h"
#include<QDebug>
#include<QString>
#include<stdio.h>
#include <iostream>
using namespace std;

class ArvoreHuffman
{
    vector<cell> arvoredehuffman;
    cell ref;
    int size;
    QString Huffmanrepresentation;
public:
    ArvoreHuffman();
    cell arvoredehuffmanAT(int pos);
    void setArvoredeHuffman(int pos, cell nil);
    int getsize();
    void inserir(cell nova);
    void bubbleHuff();
    void swap(cell &prev, cell &next);
    void buildhuff();
    QString print();


};

#endif // ARVOREHUFFMAN_H
