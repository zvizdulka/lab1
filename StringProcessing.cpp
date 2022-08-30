#include "StringProcessing.hpp"
#include<iostream>
#include <string>
#include <fstream>
using namespace std;

StringProcessing::StringProcessing(string word){
    str = word;
    size = (int)word.length();
}
StringProcessing::~StringProcessing(){}
bool StringProcessing::isCorrect(){
    if(size > 64){
        return false;
    }
    for(int i = 0; i < size; i++){
        if((int)str[i] < 48 || (int)str[i] > 57){
            return false;
        }
    }
    return true;
}
void StringProcessing::redact(){
    int count[10];
    for(int i = 0; i < 10; i++){
        count[i] = 0;
    }
    for(int k = 0; k < size; k++){
        int i = ((int)str[k]) - 48;
        count[i] = count[i] + 1;
    }
    string copy;
    for(int n = 9; n >= 0; n--){
        for(int k = count[n]; k != 0; k--){
            if(n % 2 == 0){
                copy.push_back(n + '0');
            }
            else{
                copy= copy + "KB";
            }
        }
    }
    str = copy;
}
void StringProcessing::loadToBuffer(){
    ofstream out;
    out.open("buffer.txt");
    if (out.is_open()){
        out << str;
    }
    out.close();
}




