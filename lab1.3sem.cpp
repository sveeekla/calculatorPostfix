//17 Михайловская
// Вычислить значение арифметического выражени, хранящегося в постфиксной форме
// В выражение входят: целые числа, знаки '+', '-', '*', '/', '~' (унарный минус).



#include "StackL.h"
#include <string>
#include<fstream>
#include<functional>




int menu(const char* message);
template<typename Predicat>
void ReadAndCheck(int& x, Predicat conditional, const char* massage);
double number(std::string str);
int stepen(int number, int cnt);
TInfo calculatePostfix(std::string str, bool& fl);


int main()
{
	std::ifstream file("test.txt");
	std::string str;
	getline(file, str);
	StackL st;
	int choice{};
	do {
		choice = menu("1. Add element\n2. Delete element\n3. Clear the stack\n4. Print the stack\n5. Task solution\n6. Exit\n");
		double elem{};
		switch (choice)
		{
		case 1:

			std::cout << "Enter the element: ";
			std::cin >> elem;
			st.push(elem);
			break;
		case 2:
			st.pop();
			break;
		case 3:
			st.clear();
			break;
		case 4:
			st.view();
			break;
		case 5:
		{
			std::cout << str << '\n';
			bool fl{ true };
			TInfo res = calculatePostfix(str, fl);
			if (fl)
				std::cout << res << '\n';
			else
				std::cout << "error" << '\n';
			break;
		}
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}

int menu(const char* message)
{
	std::cout << message;
	std::function<bool(int)> Lambda = [](int x) {return x >= 1 && x <= 6; };
	int choice{};
	ReadAndCheck(choice, Lambda, "\n->");
	return choice;
}

template<typename Predicat>
void ReadAndCheck(int& x, Predicat conditional, const char* massage)
{
	std::cout << massage;
	while (!(std::cin >> x && conditional(x)))
	{
		std::cout << "input error!\n";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << massage;
	}
}

double number(std::string str) 
{
	double result{};
	int sign{ 1 };
	char digit{};
	for (int i{}; i < str.length(); ++i)
	{
		digit = str[i];
		switch (str[i])
		{
		case('~'):
			sign = -1;
			break;
		case('.'):
			break;
		default:
			result = result * 10 + (str[i] - '0');
			break;
		}
	}
	return (sign < 1) ? result / (stepen(10, (str.find('.') - 1))) * sign : result / (stepen(10, (str.find('.')))) * sign;
}

int stepen(int number, int cnt)
{
	int res{1};
	for (int i{}; i < cnt; ++i)
	{
		res *= number;
	}
	return res;
}

TInfo calculatePostfix(std::string str, bool& fl)
{
	StackL st;
	size_t start{}, end{};
	std::string word;
	fl = true;
	while ((start = str.find_first_not_of(" ", end)) != std::string::npos)
	{
		end = str.find_first_of(" ", start);
		word = str.substr(start, end - start);
		if (std::isdigit(word[0]) || (word.size() > 1 && word[0] == '~'))
			st.push(number(word));
		else 
			if (word == "+" || word == "-" || word == "*" || word == "/")
			{
				if (st.size() < 2)
					fl = false;
				TInfo value2 = st.top();
				st.pop();
				TInfo value1 = st.top();
				st.pop();
				switch (word[0])
				{
				case '+':
					st.push(value1 + value2);
					break;
				case '-':
					st.push(value1 - value2);
					break;
				case '*':
					st.push(value1 * value2);
					break;
				case '/':
					if (value2 == 0) 
						fl = false;
					else
						st.push(value1 / value2);
					break;
				default:
					fl = false;

				}
			}
	}
	return st.top();
}
