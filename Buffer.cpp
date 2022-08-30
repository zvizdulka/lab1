#include "Buffer.hpp"
#include "StringProcessing.hpp"
#include "BufferProcessing.hpp"
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <fstream>
using namespace std;
Buffer::Buffer(){}
Buffer::~Buffer(){}
void Buffer::thread1(string s){
    StringProcessing string(s);
    if(string.isCorrect()){
        string.redact();
        unique_lock<mutex> locker(data);
        string.loadToBuffer();
        locker.unlock();
        queue.notify_one();
    }
    else{
        cout << "Input error. " << endl;;
    }
}

void Buffer::thread2(){
    try{
        unique_lock<mutex> locker(data);
        queue.wait(locker, [this]{return !fileIsEmpty();});
        BufferProcessing buffer;
        buffer.loadFromBuffer();
        buffer.clearBuffer();
        locker.unlock();
        buffer.print();
        cout << "Sum is " << buffer.sum() << ". "<< endl;
    }
    catch(invalid_argument err){
        cout << err.what() << endl;
    }
}

bool Buffer::fileIsEmpty(){
    ifstream file("buffer.txt");
    return file.peek() == EOF;
}

