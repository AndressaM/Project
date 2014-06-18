#include"Cell.h"
#include <stdio.h>
cell::cell()
{

}
cell::cell(int size, cell* left, cell* right)
{
    {
        this->size=size;
        leaf=false;
        this->left=left;
        this->right=right;
    }
}
cell::cell(char element, int size)
{
    this->size=size;
    this->element=element;
    leaf=true;
}
bool cell::IsMore(cell cell)
{
    if(this->size>=cell.size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int cell::getSize()
{
    return this->size;
}
char cell::getElement()
{
    if(this->leaf)
    {
        return this->element;

    }
    else
    {
        return ' ';
    }
}

void cell::setHuffmanRepresentation(int huffman)
{
    sprintf(this->HuffmanRepresentation,"%d",huffman);
}

QString cell::getHuffmanRepresentation()
{
    return QString(HuffmanRepresentation).remove(0,1);;
}
