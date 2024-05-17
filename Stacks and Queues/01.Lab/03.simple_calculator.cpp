#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int task3() {
    string expression;
    getline(cin, expression);

    istringstream istr(expression);

    int count = 1;

    stack<int> numbers;
    stack<string> solution;
    string num;
    int sum = 0;

    while(istr >> num){
        if (count % 2 == 1){
            numbers.push(stoi(num));
        } else{
            solution.push(num);
        }
        count += 1;
    }

    while(!solution.empty()){
        int curr_num = numbers.top();

        if(solution.top() == "+"){
            numbers.pop();
            sum += curr_num;
            solution.pop();

        }
        else{
            numbers.pop();
            sum -= curr_num;

            solution.pop();

        }
    }

    cout << sum + numbers.top() << endl;

    return 0;
}