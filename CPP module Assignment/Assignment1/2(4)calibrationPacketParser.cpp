// Calibration Packet Parser

#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax){
    if (size <= 0) {
        return false;
    }

    *outMin = (int*)&rawData[0];
    *outMax = (int*)&rawData[0];


    for (int i = 1; i < size; i++)
    {
        if (rawData[i] < **outMin)
        {
            *outMin = (int*)&rawData[i];
        }

        if (rawData[i] > **outMax)
        {
            *outMax = (int*)&rawData[i];
        }
    }

    return true;
}


int main()
{
    int packet[] = {45, 12, 67, 8, 55, 31};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr))
    {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}
