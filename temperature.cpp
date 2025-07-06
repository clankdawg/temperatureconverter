#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string trim(const std::string& str) {
    auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
    auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end ? std::string(start, end) : "");
}

float celcius, faren, kelv = 0;
std::string i = "0";

int main() {
	std::cout << "This is a temperature converter\n";
	while (i == "0"){
   	std::cout << "Enter a number followed by a unit (kelv, celcius, or faren):\n";

  	  std::string input;
  	  std::getline(std::cin, input);
  	  input = trim(input); // remove leading/trailing spaces

   	 std::istringstream iss(input);
   	 double number;
   	 std::string unit;

	if (!(iss >> number >> unit)) {
        std::cout << "Invalid input. Try again.\n";
        continue;
    }

		 if (unit == "celcius"){
			celcius = number;
			faren = celcius * 9.0 / 5.0 + 32;
			kelv = celcius + 273.15;
		 }else if (unit == "kelv"){
			kelv = number;
			celcius = kelv - 273.15;
			faren = celcius * 9.0 / 5.0 + 32;
		 }else if (unit == "faren"){
			faren = number;
			celcius = (faren - 32) * 5.0 / 9.0;
			kelv = celcius + 273.15;
		 } else {
			std::cout << "Unknown unit: " << unit << std::endl;
			return 0;
		 }

		std::cout << "\nConversions:\n";
   		std::cout << "Celsius:    " << celcius << " °C\n";
      std::cout << "Fahrenheit: " << faren << " °F\n";
      std::cout << "Kelvin:     " << kelv << " K\n\n";
	}
    return 0;
}
