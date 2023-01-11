#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    vector<string> myVector = {"A first string", "A second string"};

    myVector.push_back("A third string");
    myVector.push_back("A last string in the vector");

    for(auto iterator = myVector.cbegin(); iterator != myVector.cend(); ++iterator){
            cout << *iterator << endl;
    }

    for(auto& str: myVector){
        cout << str << endl;
    }

    return 0;
}


