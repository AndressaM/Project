#include<fstream>
#include"Cell.h"
#include<QString>
class File
{
public:
    std::ifstream inputFile;
    int size;
    int lixo;
    int frequency[256];
    QString HuffmanRepresentationArray[256];
    char* file;
    char* FileName;

    File(char file[]);
    int FileSize();
    void FileCount();
    int BitFrequency(int Bit);
    char BitToChar(int Bit);
    int CharToBit(char Char);
    QString HuffmanRepresentation(int Char);
    void BuildCodification(cell *node, int level);
    int calclixo();
};

