#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    array<int, 3> arr={9, 8, 7};

    cout << "Array size = " << arr.size() << endl;
    for(auto i : arr) cout << i << endl;

    cout << "Hello World!" << endl;

    return 0;
}


