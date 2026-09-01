// Hardware Register Access

#include <iostream>
using namespace std;

int main()
{
    int statusReg = 0b010110001;    // Status register
    int controlReg = 0b00000000;   // Control register
    int dataReg = 0b11001010;      // Another register

    const int* regPtr1 = &statusReg;
    cout << "Status value: " << *regPtr1 << endl;
    regPtr1 = &dataReg;
    cout << "New value: " << *regPtr1 << endl;



    int* const regPtr2 = &controlReg;

    cout << "Control value: " << *regPtr2 << endl;

    *regPtr2 = 20;

    cout << "Changed control value: " << *regPtr2 << endl;


    const int* const regPtr3 = &statusReg;

    cout << "Status value: " << *regPtr3 << endl;



    return 0;
}
