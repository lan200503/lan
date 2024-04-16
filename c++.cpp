#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Person
{
    public:
        string name;
        int age;

        Person(){};
        Person(string name,int age);
        ~Person(){};

        void eat(){};
        void sleep(){};
        void play(){};
        void Print(){};
    private:
        string ID_number;
};

Person::Person(string name, int age) : name(name), age(age) {};


class Employee :virtual public Person
{
    public:
        double salary;

        Employee(){};
        Employee(string name,int age,double salary);
        ~Employee(){};

        void work(){};
};

Employee::Employee(string name,int age,double salary) :Person(name,age),salary(salary){};

class Student :virtual public Person
{
    public:
        int grade;
        char mark;

        Student(){};
        Student(string name,int age,int grade,char mark);
        ~Student(){};
        void study(){};
};

Student::Student(string name,int age,int garde,char mark) :Person(name,age), grade(garde),mark(mark){};

class Parttime_Graduate_Student:public Student,public Employee
{
    public:
        Parttime_Graduate_Student(){};
        Parttime_Graduate_Student(string name,int age,double salary,int grade,char mark);
        ~Parttime_Graduate_Student(){};

        void Print();
};

Parttime_Graduate_Student::Parttime_Graduate_Student(string name,int age,double salary,int grade,char mark):Person(name,age), Employee(name, age, salary), Student(name, age, grade,mark)
{
    
}

void Parttime_Graduate_Student::Print()
{
    cout << "Name: " << name << ", Age: " << age << ", Salary: " << salary << ", Grade: " << grade <<", Mark: "<< mark << endl;
}

int main()
{
    Parttime_Graduate_Student A("lan",20,4000.0,18,'A');
    A.Print();
}