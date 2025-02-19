#pragma once
// using 2 dimensional array to store student test grades.
#include <array>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include "student.h"

// Gradebook class definition
template<typename T, size_t NumStudents, size_t NumCourses>
class Gradebook {
	std::string gradebookId;  // a name that represents a cohort of students in a program, like CSTP202240 which represent spring cohort for CST program
	size_t numGradesSet{};  // represent how many students' grades have been set so far.
	std::array<Student<T, NumCourses>, NumStudents> grades; // 2D array

public:
	using StudentGrades = Student<T, NumCourses>;  // represent one student
	using CohortGrades = std::array<StudentGrades, NumStudents>;
	using CourseGrades = std::array<T, NumStudents>; // represents one course's grades for all students.

	// constructors
	Gradebook(std::string gbID = "") : gradebookId(gbID), numGradesSet{ 0 } {
		std::cout << "Gradebook created.\n";
		grades.fill(Student<T, NumCourses>());
	}

	Gradebook() = delete;  // default constructor is not available

	void addStudent(StudentGrades aStudentGrades) {
		if (numGradesSet < grades.size()) {
			grades[numGradesSet] = aStudentGrades;
			++numGradesSet;
		}
	}
	~Gradebook() {
		std::cout << "gradebook destroyed. TotalNumGradebooks="
			<< getGradebookId() << std::endl;
	}

	void setGradebookId(std::string id) {
		gradebookId = id;
	}
	std::string getGradebookId() const {
		return gradebookId;
	}

	CourseGrades getACourseGrades(std::string courseName) const {

		CourseGrades grade;
		for (int i = 0; i < NumStudents; ++i) {
			for (int j = 0; j < NumCourses; ++j) {
				if (grades[i].getCourse(j).name == courseName) {
					grade[i] = grades[i].getCourse(j).grade;
				}
			}
		}
		return grade;
	}

	void displayMessage() const {
		std::cout << "Welcome to the grade book for cohort " << gradebookId << "\n";
	}

