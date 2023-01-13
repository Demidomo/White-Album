#include <iostream>
#include <array>
#include <vector>

using namespace std;

// A utility function to print a vector
void printVec(vector<int> vec)
{
	for (auto item : vec)
		cout << item << " ";

	cout << "\n";
}


int main()
{
/*	int count{};  // initializes count to default value for int
	std::cout<<"What is your name?\n";
	std::string myname{"NotSetYet"};
	std::string mylastname{"Notset"};
	//std::cin>>myfirstname>>mylastname;
	std::getline(myname);
	myprint(myname); // change myprint() to receive the string and print it.
*/	
	
	// arrays in c++:
	std::array<int, 5> my5Numbers{4, 5, 6};
	my5Numbers[3] = 7;
	my5Numbers.at(4) = 8;
	for(int i=0; i<my5Numbers.size(); ++i)
	{
		std::cout<<"valu at "<<i<<" is "<<my5Numbers.at(i)<<std::endl;
	}
	
	my5Numbers[2] = 9;
	
	for( auto item : my5Numbers)
	{
		std::cout<<"item = "<<item<<std::endl;
	}
	
	std::vector<int> myInts{};
	std::cout<<"Size of myInts: "<<myInts.size()<<std::endl;
	myInts.push_back(1);
	std::cout<<"Size of myInts: "<<myInts.size()<<std::endl;
	myInts.push_back(2);
	std::cout<<"Size of myInts: "<<myInts.size()<<std::endl;
	myInts.push_back(3);
	std::cout<<"Size of myInts: "<<myInts.size()<<std::endl;
	myInts.push_back(4);
	std::cout<<"Size of myInts: "<<myInts.size()<<std::endl;

	// Print array
	printVec(myInts);

	// myInts[2] = 9;

	
	/* for (auto item : myInts) {
		myInts.push_back(item * 2);
	}
	*/
	

	// Adding even number set at the end of array
	int currSize = myInts.size();
	for (int i = 0; i < currSize; ++i)
		myInts.push_back(2 * myInts[i]);

	// Print array
	printVec(myInts);

	// Removing items
	myInts.pop_back();
	myInts.pop_back();


	// Print the content of the myInt vector/array
	printVec(myInts);

	// Print the vector using iterators
	cout << endl; 
	for (auto it = myInts.begin(); it < myInts.end(); ++it)
		cout << *it << " ";

	cout << endl;

	// insert 22 at index 2
	auto index2It = myInts.begin() + 2;
	myInts.insert(index2It, 3, 22);

	cout << "Printing after inserting 22" << endl;;

	// Print the content of the myInt vector/array
	printVec(myInts);


	// make an array to print 100 times
	std::vector<int> secondVec(100, -1);

	for(auto item : secondVec)
		std::cout<<" "<<item<<" ";
	
	// create an array of 5 strings and put "str0", "str1", ..."str4" in it and print it.
	array <string,5> testArr{"str1","str2","str3","str4","str5"};
    for (auto& item : testArr)	
		cout << item << endl;
	


	return 0;
}


