#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
protected:
    int ID;
    std::string first_name;
    std::string last_name;

public:
    Person();
    Person(int ID, std::string first_name, std::string last_name);
    Person(const Person& p);

    void Set(int ID, std::string first_name, std::string last_name);
    int GetID();
    std::string GetFirstName();
    std::string GetLastName();

    bool operator == (const Person &other);
    bool operator != (const Person &other);
    bool operator < (const Person &other);
    bool operator > (const Person &other);
    bool operator <= (const Person &other);
    bool operator >= (const Person &other);

    friend std::ostream& operator << (std::ostream &out, const Person &p);

};

class Student : public Person
{
    std::string group;

public:
    Student();
    Student(int ID, std::string first_name, std::string last_name, std::string group);
    Student(Person& p);
    Student(const Student& s);

    void SetS(int ID, std::string first_name, std::string last_name, std::string group);
    std::string GetGroup();

    friend std::ostream& operator << (std::ostream &out, const Student &s);
};

class Teacher : public Person
{
    std::string subject;

public:
    Teacher();
    Teacher(int ID, std::string first_name, std::string last_name, std::string subject);
    Teacher(Person& p);
    Teacher(const Teacher& t);

    void SetT(int ID, std::string first_name, std::string last_name, std::string subject);
    std::string GetSubject();

    friend std::ostream& operator << (std::ostream &out, const Teacher &t);
};

std::string to_string(Person &p);
std::string to_string(Student &s);
std::string to_string(Teacher &t);

#endif // PERSON_H
