#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int task7() {
    string names;
    getline(cin, names);
    int count;
    cin >> count;
    istringstream name(names);
    string n;

    queue<string> imena;

    while(name >> n){
        imena.push(n);
    }
    int c = 0;
    while(imena.size() > 1){
        c++;
        if (c == count){
            c = 0;
            cout << "Removed " << imena.front() << endl;
            imena.pop();
        }
        else {
            string ime = imena.front();
            imena.pop();
            imena.push(ime);
        }
    }
    cout << "Last is " << imena.front() << endl;


    return 0;
}