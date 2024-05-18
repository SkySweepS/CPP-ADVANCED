#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

bool check_identical(stack<char>&open, char expected){
    if(open.size() == 0) return false;
    if(open.top() != expected) return false;
    open.pop();
    return true;
}

int task14() {
    string text;
    cin >> text;

    stack<char>open;
    bool valid = true;
    string::iterator it_s = text.begin();
    for(; valid && it_s != text.end(); it_s++){
        switch (*it_s) {
            case '(':
            case '[':
            case '{':
                open.push(*it_s);
                break;
            case ')':
                if(!check_identical(open, '(')){
                    valid = false;
                }
                break;
            case '}':
                if(!check_identical(open, '{')){
                    valid = false;
                }
                break;
            case ']':
                if(!check_identical(open, '[')){
                    valid = false;
                }
                break;
        }

    }
    if(valid){
        if(open.size() != 0){
            valid = false;
        }
    }
    cout << (valid ? "YES" : "NO") << endl;


    return 0;
}