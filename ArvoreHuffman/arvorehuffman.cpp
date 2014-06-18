#include "arvorehuffman.h"

ArvoreHuffman::ArvoreHuffman()
{
    arvoredehuffman.reserve(258);
    size = 0;
}


cell ArvoreHuffman::arvoredehuffmanAT(int pos)
{
    return arvoredehuffman[pos];
}
void ArvoreHuffman::setArvoredeHuffman(int pos, cell nil)
{
    arvoredehuffman[pos] = nil;
}
int ArvoreHuffman::getsize()
{
  return size;
}
void ArvoreHuffman::inserir(cell nova)
{
    if(nova.getSize()!=0 && (int)nova.getElement()!=10)
    {
        size++;
        arvoredehuffman[size] = nova;
    }
}
void ArvoreHuffman::swap(cell &prev, cell &next)
{
    cell aux= prev;
    prev=next;
    next=aux;
}
void ArvoreHuffman::bubbleHuff()
{
    for(int i = 1;i<=size;i++)
    {
        for(int j = 1; j<size;j++)
        {
            if(arvoredehuffman[j+1].IsMore(arvoredehuffman[j]))
            {
                swap(arvoredehuffman[j],arvoredehuffman[j+1]);
            }
        }
    }
    cell* left =new cell();
    *left=arvoredehuffman[size];
    cell* right= new cell();
    *right=arvoredehuffman[size-1];
    size = size-2;
    ref= cell(left->getSize()+right->getSize(),left,right);
    this->inserir(ref);
}
void ArvoreHuffman::buildhuff()
{
    while(size>1)
    {
        this->bubbleHuff();
    }
}

QString ArvoreHuffman::print()
{
    return Huffmanrepresentation;
}

