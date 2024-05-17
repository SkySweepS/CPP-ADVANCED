#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

string read_input(){
    string input;
    getline(cin, input);
    return input;
}
void execute_add_url(const string & new_url,
                     stack<string> &url_history,
                     stack<string> & forward_history){
    url_history.push(new_url);
    cout << "Last URL: " << new_url << endl;
    forward_history = stack<string>();
}

void execute_forward_url(stack<string> & url_history,
                         stack<string> & forward_url){
    if (forward_url.empty()){
        cout << "no next URL" << endl;
        return;
    }
    const string curr_url = forward_url.top();
    url_history.push(curr_url);
    forward_url.pop();
    cout << "Last URL: " << curr_url << endl;
}

void execute_back_url(stack<string> & url_history,
                      stack<string> & forward_history){
    string fw_string;
    if(url_history.empty()){
        cout << "No previous URL" << endl;
        return;
    }
    forward_history.push(url_history.top());
    url_history.pop();
    if(url_history.empty()) {
        cout << "Empty browser" << endl;
    }
    else {
        cout << url_history.top() << endl;
    }

}

int browser_main() {

    stack<string> url_history;
    stack<string> forward_history;
    string curr_url;
    const string delimiter = "end"; //Stops the Loop
    const string back_instruction = "/back"; //COMMAND THAT Return to the previous page
    const string forward_instruction = "/forward";

    while(true){
        curr_url = read_input();
        if (curr_url == delimiter){
            break;
        }
        if (curr_url == back_instruction){
            execute_back_url(url_history, forward_history);
        }
        else if(curr_url == forward_instruction){
            execute_forward_url(url_history,forward_history);
        }

        else{
            execute_add_url(curr_url, url_history, forward_history);
        }
    }

    return 0;
}