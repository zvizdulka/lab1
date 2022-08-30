#ifndef StringProcessing_hpp
#define StringProcessing_hpp
#include <iostream>
using namespace std;
class StringProcessing{
private:
    int size;
    string str;
public:
    StringProcessing(string word);
    ~StringProcessing();
    bool isCorrect();
    void redact();
    void loadToBuffer();
};
#endif
