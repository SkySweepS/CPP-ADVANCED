#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>

using namespace std;

int max_stack(stack<int> max_s){
    int max = INT_MIN;
    while(!max_s.empty()){
        if(max_s.top() > max){
            max = max_s.top();
        }
        max_s.pop();
    }
    return max;
}
int min_stack(stack<int> min_s){
    int min = INT_MAX;
    while(!min_s.empty()){
        if(min_s.top() < min){
            min = min_s.top();
        }
        min_s.pop();
    }
    return min;
}

int task10() {
    int w;
    cin >> w;
    cin.ignore();
    stack<int> numbers;

    for (int i = 0; i < w; i ++){
        string num;
        getline(cin, num);
        istringstream istr(num);
        int numbers_to_add;
        while(istr >> numbers_to_add){
            if (numbers_to_add == 1){
                int test;
                istr >> test;
                numbers.push(test);
            }
            else if(numbers_to_add == 2){
                if(!numbers.empty())
                    numbers.pop();
            }
            else if(numbers_to_add == 3){
                if(!numbers.empty())
                    cout << max_stack(numbers) << endl;

            }
            else if(numbers_to_add == 4){
                if(!numbers.empty())
                    cout << min_stack(numbers) << endl;

            }

        }
    }
    while(numbers.size() > 1){
        cout << numbers.top() << ", ";
        numbers.pop();
    }
    cout << numbers.top();
    return 0;
}