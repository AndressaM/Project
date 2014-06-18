#include "File.cpp"
#include<QDebug>
#include<QString>
#include"Cell.h"
#include "arvorehuffman.h"
#include<stdio.h>
#include <iostream>
#include <unistd.h>
#include<bitvector.h>

using namespace std;
void printTree(cell* node , int level = 1)
{
    if(node->leaf != true)
    {
        printTree(node->left, level +1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getSize() <<endl;
        printTree(node->right,level +1);
    }
    if(node->leaf)
    {
        cout << qPrintable(QString("\t").repeated(level)) << node->getElement() <<endl;
    }

}

QString TreeRepresetation(cell* node,QString R = "(", bool left=true)
{
    QString retorno;
    if(node->leaf != true)
    {
        retorno.append(QString("("));
        //retorno.append(QString().setNum(node->getSize()));
        retorno.append(QString(","));
        retorno.append(TreeRepresetation(node->left,retorno));
        retorno.append(QString(","));
        retorno.append(TreeRepresetation(node->right,retorno,false));
        if(left==false)
            retorno.append(QString(")"));
    }

    else
    {
        retorno.append(QString(node->getElement()));
        if(left==false)
            retorno.append(QString(")"));
    }
    return retorno;

}
int main()
{
    char file[100] = "/home/alunoic/Área de Trabalho/ArvoreHuffman/pedro";
    ArvoreHuffman vetor = ArvoreHuffman();
    File* arquivo =new File(file);
    for(int i=0; i<256; i++)
    {
        cell new_cell=cell(arquivo->BitToChar(i),arquivo->BitFrequency(i));
        vetor.inserir(new_cell);
    }
    vetor.buildhuff();
    for(int i = 1;i<=vetor.getsize();i++)
    {
        //qDebug()<<vetor.arvoredehuffmanAT(i).getSize();
    }
    cell ref=vetor.arvoredehuffmanAT(1);
    printTree(&ref);
    QString tree=TreeRepresetation(&ref).remove(',').remove(0,1);
    arquivo->BuildCodification(&ref);
//    qDebug()<<QString().setNum(tree.remove(tree.size()-1,1).size(),2);
//    qDebug()<<tree;
//    qDebug()<<QString().setNum(arquivo->calclixo(),2);
    bitvector andressa=bitvector();
    andressa.setbit(0,1);
       andressa.setbit(5,1);
          andressa.setbit(3,1);
             andressa.setbit(7,1);




}

