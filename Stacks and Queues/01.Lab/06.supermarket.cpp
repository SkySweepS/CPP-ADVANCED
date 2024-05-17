#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task6() {
    string name;
    queue<string> waiting;

    while(true){
        cin >> name;
        if (name == "End"){
            cout << waiting.size() << " people remaining." << endl;
            break;
        }

        if (name == "Paid"){
            while(!waiting.empty()) {
                cout << waiting.front() << endl;
                waiting.pop();
            }
        }
        else{
            waiting.push(name);
        }
    }



    return 0;
}