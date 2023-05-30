#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
using namespace std;
class Employee {
	std::string _name;
	int _birth;
	std::string _proffession;
	std::string _group;
public:
	Employee(std::string n, int b, std::string p, std::string g): _name(n), _birth(b), _proffession(p), _group(g){}
	string getGroup() const { return _proffession; }
	int getBirth() const { return _birth; }
	void printInfo() const {
		std::cout << _name + " " << _birth << " " + _proffession + " Группа " + _group+"\n";
	}
};

class Database {
private:

public:
	std::vector<Employee*> employees;
	void addEmployee(Employee* e) {
		employees.push_back(e);
	}
	void printAllEmployees() const {
		for (const auto e : employees) {
			e->printInfo();
		}
	}
	void printAllEngineers() const {
		std::for_each(employees.begin(), employees.end(), [] (Employee* e) {
			if (e->getGroup() == "инженер")  e->printInfo(); 
			});
	}
	void printAllNotResidents() const {
		std::vector<Employee*> nonResidents;
		std::for_each(employees.begin(), employees.end(), [&](Employee* e) {
			if (e->getGroup() != "председатель")  nonResidents.push_back(e);
			});
		std::sort(nonResidents.begin(), nonResidents.end(), [](const Employee* a, const Employee* b) {
			return a->getBirth() < b->getBirth();
		});
		for (const auto& e : nonResidents) e->printInfo();
	}
	Database(){}
	~Database(){for (auto e : employees) delete e;}
};

int main()
{
	setlocale(0, "");
	Database db;
	std::ifstream file("employees.txt");
	std::string name,prof,group,line;
	int birth;
	std::string employeeInfo[6];
	if (file.is_open()) {
		cout<<"ok" << endl;
		while (std::getline(file, line))
		{
			std::istringstream ss(line);
			for(int i=0;i<6;i++)
			{
				ss >> line;
				if (i==2) { 
					line.pop_back();
					birth = stoi(line);
					}
				if (i == 3) {
					line.pop_back();
					employeeInfo[i] = line;
				}
				else 
					employeeInfo[i] = line;
			}
			db.addEmployee(new Employee(employeeInfo[0] + " " + employeeInfo[1], birth, employeeInfo[3], employeeInfo[5]));
		}
	}
	std::cout << "Все работники: \n";
	db.printAllEmployees();
	std::cout << "Все инженеры: \n";
	db.printAllEngineers();
	std::cout << "Все не представители, отсортированы по возрасту: \n";
	db.printAllNotResidents();
	return 0;
}

