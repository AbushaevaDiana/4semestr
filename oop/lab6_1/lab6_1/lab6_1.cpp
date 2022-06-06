#include <iostream>
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
    while (!(std::cin.eof()))
    {
        std::cout << "> ";
        std::string str;
        getline(std::cin, str);
		try
		{
			CHttpUrl url(str);

			std::cout << "\nurl: " << url.GetURL() << "\n"
				<< "protocol: " << url.GetProtocolLikeString() << "\n"
				<< "domain: " << url.GetDomain() << "\n"
				<< "port: " << std::to_string(url.GetPort()) << "\n"
				<< "document: " << url.GetDocument() << "\n\n";
		}
		catch (const CUrlParsingError& e)
		{
			std::cout << e.what() << "\n\n";
		}
    }

	return EXIT_SUCCESS;
}

