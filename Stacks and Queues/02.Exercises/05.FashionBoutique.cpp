#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task12() {
    string items_size;
    getline(cin, items_size);
    istringstream istr(items_size);
    int num;
    stack<int> size;
    while(istr >> num){
        size.push(num);
    }
    int rack_capacity;
    cin >> rack_capacity;
    int capacity = rack_capacity;
    int count = 1;
    while(!size.empty()){
        int item = size.top();
        if(rack_capacity - item >= 0){
            rack_capacity -= item;
            size.pop();
        }
        else{
            count++;
            rack_capacity = capacity;
        }

    }
    cout << count << endl;



    return 0;
}