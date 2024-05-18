#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task11() {
    int food_quantity;
    cin >> food_quantity;
    cin.ignore();
    string numbers;
    getline(cin, numbers);
    istringstream istr(numbers);
    int num;
    int max = INT_MIN;
    queue<int> nums;
    while(istr >> num) {
        if (num > max) max = num;
        nums.push(num);
    }
    while(!nums.empty()){
        if(food_quantity - nums.front() >= 0){
            food_quantity -= nums.front();
            nums.pop();
        }
        else {
            break;
        }
    }
    if(nums.empty()){
        cout << max << endl;
        cout << "Orders complete" << endl;
    }
    else{
        cout << max << endl;
        cout << "Orders left: ";
        while(!nums.empty()){
            cout << nums.front() << " ";
            nums.pop();
        }
    }

    return 0;
}