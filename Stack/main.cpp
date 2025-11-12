#include <iostream>
#include "stack.hpp"
using namespace std;

bool check(string str){
    LinkStack<char> stack;
    for(char c : str){
        if(c == '(' || c == '{' || c == '['){
            stack.push(c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            if(stack.empty()){
                return false;
            }
            char top = stack.pop();
            if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')){
                return false;
            }
        }
        
    }
    return stack.empty();
}

int main(){
    string str; 
    cout << "Enter a string that includes brackets: ";
    getline(cin, str);

    if(check(str)){
        cout << "correct" << endl;
    }else{
        cout << "incorrect" << endl;
    }
    return 0;
}





