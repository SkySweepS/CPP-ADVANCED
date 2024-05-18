#include <iostream>
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;


bool check_for_trip(queue<int>petrol, queue<int>distance){
    int fuel = 0;
    while(petrol.size()){
        int p = petrol.front();
        fuel += p;
        if(fuel - distance.front() >= 0){
            fuel -= distance.front();
            petrol.pop();
            distance.pop();
        }
        else break;
    }
    return petrol.size() == 0;
}


int main() {
    int n;
    cin >> n;
    cin.ignore();
    int tank = 0;
    queue<int> petrol;
    queue<int> distance;
    int count = 1;
    cout << endl;
    while(n--){
        string numbers;
        getline(cin, numbers);
        istringstream istr(numbers);
        int p;
        int d;
        istr >> p;
        istr >> d;
        petrol.push(p);
        distance.push(d);
    }
    int index = 0;
    while (petrol.size()){
        if (check_for_trip(petrol, distance)) break;
        int p = petrol.front();
        int d = petrol.front();
        index++;
        petrol.pop();
        petrol.push(p);
        distance.pop();
        distance.push(d);
    }
    cout << index << endl;

    return 0;
}