//Building Sensor Grid

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double temp[3][3];

 
    cout << "Enter temperatures for 9 rooms:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp[i][j];
        }
    }

    
    cout << "\nTemperature Grid:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(8) << temp[i][j];
        }
        cout << endl;
    }

    
    double hottest = temp[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] > hottest)
            {
                hottest = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }
        }
    }

    cout << "\nHottest room: Floor " << hotFloor + 1
         << ", Room " << hotRoom + 1
         << " -> " << hottest << " C";


   
    double highestAvg = 0;
    int highestFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        float sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + temp[i][j];
        }

        float avg = sum / 3;

        if (avg > highestAvg)
        {
            highestAvg = avg;
            highestFloor = i;
        }
    }

    cout << "\nFloor with highest average: Floor "
         << highestFloor + 1
         << " -> " << highestAvg << " C";


   
    int warningRooms = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] >= 30)
            {
                warningRooms++;
            }
        }
    }

    cout << "\nRooms at/above warning (30 C): "
         << warningRooms;

    return 0;
}
