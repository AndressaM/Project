#include "bitvector.h"

bitvector::bitvector()
{
    this->biTvector.resize(200);
    size=0;
}
void bitvector::setbit(int pos, int valor)
{
    bool value;
    if(valor == 0)
    {
        value = false;
    }
    else
    {
        value = true;
    }

    biTvector.setBit(pos,value);
    if(pos>size)
    {
        size=pos;
    }
}
void bitvector::setbit(int pos , QString valor)
{
    bool value;
    for(int i = 0; i < valor.size();i++)
    {
        if(valor.at(i)=='0')
        {
            biTvector[pos+i] = false;
        }
        if(valor.at(i)=='1')
        {
            biTvector[pos+i] = true;
        }
    }
}

int bitvector::bitvectorAt(int pos)
{
    int retorno;
    if(biTvector.at(pos))
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
QString bitvector::getQbitarray()
{
    char bit;
    QString retornobit=QString();
    int i= 0;
    while(size-i>=8)
    {
        bit = 0x0000;
        for(int j= 0; j<8;j++ )
        {
            if (biTvector[i+j])
            {
                bit = (bit<<1)|1;

            }
            else
            {
                bit = bit<<1;
            }

        }
        i=i+8;
        retornobit.append(bit);

    }
    bit= 0x0000;
    for(int j= 0; j<size-i;j++ )
    {
        if (biTvector[i+j])
        {
            bit = (bit<<1)|1;

        }
        else
        {
            bit = bit<<1;
        }

    }
    bit = bit<<8-(size-i);

    retornobit.append(bit);

    return retornobit;


}

void bitvector::clearbitvector()
{
    biTvector.clear();
}
