#include <iostream>
#include <thread>
#include "StringProcessing.hpp"
#include "BufferProcessing.hpp"
#include "Buffer.hpp"
using namespace std;

int main() {
    string s;
    Buffer buffer;
    while(true){
        cin >> s;
        if(s == "end"){
            break;
        }
        thread t1(&Buffer::thread1, ref(buffer), s);
        thread t2(&Buffer::thread2, ref(buffer));
        t1.join();
        t2.detach();
    }
}

