#ifndef Buffer_hpp
#define Buffer_hpp
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;
class Buffer{
private:
    mutex data;
    condition_variable queue;
public:
    Buffer();
    ~Buffer();
    void thread1(string s);
    void thread2();
    bool fileIsEmpty();
};

#endif

