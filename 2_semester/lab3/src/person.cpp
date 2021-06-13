#include "person.h"
#include <iostream>

Person::Person() {
    this->ID = 0;
    this->first_name = "";
    this->last_name = "";
}

Person::Person(int ID, std::string first_name, std::string last_name) {
    this->ID = ID;
    this->first_name = first_name;
    this->last_name = last_name;
}

Person::Person(const Person& p) {
    this->ID = p.ID;
    this->first_name = p.first_name;
    this->last_name = p.last_name;
}

void Person::Set(int ID, std::string first_name, std::string last_name) {
    this->ID = ID;
    this->first_name = first_name;
    this->last_name = last_name;
}

int Person::GetID() {
    return ID;
}

std::string Person::GetFirstName() {
    return first_name;
}

std::string Person::GetLastName() {
    return last_name;
}

bool Person::operator == (const Person& other) {
    return this->ID == other.ID;
}

bool Person::operator != (const Person& other) {
    return this->ID != other.ID;
}

bool Person::operator < (const Person& other) {
    return this->ID < other.ID;
}

bool Person::operator > (const Person& other) {
    return this->ID > other.ID;
}

bool Person::operator <= (const Person& other) {
    return this->ID <= other.ID;
}

bool Person::operator >= (const Person& other) {
    return this->ID >= other.ID;
}

std::ostream& operator << (std::ostream &out, const Person &p) {
    out << "[" << p.ID << ": " << p.first_name << p.last_name << "]";
    return out;
}

Student::Student() {
    Person();
    this->group = "";
}

Student::Student(int ID, std::string first_name, std::string last_name, std::string group): Person(ID, first_name, last_name) {
    this->group = group;
}

Student::Student(Person& p) {
    Person(p.GetID(), p.GetFirstName(), p.GetLastName());
    this->group = "";
}

Student::Student(const Student& s): Person(s.ID, s.first_name, s.last_name) {
    this->group = s.group;
}

void Student::SetS(int ID, std::string first_name, std::string last_name, std::string group) {
    Set(ID, first_name, last_name);
    this->group = group;
}

std::string Student:: GetGroup() {
    return group;
}

std::ostream& operator << (std::ostream &out, const Student &s) {
    out << "[" << s.ID << ": " << s.first_name << " " << s.last_name << ", " << s.group << "]";
    return out;
}

Teacher::Teacher() {
    Person();
    this->subject = "";
}

Teacher::Teacher(int ID, std::string first_name, std::string last_name, std::string subject): Person(ID, first_name, last_name) {
    this->subject = subject;
}

Teacher::Teacher(Person& p) {
    Person(p.GetID(), p.GetFirstName(), p.GetLastName());
    this->subject = "";
}

Teacher::Teacher(const Teacher& t): Person(t.ID, t.first_name, t.last_name) {
    this->subject = t.subject;
}

void Teacher::SetT(int ID, std::string first_name, std::string last_name, std::string subject) {
    Set(ID, first_name, last_name);
    this->subject = subject;
}

std::string Teacher:: GetSubject() {
    return subject;
}

std::ostream& operator << (std::ostream &out, const Teacher &t) {
    out << "[" << t.ID << ": " << t.first_name << " " << t.last_name << ", " << t.subject << "]";
    return out;
}

std::string to_string(Person &p) {
    return std::to_string(p.GetID()) + ": " + p.GetFirstName() + " " + p.GetLastName();
}

std::string to_string(Student &s) {
    return std::to_string(s.GetID()) + ": " + s.GetFirstName() + " " + s.GetLastName() + ", " + s.GetGroup();
}

std::string to_string(Teacher &t) {
    return std::to_string(t.GetID()) + ": " + t.GetFirstName() + " " + t.GetLastName() + ", " + t.GetSubject();
}
