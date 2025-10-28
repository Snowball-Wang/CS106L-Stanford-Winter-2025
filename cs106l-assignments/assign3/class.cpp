#include "class.h"
#include <string>

// Default constructor
ArmID::ArmID() {
    name = "Rene Hass";
    title = "CEO";
    idNumber = 1;
    salary = 10000000;
    std::cout << "Default constructor" << std::endl;
}

// Parameterized constructor
ArmID::ArmID(std::string name, std::string title, int idNumber, int salary) {
    this->name = name;
    this->title = title;
    if(idNumber > 0)
        this->idNumber = idNumber;
    if(salary > 0)
        this->salary = salary;
    std::cout << "Parameterized constructor" << std::endl;
}

// Group of get functions
std::string ArmID::getName() const {
    return this->name;
}
std::string ArmID::getTitle() const {
    return this->title;
}
int ArmID::getID() const {
    return this->idNumber;
}
int ArmID::getSalary() const {
    return this->salary;
}

// Private function
void ArmID::display() const {
    std::cout << "Employee Name: " << this->name << "\n"
    << "Employee Title: " << this->title << "\n"
    << "Employee ID Number: " << this->idNumber << "\n"
    << "Employee Salary: " << this->salary << std::endl;
}

// Group of set functions
void ArmID::setName(const std::string& name) {
    this->name = name;
}
void ArmID::setTitle(const std::string& title) {
    this->title = title;
}
void ArmID::setID(int idNumber) {
    this->idNumber = idNumber;
}

// Group of private functions
void ArmID::setSalary(int salary) {
    this->salary = salary;
}
void ArmID::changeTitle(std::string newTitle) {
    this->title = newTitle;
}

// Method to promote someone
void ArmID::promote(std::string newTitle, int newSalary) {
    std::cout << "Congratulations to your promotion!" << std::endl;
    std::cout << "Before your promotion:" << std::endl;
    display();
    std::cout << "After your promotion:" << std::endl;
    changeTitle(newTitle);
    setSalary(newSalary);
    display();
}

// Destructor
ArmID::~ArmID() {
    // free/deallocate any data here
}

