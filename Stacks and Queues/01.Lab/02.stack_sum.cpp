#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int task2() {
    stack<int> numbers;
    string line;
    getline(cin, line);
    int sum = 0;
    istringstream istr(line);
    int curr_num;
    while(istr >> curr_num){
        numbers.push(curr_num);
    }
    while(true){
        getline(cin, line);
        if (line == "end"){
            break;
        }

        istringstream istr(line);
        string command;
        istr >> command;

        if(command == "add"){
            int n1, n2;
            istr >> n1 >> n2;
            numbers.push(n1); numbers.push(n2);
        }
        else if(command == "remove"){
            int n;
            istr >> n;

            if (n <= numbers.size()){
                while(n--)
                    numbers.pop();

            }
        }

    }

    while(!numbers.empty()){
        sum += numbers.top();
        numbers.pop();
    }
    cout << sum << endl;
    return 0;
}