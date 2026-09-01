// HR_Payroll_Engine

#include <iostream>
#include <algorithm>
using namespace std;

int EMP_ID = 1001;

class Employee{
private:
	int empId;
	string name;
	string department;
	char grade;
	double basicSalary;
	bool isActive = true;
public:
	
	inline static int employeeCount;
	Employee(){
		empId = EMP_ID++;

		employeeCount++;

	}

	
	void setName(const string& n){
		if(!n.size()){
			cout<<"Name cannot be null"<<endl;
			return;
		}
		name = n;
	}
	void setDepartment(const string& dept){
		if(dept == "Engineering" || dept == "HR" || dept == "Finance" || dept == "Operations"){
			department = dept;
		}
		else{
			cout<<"Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."<<endl;
			return;
		}

	}
	void setGrade(char g){
		if(g == 'A' || g == 'B' || g == 'C' || g == 'D'){
			grade = g;
		}
		else{
			cout<<"ERROR: Invalid grade 'X'. Accepted values: A, B, C, D."<<endl;
			return;
		}
	}
	void setBasicSalary(double salary){
		if(salary < 10000 || salary > 500000){
			cout<<"Salary must be between Rs.10,000 and Rs.5,00,000. Value rejected."<<endl;
			return;
		}
		basicSalary = salary;
	}
	void deactivate(){
		isActive = false;
		employeeCount--;
	}

	int getEmpId() const{
		return empId;
	}
	string getName() const{
		return name;
	}
	string getDepartment() const{
		return department;
	}
	char getGrade() const{
		return grade;
	}
	double getBasicSalary() const{
		return basicSalary;
	}
	bool getIsActive() const{
		return isActive;
	}


	void acceptDetails(){
		string t;
		cout<<"Enter Name: "<<endl;
		getline(cin, t);
		setName(t);

		cout<<endl;
		cout<<"Enter Department: "<<endl;
		getline(cin, t);
		setDepartment(t);

		cout<<endl;
		cout<<"Enter Grade: "<<endl;
		getline(cin, t);
		setGrade(t[0]);

		cout<<endl;
		cout<<"Enter Basic Salary: "<<endl;
		getline(cin, t);
		setBasicSalary(stod(t));
	}

	static int getEmployeeCount(){
		return employeeCount;
	}

	double computeAllowances() const{
		
		double ret;
		if(grade == 'A'){
			ret = (double)(basicSalary * 0.4);
		}
		else if(grade == 'B'){
			ret = (double)(basicSalary * 0.3);
		}
		else if(grade == 'C'){
			ret = (double)(basicSalary * 0.2);
		}
		else{
			ret = (double)(basicSalary * 0.1);
		}

		return ret;
	}

	double computeGrossSalary() const{

		return basicSalary + computeAllowances();

	}

	double computeTax() const{
		

		double grossSalary = computeGrossSalary();
		if(grossSalary <= 50000) return 0;
		else if(grossSalary >= 50001 && grossSalary <= 100000) return (double)((grossSalary-50000)*0.1);
		else if(grossSalary >= 100001) return (double)(5000 + (grossSalary*0.2));

		return 0.0;
	}

	double computeNetSalary() const{
		return (double)(computeGrossSalary() - computeTax());
	}


	void printPayslip() const{
		cout<<"============================================"<<endl;
		cout<<"EMPLOYEE PAYSLIP — AUG 2026"<<endl;
		cout<<"============================================"<<endl;
		cout<<"EMP ID: "<<empId<<endl;
		cout<<"Name: "<<name<<endl;
		cout<<"Department: "<<department<<endl;
		cout<<"Grade: "<<grade<<endl;
		cout<<"Status: "<<((isActive) ? "Active" : "Inactive")<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"Basic Salary: "<<basicSalary<<endl;
		cout<<"Allowances: "<<computeAllowances()<<endl;
		cout<<"Gross Salary: "<<computeGrossSalary()<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"Tax Deduction: "<<computeTax()<<endl;
		cout<<"Net Salary: "<<computeNetSalary()<<endl;
		cout<<"--------------------------------------------\n";

	}

};


int main() {
	
	 Employee e1;
	 Employee* e2 = new Employee();
	 Employee* e3 = new Employee();
	 e1.acceptDetails();
	 e2->acceptDetails();
	 e3->acceptDetails();
	

	 e1.printPayslip();
	 e2->printPayslip();
	 e3->printPayslip();
	 
	 e3->deactivate();
	 if (!e3->getIsActive())
	 cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
	 cout << "Total Employees : " << Employee::getEmployeeCount() << endl;
	 delete e2;
	 delete e3;
	 return 0;

	return 0;
}
