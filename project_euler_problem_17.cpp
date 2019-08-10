#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string ones(int num);
string teens(int num);
string tens(int num);
string hundreds(int num);
string thousands(int num);
vector<int> get_digits(int num);

int main()
{

	string str_all_numbers = "";


	for (int i = 1; i < 1001; i++) {
		vector<int> vec_i = get_digits(i); // turn ith digit into vectorized form
		int vec_size_i = vec_i.size(); // size of ith vector

		if (vec_size_i == 1) { // process ones
			str_all_numbers = str_all_numbers + ones(vec_i[0]);
		}
		else if (vec_size_i == 2) {

			if (vec_i[0] == 1) {
				str_all_numbers = str_all_numbers + teens(vec_i[1]);
			}
			else {
				str_all_numbers = str_all_numbers + tens(vec_i[0]) + ones(vec_i[1]);
			}

		}
		else if (vec_size_i == 3) {


			str_all_numbers = str_all_numbers + hundreds(vec_i[0]);

			if (vec_i[1] == 0 and vec_i[2] == 0) {
				continue;
			}
		 	else {
				str_all_numbers = str_all_numbers + "and";

				if (vec_i[1] == 1) {
					str_all_numbers = str_all_numbers + teens(vec_i[2]);
				}
				else {
					str_all_numbers = str_all_numbers + tens(vec_i[1]) + ones(vec_i[2]);
				}
			}
		}

		else if (vec_size_i == 4) {
			str_all_numbers = str_all_numbers + "onethousand";
		}
	}

	cout << str_all_numbers << endl;

	cout << "The total length of concatenating all the numbers (in words) from 1 to 1000 is :"
		<< str_all_numbers.length() << endl;

  return 0;
}

string ones(int num) {
	switch (num)
	{
	  case 1:
	  	return "one";
	  case 2:
	  	return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
	  default:
	     return "";
	}
}

string teens(int num) {
	switch (num)
	{
		case 0:
			return "ten";
	  case 1:
	  	return "eleven";
	  case 2:
	  	return "twelve";
		case 3:
			return "thirteen";
		case 4:
			return "fourteen";
		case 5:
			return "fifteen";
		case 6:
			return "sixteen";
		case 7:
			return "seventeen";
		case 8:
			return "eighteen";
		case 9:
			return "nineteen";
	  default:
	     return "";
	}
}

string tens(int num) {
	switch (num)
	{
		case 2:
			return "twenty";
	  case 3:
	  	return "thirty";
	  case 4:
	  	return "forty";
		case 5:
			return "fifty";
		case 6:
			return "sixty";
		case 7:
			return "seventy";
		case 8:
			return "eighty";
		case 9:
			return "ninety";
	  default:
	     return "";
	}
}

string hundreds(int num) {
	switch (num)
	{
		case 1:
			return "onehundred";
		case 2:
			return "twohundred";
	  case 3:
	  	return "threehundred";
	  case 4:
	  	return "fourhundred";
		case 5:
			return "fivehundred";
		case 6:
			return "sixhundred";
		case 7:
			return "sevenhundred";
		case 8:
			return "eighthundred";
		case 9:
			return "ninehundred";
	  default:
	     return "";
	}
}

// returns a vectorized form of input num
// e.g. 23 becomes [2,3] ; this way we break this into 'twenty' and 'three'
vector<int> get_digits(int num) {
	vector<int> vectorized_num; // stores the vectorized form of input num
	string str_num = to_string(num); // convert input num to string

	cout << str_num <<endl;
	int x = 0;
	// int x = 0;
	for (int i = 0; i < str_num.length(); i++) {
		// stringstream toint(str_num[i]);
		//
		// toint >> x;
		x = str_num[i] - '0';
		// pushes ith element to the back of the vector
		vectorized_num.push_back(x);
	}
	return vectorized_num;
}
