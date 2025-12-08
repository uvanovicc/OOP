#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Course.h"
using namespace std;

class Student {
private:
	int id;
	string name;
	string study_program;
	int year;

	static int total_students;

	Course* enrolled_courses;
	size_t enrolled_count;

public:
	Student(int _id = 0, string n = "", string prog = "", int y = 1);

	~Student();
	Student(const Student& other);
	Student(Student&& other) noexcept;
	Student& operator = (const Student& other) noexcept;

	static int get_total_students();
	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream is, Student& s);

	Student& operator+=(const Course& c);
	Student& operator++();
	Student operator++(int);

	void compliete_course(const Course& c);
	int getTotalECTS() const;

};

#endif