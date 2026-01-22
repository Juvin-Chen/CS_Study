#include<iostream>
#include<string>

using namespace std;

int main() {
    string str,word;
    getline(cin,str);
    str += ' ';

    int count=0,max=0,min=501;
    string max_str,min_str;

    for(char c : str) {
        if(c !=' ') {
            count++;
            word += c;
        }else {
            if (word.empty()) continue;
            if(count < min){
                min_str = word;
                min = word.length();
            }
			if(count > max) {
                max_str = word;
                max = word.length();
            }
            count = 0;
            word = "";
        }
    }
    
    cout << max_str << "\n" << min_str;
}