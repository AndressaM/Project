#ifndef TREATMENTHEADER_H
#define TREATMENTHEADER_H
#include<QString>
class TreatmentHeader
{
    bool isCodificationBool;
    bool isSuccessBool;
    int argc;
    char** argv;


public:
    TreatmentHeader(int argc, char* argv[]);
    bool isCodification();
    char* getFileInput();
    QString getFileOutput();
    bool isSuccess();
};

#endif // TREATMENTHEADER_H
