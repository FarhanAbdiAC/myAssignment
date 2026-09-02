// Hospital Patient Registry

#include <iostream>
using namespace std;

class Patient{
private:
	int patientId;
	string name;
	int age;
	string ward;
	const string bloodGroup;

public:

	Patient(const string& bg = "NA") : bloodGroup{bg}{
		this->patientId = 0;
		this->name="Unknown";
		this->age=0;
		this->ward="General";

		cout<<"[Constructor] Default patient registered."<<endl;
	}


	Patient(int id, const string& name){
		this->patientId = id;
		this->name = name;

		cout<<"[Constructor] Emergency:"<<this->name<<endl;
	}


	Patient(int id, const string& name, int age, const string& ward, const string&
	bg = "NA")
	: bloodGroup{bg}
	{
		this->patientId = id;
		this->name = name;
		this->age = age;
		this->ward = ward;

		cout<<"[Constructor] Full admission: "<<this->name<<endl;
	}

	~Patient(){
		cout<<"Patient: "<<this->name<<" discharged"<<endl;
	}

	void displayRecord() const{

		cout<<"Patient Record:"<<endl;
		cout<<"ID : "<<this->patientId<<endl;
		cout<<"Age : "<<this->age<<endl;
		cout<<"Ward : "<<this->ward<<endl;
		cout<<"Blood Grp : "<<this->bloodGroup<<endl;
	}
	void transferWard(const string& newWard){
		this->ward = newWard;

		cout<<"Ward Transfer: "<<this->name<<" -> "<<newWard<<endl;
	}


};


int main() {

	Patient p1("O+");
	Patient p2(0, "Raj Patel");
	Patient p3(1001, "Meera Joshi", 34, "Cardiology", "B+");
	p3.displayRecord();
	cout<<endl;
	cout<<endl;


	int sz = 4;
	Patient* ptr = new Patient[sz];
	for(int i = 0; i < 4; i++){
		(ptr+i)->displayRecord();
		cout<<endl;
	}
	cout<<endl;
	p2.transferWard("ICU");
	cout<<endl;

	delete[] ptr;

	return 0;
}
