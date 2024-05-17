#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    istringstream istr(line);
    string check;

    stack<int> start;
    stack<int> end;

    for (int i = 0; i < line.size(); i++){
        check = line[i];
        if (check == "("){
            start.push(i);
        }
        else if(check == ")"){
            int out = start.top();
            start.pop();
            int put = line[out] + line[i];
            cout << put;

        }
    }


    return 0;
}