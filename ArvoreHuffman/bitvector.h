#ifndef BITVECTOR_H
#define BITVECTOR_H
#include <QBitArray>
#include<QString>

class bitvector
{
    int size;
    QBitArray biTvector;
public:
    bitvector();
    void setbit(int pos, int valor);
    void setbit(int pos, QString valor);
    int bitvectorAt(int pos);
    QString getQbitarray();
    void clearbitvector();

};

#endif // BITVECTOR_H
