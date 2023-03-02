#pragma once
#include <string>

class PhoneNumber {
private:
	std::string areaCode;  // 3-digit area code
	std::string exchange;  // 3-digit exchange
	std::string line;  // 4-digit line 

public:
	PhoneNumber(std::string a = "000", std::string e = "000", std::string l = "0000");

	friend std::ostream& operator<<(std::ostream&, const PhoneNumber&); // std::cout<<ph;  cout<<"My name is "<<" Reza" <<endl;
	friend std::istream& operator>>(std::istream&, PhoneNumber&);  // std::in >> ph; std::cin >> i;

	void setPhoneNumber(std::string ac, std::string ex, std::string ln) {
		areaCode = ac;
		exchange = ex;
		line = ln;
	}

};
