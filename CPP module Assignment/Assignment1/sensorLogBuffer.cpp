//Sensor Log Buffer
#include <iostream>
using namespace std;

int main()
{
    int n;
    double temp[100];

    cout << "Enter number of readings: ";
    cin >> n;

    // Input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter temperature " << i << ": ";
        cin >> temp[i];
    }

    // 1. Print valid readings and count errors
    int errors = 0;

    cout << "\nValid readings : ";

    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
        {
            errors++;
            continue;
        }

        cout << temp[i] << " ";
    }

    cout << "\nSkipped (errors) : " << errors << endl;


    // 2. Find first reading >= 45
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
            continue;

        if (temp[i] >= 45)
        {
            cout << "\nFirst CRITICAL : Index " << i
                 << " -> " << temp[i] << "°C" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nNo critical reading found." << endl;
    }


    // 3. Find min, max and average in one loop
    double min = 0;
    double max = 0;
    double sum = 0;
    int validCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
            continue;

        if (validCount == 0)
        {
            min = temp[i];
            max = temp[i];
        }

        if (temp[i] < min)
            min = temp[i];

        if (temp[i] > max)
            max = temp[i];

        sum = sum + temp[i];
        validCount++;
    }

    double avg = sum / validCount;

    cout << "\nMin : " << min << "°C";
    cout << "    Max : " << max << "°C";
    cout << "    Avg : " << avg << "°C" << endl;


    // 4. Count categories
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
            continue;

        if (temp[i] < 30)
            normal++;
        else if (temp[i] < 45)
            warning++;
        else if (temp[i] < 55)
            critical++;
        else
            shutdown++;
    }

    cout << "\nNormal: " << normal;
    cout << "    Warning: " << warning;
    cout << "    Critical: " << critical;
    cout << "    Shutdown: " << shutdown << endl;

    return 0;
}
