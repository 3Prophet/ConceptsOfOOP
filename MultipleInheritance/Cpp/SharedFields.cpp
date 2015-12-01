/**
 * @author Dmitry Logvinovich
 * @version 1
 *
 * 01.12.2015
 *
 * Resolution of the diamond problem in C++ 
 * Class that inherits from Both Student and Assistant will have
 * a single copy of the address field.
 *
 *        Person----->Address  
 *        /\
 *Student/  \Assistant
 *       \  /
 *        \/  
 *      PhDStudent
 */     

#include<iostream>

using namespace std;

//Field
class Address 
{
    public:
        Address(string street) {
            this->street = street;
        }
        string getStreet() {
            return this->street;
        }
    private:
        string street;
};

//Tip of the diamond
class Person 
{
    public:
        Person(Address* address) {
            this->address = address;
        }
        Address* getAddress() {
            return this->address;
        }
        virtual void printInfo() {
            cout << "Class Person. Address: " << 
                this->address->getStreet() << endl; 
        }   
    private:
        Address* address;
};

//Branch1
//virtual class: call to Person's constuctor will be overtaken by a subclass
class Student: virtual public Person 
{
    public:
        Student(Address* address, int stIdNr): Person(address) {
            this->studentId = stIdNr;
        }
        int getStudentId() {
            return this->studentId;
        }
        virtual void printInfo() {
            cout << "Class Student. Student Id: " <<
                this->studentId << endl;
        }
    private:
        int studentId;    
};

//Branch2
//virtual class: call to Person's constuctor will be overtaken by a subclass
class Assistant: virtual public Person 
{
    public:
        Assistant(Address* address, int asIdNr): Person(address) {
            this->assistantId = asIdNr;
        }
        int getAssistantId() {
            return this->assistantId;
        }
        virtual void printInfo() {
            cout << "Class Assistant. Assistant Id: " <<
                this->assistantId << endl;
        }
    private:
        int assistantId;    
};

//Inherits from Branch1 and Branch2 which share common superclass
class PhDStudent: public Student, public Assistant 
{
    public:
        //Overtakes initialization of Person.
        //Single copy of Person is created
        PhDStudent(Address* address, int stIdNr, int asIdNr, int phdIdNr):
            Person(address),
            Student(address, stIdNr),
            Assistant(address, asIdNr) {
            this->phdId = phdIdNr;
        }
        int getPhdId() {
            return this->phdId;
        }

        //Both Branch1 and Branch2 have the same method printInfo.
        //To resolve ambiguity it has to be overriden by the subclass
        virtual void printInfo() {
            Person::printInfo();
            Student::printInfo();
            Assistant::printInfo();
            cout << "Class PhDStudent. PhDStudent Id: " <<
                this->phdId << endl;
        }
    private:
        int phdId;
};

//Client
int main() {
    Address* address = new Address("Salvatorstrasse");
    PhDStudent* phd = new PhDStudent(address, 1, 2, 3);

    //access to the common field
    cout << phd->getAddress()->getStreet() << endl;
    
    //access to the common method
    phd->printInfo();

    Assistant* as = new PhDStudent(address, 1, 2, 3);
    //The following will not compile:
    //cout << as->getStudentId() << endl;

    return 0;
}

