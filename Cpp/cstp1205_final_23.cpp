///////////////////////////////////////////////////////////////////////////////////////////////////////
//  FINAL EXAM: CSTP1205 Winter 2023
// Student NAME: Muochu Hu
// Student ID: 000471438
// It is a closed book test. NO WEB SEARCH OR SITE ALLOWED. You can use your own notes and assignments
// Exam time is 2 1/2 hours sharp!
// Answer all questions bellow. You can use visual studio to do the work. But at the end copy the code to the slot provided bellow each question. 
// Once finished, Upload this file with your answers in it to moodle.
//////////////////////////////////////////////////////////////////////////////////////////////////////
//1) Consider the following class A and its testing code:
class A
{
	char c[100];
	int n;
	std::vector<int> vec;

public:

	A(int count) :n(count)
	{	
		// Question 1: initialize c to be filled by character sequence "FE". This means C[] would contain "FEFEFEFE..."
		
		std::cout << "A created : n = " << n << ", vec size is " << vec.size() << std::endl;

		// here goes your answer
		std::fill_n(c, 100, 0); // Initialize c with 0s
		for (int i = 0; i < 100; i += 2) {
			c[i] = 'F';
			c[i + 1] = 'E';
		}
	}

	~A()
	{
		// Question 2: Print out the content of vec in a row, numbers separated by ,
		std::cout << "~A: n=" << n << ", vec size is " << vec.size() << std::endl;
		for (int i = 0; i < vec.size(); ++i) {
			std::cout << vec[i] << " , ";
		}
		std::cout << std::endl;
	}


	// Question 2: set vector vec to contain numbers 1, 2, 3, ..., n.
	void setVec()
	{
		// here goes your answer
		vec.clear();
		for (int i = 1; i <= n; ++i) {
			vec.push_back(i);
		}
	}
};


int main()
{
	A* pA1 = new A(6);
	A* pA2 = new A(20);

	pA1->setVec();

	delete pA1;
	delete pA2;

	return 0;
}
/*
Answer the following questions:
Question 1: Complete the constructor of A above by initializing the character array c as requested in the constructor.
(initialized c above with FEFE sequence) 

Question 2: Implement the function setVec() as explained in the comment section above set().
(Implemented above)

Question 3: Write the output of this program as accurately as possible, Remember no need to generate exe and run. You should be able to figure out what would be printed out and at which order without actually compile and run.

A created : n = 6, vec size is 0
~A: n=6, vec size is 6
1 2 3 4 5 6
A created : n = 20, vec size is 0
~A: n=20, vec size is 20

- 2 instances of the A class with counts 6 and 20 are created
- The constructor for each instance initializes the c array to "FEFEFEFE..." and prints a message indicating the count and the size of the vec vector (which is initially empty).
- setVec function is called on pA1, which sets the vec vector to contain the numbers 1 to 6.
- both instances of the A class are delete, which triggers the destructor.
- The destructor for each instance prints a message indicating the count and the size of the vec vector



Question 4: Modify the above main() function to use shared pointers instead of raw pointers. We want the modified program still print out exactly what it is printing out now. So basically do not modify the functionality of the program. Write out the modified
main function bellow:


int main()
{
	std::shared_ptr<A> pA1 = std::make_shared<A>(6);
	std::shared_ptr<A> pA2 = std::make_shared<A>(20);

	pA1->setVec();

	return 0;
}
---------------------------------------------------------------------------------------------
-----------------------------------------------------------
2) a) Create a templated function named MaxOf3(T val1, T val2, T val3) which finds the maximum val among the 3 values provided and return it. You must write the full templated function bellow. The type of val1, val2, and val3 is T.

template<typename T>
T MaxOf3(T val1, T val2, T val3)
{
	T maxVal = val1;

	if (val2 > maxVal) {
		maxVal = val2;
	}

	if (val3 > maxVal) {
		maxVal = val3;
	}
	return maxVal;
}


b) Let's say we have a struct Coord like this : struct Coord{ int x, y;}. Write a specialization of MaxOf3() for objects of type Coord which finds the Coord whose distance from center is maximum. It means x*x + y*y is maximum among the 3 inputs to MaxOf3().


#include <cmath>

struct Coord
{
	int x, y;
};

double distanceFromCenter(const Coord& c)
{
	return std::sqrt(c.x * c.x + c.y * c.y);
}

template<>
Coord MaxOf3(Coord val1, Coord val2, Coord val3)
{
	double dist1 = distanceFromCenter(val1);
	double dist2 = distanceFromCenter(val2);
	double dist3 = distanceFromCenter(val3);

	if (dist1 >= dist2 && dist1 >= dist3) {
		return val1;
	} else if (dist2 >= dist1 && dist2 >= dist3) {
		return val2;
	} else {
		return val3;
	}
}



---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------
3) Suppose we have a templated structure representing a 2D point like this
*/
template<class T>
struct  Point
{
	T  x, y;
	Point(T a, T b) :x(a), y(b) {}
	Point  operator+ (const Point& rhs)
	{
		Point result(x + rhs.x, y + rhs.y);
		return result;
	}
	Point& operator/ (T d)
	{	
		x /= d;
		y /= d;
		return *this;
	}
};


/*
i) Return the overloaded operator+ so that  a+b (a and b are both 2D points) returns a new point c by adding x’s together and y’s together of a and b

ii) The operator / is for division of a's coordinates x and y by d.


-----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------
4) We have an array of n objects of type T: std::array<T, n> theArray.
 Write a templated function Reverse() that receives theArray as reference argument and reverse the order of elements in the array.
 For example for array of 4 int array<int, 4> myints{5, 7, 2, 9}, Reverse(myInts) will reverse the orders to {9, 2, 7, 5}.
 Notice that function template Reverse does not return anything,it means it returns void.
*/


template<typename T, size_t n>
void Reverse(std::array<T, n>& theArray)
{
	for (int i = 0; i < n / 2; ++i) {
		std::swap(theArray[i], theArray[n - i - 1]);
	}
}
