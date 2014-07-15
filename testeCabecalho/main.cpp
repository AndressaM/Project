#include <QDebug>
#include"treatmentheader.h"

int main(int argc, char *argv[])
{
    TreatmentHeader teste = TreatmentHeader(argc,argv);
    qDebug()<<"input:"<<teste.getFileInput();
    qDebug()<<"output:"<<teste.getFileOutput().append("pedrobarro").toLocal8Bit().data();
}
