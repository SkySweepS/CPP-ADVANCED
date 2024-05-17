#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int task4() {
    string line;
    getline(cin, line);




    stack<size_t> start;
    stack<size_t> end;

    for (size_t i = 0; i < line.size(); i++){

        if (line[i] == *"("){
            start.push(i);
        }
        else if(line[i] == *")"){

            string output = line.substr(start.top(), i - start.top() + 1);
            start.pop();
            cout << output << endl;;

        }

    }


    return 0;
}