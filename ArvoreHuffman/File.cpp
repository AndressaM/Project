#include"File.h"
#include<string>

File::File(char FileName[])
{
    for(int i=0; i<255; i++)
    {
        frequency[i]=0;
    }
    inputFile.open(FileName,std::ios::binary);
    if(inputFile.is_open())
    {
        inputFile.seekg(0,inputFile.end);
        size=inputFile.tellg();
        inputFile.seekg(0);
    }
    file=new char[size];
    inputFile.read(file,size);
    FileCount();
}
int File::FileSize()
{

    return size;
}
void File::FileCount()
{
    inputFile.read(file,size);
    for(int i=0; i<size; i++)
    {
        frequency[int(file[i])+128]++;
    }
}
int File::BitFrequency(int Bit)
{
    return frequency[Bit];
}
char File::BitToChar(int Bit)
{
    return char(Bit-128);
}
int File::CharToBit(char Char)
{
    return int(Char+128);
}
QString File::HuffmanRepresentation(int Char)
{
    return this->HuffmanRepresentationArray[Char];
}
void File::BuildCodification(cell* node, int level = 1)
{
        if(node->leaf != true)
        {
            BuildCodification(node->left, level*10);
            BuildCodification(node->right,level*10+1);
        }
        if(node->leaf)
        {
            node->setHuffmanRepresentation(level);
            this->HuffmanRepresentationArray[this->CharToBit(node->getElement())]=node->getHuffmanRepresentation();
            //qDebug() << "\n" <<node->getHuffmanRepresentation();
        }
    }
int File::calclixo()
{
    int totalbit=0;
    for(int i=0;i<256;i++)    {
        totalbit += this->HuffmanRepresentationArray[i].size() * this->frequency[i];
    }
    lixo=8-(totalbit%8);
    return lixo;
}
