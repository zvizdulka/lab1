#ifndef BufferProcessing_hpp
#define BufferProcessing_hpp
#include <iostream>
using namespace std;
class BufferProcessing{
private:
    int size;
    string buffer;
public:
    BufferProcessing();
    ~BufferProcessing();
    int sum();
    void print();
    void loadFromBuffer();
    void clearBuffer();
};
#endif

