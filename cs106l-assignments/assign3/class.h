#include <string>
#include <iostream>

class ArmID {
private:
    std::string name;
    std::string title;
    int idNumber;
    int salary;
    // private function
    void changeTitle(std::string newTitle);
    void setSalary(int salary);
public:
    // default constructor
    ArmID();
    // parameterized constructor
    ArmID(std::string name, std::string title, int idNumber, int salary);
    // method to get name, department and ID number respectively
    std::string getName() const;
    std::string getTitle() const;
    int getID() const;
    int getSalary() const;
    // method to set name, department and ID number respectively
    void setName(const std::string& name);
    void setTitle(const std::string& title);
    void setID(int idNumber);

    // method to display all information
    void display() const;

    // method to promote someone
    void promote(std::string newTitle, int newSalary);

    // destructor
    ~ArmID();
};