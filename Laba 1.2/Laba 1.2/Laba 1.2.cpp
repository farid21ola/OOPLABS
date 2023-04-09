#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Car {
public:
	Car(const std::string& model) : m_model(model) {std::cout << model << " :  Create" << std::endl;}
	virtual ~Car() {}
protected:
	const std::string m_model;
};

class Mercedes : public Car {
public:
	Mercedes(const std::string& model) : Car(model){}
	virtual ~Mercedes() {
		std::cout << "Mercedes" << " : " << m_model << std::endl;
	}
};

class Lotus : public Car {
public:
	Lotus(const std::string& model) : Car(model){}
	virtual ~Lotus() {
		std::cout << "Lotus" << " : " << m_model << std::endl;
	}
};

class Lada : public Car {
public:
	Lada(const std::string& model) : Car(model){}
	virtual ~Lada() {
		std::cout << "Lada" << " : " << m_model << std::endl;
	}
};

class Dodge : public Car {
public:
	Dodge(const std::string& model) : Car(model){}
	virtual ~Dodge() {
		std::cout << "Dodge" << " : " << m_model << std::endl;
	}
};

class Pagani : public Car {
public:
	Pagani(const std::string& model) : Car(model){}
	virtual ~Pagani() {
		std::cout << "Pagani" << " : " << m_model << std::endl;
	}
};

class Bmw : public Car {
public:
	Bmw(const std::string& model) : Car(model){}
	virtual ~Bmw() {
		std::cout<< "Bmw" << " : " << m_model<< std::endl;
	}
};

class Chevrolet : public Car {
public:
	Chevrolet(const std::string& model) : Car(model){}
	virtual ~Chevrolet() {
		std::cout << "Chevrolet" << " : "<<m_model << std::endl;
	}
};

int main()
{
	std::ifstream file;
	std::vector <Car*> v;
	file.open("text.txt");
	std::string line;
	std::string mark;
	std::string model;
	int count = 0;
	while (true)
	{	
		if (file.eof()) break;
		file >> mark >> model;
		if (mark == "Mercedes") {
			v.emplace_back(new Mercedes(model));
		}
		if (mark == "Bmw") {
			v.emplace_back(new Bmw(model));
		}
		if (mark == "Chevrolet") {
			v.emplace_back(new Chevrolet(model));
		}
		if (mark == "Lotus") {
			v.emplace_back(new Lotus(model));
		}
		if (mark == "Lada") {
			v.emplace_back(new Lada(model));
		}
		if (mark == "Pagani") {
			v.emplace_back(new Pagani(model));
		}
		if (mark == "Dodge") {
			v.emplace_back(new Dodge(model));
		}
		mark = "";
		model = "";
	}
	std::cout << std::endl;
	file.close();
	for (Car* car : v) {
		delete car;
	}
}