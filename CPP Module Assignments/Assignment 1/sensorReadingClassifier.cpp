//Problem 1 — Sensor Reading Classifier


#include <iostream>
using namespace std;

int main () {
	double celcius;
	int status;
	cout << "Enter Sensor Value in celcius: " << endl;
	cin >> celcius;
	double faren = (celcius * 9 / 5) + 32;

	cout << "Temprature : " << celcius << "°C" << " / " << faren << "°F" << endl;

	if(celcius < 0){
			status = -1;
			cout << "Status :  SENSOR ERROR" << endl;
			}
		else if (celcius >= 0 && celcius <= 29) {
				status = 0;
				cout << "Status :  NORMAL" << endl;
		}
		else if (celcius >= 30 && celcius <= 44) {
					status = 1;
					cout << "Status :  WARNING" << endl;
			}
		else if (celcius >= 45 && celcius <= 59) {
					status = 2;
					cout << "Status :  CRITICAL" << endl;
			}

	switch (status){
	case (-1):
			cout << "Action :  Sensor fault - check wiring" << endl;
	break;
	case (0):
			cout << "Action :  No action required" << endl;
	break;
	case (1):
		cout << "Action :  Alert sent to supervisor" << endl;
	break;
	case (2):
			cout << "Action :  Cooling system triggered" << endl;
	break;
	case (3):
				cout << "Action :  Emergancy shutdown initiated" << endl;
		break;
	}

	cout << (celcius > 25 ? "Readings :  Above Average" : "Readings :  Below Average");
}
