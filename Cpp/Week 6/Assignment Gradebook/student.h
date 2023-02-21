
#pragma once

#include <string>
#include <vector>
#include <iostream>


// represents a course and the grade student received in this course. The grade type is templated type T.
template<typename T>
struct Course
{
	std::string name;
	T grade;
	Course(std::string n = "CourseNotSet", T g = T{}) : name(n), grade(g) {}//this is also a default constrructor

	void setGrade(T g)
	{
		grade = g;
	}
};

// represents a student and its grades in all courses she has taken so far.
template<typename T, size_t NumGrades>
class Student
{

	std::string name;
	int id;
	size_t numCoursesSet{};
	std::array<Course<T>, NumGrades> courses;

	//Student()   // defauilt constructor is private, so only accessible inside the class
	//{}

public:
	Student(std::string n = "NotSet", int d = -1) : name(n), id(d), numCoursesSet(0)
	{
		std::cout << "Student : (" << name << ", " << id << ") created\n";
	}

	Course<T> getCourse(size_t idx) const
	{
		return courses.at(idx);
	}

	void setCourseGrade(size_t idx, T g)
	{
		courses.at(idx).setGrade(g);
	}

	//THis method computes the average grade for all the courses for this student and return it.
	T computeAverage()
	{
		T avg{ 0 };
		// your code goes here.
		for (int i = 0; i < NumGrades; ++i) {
			avg += courses[i].grade;
		}
		avg /= NumGrades;
		return avg;
	}

	void addCourse(std::string coursename, T g)
	{
		if (numCoursesSet < NumGrades)
			courses[numCoursesSet++] = Course<T>(coursename, g);
	}

	std::string getName() const
	{
		return name;
	}

	void setName(std::string n)
	{
		if (n.length() > 1)
			name = n;
	}

	int getID() const
	{
		return id;
	}

	void setID(int n)
	{
		if (n > 0)
			id = n;
	}

};
