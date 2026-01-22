#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;

    istringstream iss(str);
    string word,max_word,min_word;
    int maxlen=0,minlen=501;
    while(iss>>word){
        if(word.length() < minlen) min_word=word;
        if(word.length() > maxlen) max_word=word; 
    }

    cout<<min_word<<"\n"<<max_word;
}