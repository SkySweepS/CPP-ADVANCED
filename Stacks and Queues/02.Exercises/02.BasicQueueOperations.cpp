#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task9() {
    int N, S, X;
    cin >> N >> S >> X;
    cin.ignore();
    string nums;
    getline(cin, nums);

    istringstream istr(nums);
    queue<int> n;
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

        if(n.front() == X){
            cout << "true" << endl;
            return 0;
        }
        else{
            if(n.front() < int_min){
                int_min = n.front();
            }
        }
        n.pop();
    }
    if(n.empty()){
        cout << int_min;
    }

    return 0;
}