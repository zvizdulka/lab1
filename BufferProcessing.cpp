#include "BufferProcessing.hpp"
#include<iostream>
#include <string>
#include <fstream>
using namespace std;
BufferProcessing::BufferProcessing(){}
BufferProcessing::~BufferProcessing(){}
void BufferProcessing::loadFromBuffer(){
    ifstream in("buffer.txt");
    if (in.is_open()){
            in >> buffer;
    }                    
    else{
        throw invalid_argument("File not found.");
    }
    in.close();
}
void BufferProcessing::clearBuffer(){
    ofstream out;
    out.open("buffer.txt");
    out.close();
}
void BufferProcessing::print(){
    cout << "Data: " << buffer << ". ";
}
int BufferProcessing::sum(){
    int count = 0;
    for(int i = 0; i < buffer.length(); i++){
        int k = ((int)buffer[i]) - 48;
        if(k >= 0 && k <= 9){
            count = k + count;
        }
    }
    return count;
}