	// return the name of a course usign idx into grades array of first student
	std::string getCourseNameFromIdx(size_t idx) const {
		return grades[0].getCourse(idx).name;
	}
	// output to commandline students grades for all courses, one student per row, like:
	// 1- studentName studentID  grade1 grade2 grade3 ....
	// 2- studentName studentID  grade1 grade2 grade3 ....
	// 
	void outputGradesPerStudent() const {
		// your code for output student grades goes here.
		// Looping through all the students
		for (int i = 0; i < NumStudents; ++i) {
			// Printing all the name and ID
			std::cout << i + 1 << "- " << grades[i].getName() << " " << grades[i].getID() << " ";
			// Looping through all the courses
			for (int j = 0; j < NumCourses; ++j) {
				// Printing all the grades
				std::cout << grades[i].getCourse(j).grade << " ";
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < NumCourses; ++i) {
			// Looping throug the courses to get the course name
			std::string courseName = getCourseNameFromIdx(i);
			std::cout << "\n Lowest grade for course " << courseName << " is " << getMinimum(courseName);
			std::cout << "\n Highetst grade for course " << courseName << " is " << getMaximum(courseName) << std::endl;
		}
	}

	// Find and return minimum grade for a course:
	T getMinimum(std::string courseName) const {
		T lowGrade{ 101 };
		// you code goes here for finding lowGrade.

		// Nested loop to find the the lowest grade for the course
		for (int i = 0; i < NumStudents; ++i) {
			for (int j = 0; j < NumCourses; ++j) {
				if (grades[i].getCourse(j).name == courseName) {
					lowGrade = std::min(lowGrade, grades[i].getCourse(j).grade);
				}
			}

		}
		return lowGrade;
	}

	// Find and return max grade for a course:
	T getMaximum(std::string courseName) const {
		T highGrade{ -1 };
		// you code goes here for finding highGrade.

		// Nested for loop to find the highest grade for the course
		for (int i = 0; i < NumStudents; ++i) {
			for (int j = 0; j < NumCourses; ++j) {
				if (grades[i].getCourse(j).name == courseName) {
					highGrade = std::max(highGrade, grades[i].getCourse(j).grade);
				}
			}
		}
		return highGrade;
	}

	// find the average grade for each course an print it using a star bar, like the following:
	//	CouseName			Average (from 0 to 10)
	//	WebSiteDevelpment	********    // means average grade is 8 x 10 = 80
	//	ComputerAdmin		*********	// means average grade is 9 x 10 = 90
	//	IntroToProgramming	******		// means average grade is 6 x 10 = 60
	// 
	// You should use setw(20) to aling the stars on column 20 on each row.
	void outputGradeAveragePerCourseBarChart() const {
		// your code goes here.

		std::cout << std::left << std::setw(20) << "CourseName" << "Average (from 0 to 10)" << std::endl;

		for (int i = 0; i < NumCourses; ++i) {
			std::string courseName = getCourseNameFromIdx(i);
			// Assigning the * symbol 
			int avg = getAverageGradePerCourse(courseName);
			int avgStar = avg / 10;
			std::cout << std::left << std::setw(20) << courseName;

			// Iterating through the average grade to add up the astericks needed for each course
			for (int i = 0; i < avgStar; ++i){
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}

	// determine average grade for a particular student
	T getAverageGradePerStudent(size_t studentID) const {
		// your code goes here.
		T avg{ 0 };

		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getID() == studentID) {
				for (int j = 0; j < NumCourses; ++j) {
					avg += grades[i].getCourse(j).grade;
				}
				avg /= NumCourses;
			}
		}
		return avg;
	}
	T getAverageGradePerStudent(std::string studentName) const {
		// your code goes here.
		T avg{ 0 };

		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getName() == studentName) {
				for (int j = 0; j < NumCourses; ++j) {
					avg += grades[i].getCourse(j).grade;
				}
				avg /= NumCourses;
			}
		}
		return avg;
	}

	int getStudentID(std::string studentName) {
		// your code goes here
		int studentID = 0;
		// Looping through students to get student ID 
		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getName() == studentName) {
				studentID += grades[i].getID();
			}
		}
		return studentID;
	}
	// determine average grade for a particular test
	T getAverageGradePerCourse(std::string courseName) const {
		T avg{ 0 };
		// your code goes here
		// Looping through student to find average grade for a specific course 
		for (int i = 0; i < NumStudents; ++i) {
			for (int j = 0; j < NumCourses; ++j) {
				if (grades[i].getCourse(j).name == courseName) {
					avg += grades[i].getCourse(j).grade;
				}
			}
		}
		avg /= NumStudents;
		return avg;
	}

	T getStudentGradeForCourse(std::string studentName, std::string courseName) {
		T grade{ 0 };
		// your code goes here
		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getName() == studentName) {
				for (int j = 0; j < NumCourses; ++j) {
					if (grades[i].getCourse(j).name == courseName) {
						grade += grades[i].getCourse(j).grade;
					}
				}
			}
		}
		return grade;
	}
	// update the grade for a given student for a given course to the newgrade.
	void updateStudentCourseGrade(std::string courseName, std::string studentName, T newgrade) {
		// your code goes here
		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getName() == studentName) {
				for (int j = 0; j < NumCourses; ++j) {
					if (grades[i].getCourse(j).name == courseName) {
						grades[i].setCourseGrade(j, newgrade);
					}
				}
			}
		}
	}


	void setStudentGrade(std::string studentName, int studentID, std::string courseName, T grade) {
		// your code goes here.
		for (int i = 0; i < NumStudents; ++i) {
			if (grades[i].getName() == studentName || grades[i].getID() == studentID) {
				for (int j = 0; j < NumCourses; ++j) {
					if (grades[i].getCourse(j).name == courseName) {
						grades[i].setCourseGrade(j, grade);
					}
				}
			}
		}
	}

	// This function builds a gradebook using the data in the inputfile. The type of grades is given as template argument T
	static Gradebook buildGradeBookFromFile(std::string inputfile) {
		// your code goes here
		// the following return is just an example. YOu must modify it once 
		// the loading of the datafile is done properly.
		std::ifstream fs(inputfile);
		std::string gradebookId;
		std::getline(fs, gradebookId);
		Gradebook<T, NumStudents, NumCourses> gradebook(gradebookId);

		std::string line;
		size_t i = 0;
		for (int i = 0; i < NumStudents; ++i) {
			std::getline(fs, line);
			std::istringstream ss(line);
			std::string name;
			int id = 0;
			ss >> name >> id;
			gradebook.grades[i].setName(name);
			gradebook.grades[i].setID(id);
			for (int j = 0; j < NumCourses; ++j) {
				std::string courseName;
				T grade{};
				ss >> courseName >> grade;
				gradebook.grades[i].addCourse(courseName, grade);
			}
		}
		fs.close();
		return gradebook;
	}
};
