#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task8() {
    int N, S, X;
    cin >> N >> S >> X;
    cin.ignore();
    string nums;
    getline(cin, nums);

    istringstream istr(nums);
    stack<int> n;
    int num;
    while(istr >> num){
        n.push(num);
    }
    while(S > 0){
        S--;
        n.pop();
    }
    int int_min = INT_MAX;
    if(n.empty()){
        cout << 0 << endl;
        return 0;
    }
    while(!n.empty()){

        if(n.top() == X){
            cout << "true" << endl;
            return 0;
        }
        else{
            if(n.top() < int_min){
                int_min = n.top();
            }
        }
        n.pop();
    }
    if(n.empty()){
        cout << int_min;
    }

    return 0;
}