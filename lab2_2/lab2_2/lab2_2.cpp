
#include <iostream>
#include "Encode.h"

int main()
{
	while (std::cin.peek() != EOF)
	{
		std::string str;
		std::cin >> str;
		HtmlEncode(str);
		std::cout << str;
	}
    return 0;
}
