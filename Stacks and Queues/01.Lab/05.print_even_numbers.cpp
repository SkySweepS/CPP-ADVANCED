#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int main() {

    string arr;
    getline(cin, arr);

    istringstream istr(arr);
    queue<int> que;
    int test;
    while(istr >> test){
        if(test % 2 == 0) {
            que.push(test);
        }
    }

    while(que.size() > 1){

        cout << que.front() << ", ";
        que.pop();
    }

    cout << que.front();

    return 0;
}