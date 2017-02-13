#include <iostream>

using namespace std;

int main()
{
    char answer = '';
    cout << "Hello Hub!" << endl;
    cout << "are you ready for calculations?(y,n)" << endl;
    cin >> answer;
    if (answer == 'n')
    cout << "Thats about all I do." << endl;
    else if (answer == 'y')
        cout << "I can do simple mathematics.(add, sub, mult, divs)" << endl;
        cout << "enter your simple math problem" << endl;
        cin >> >> endl;

    return 0;
}
