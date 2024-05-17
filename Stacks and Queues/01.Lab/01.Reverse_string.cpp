#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int task1() {

    string text;
    getline(cin ,text);
    stack<char> reverse;

    for(char i : text) reverse.push(i);

    while(!reverse.empty()){
        cout << reverse.top();
        reverse.pop();
    }

    return 0;

}