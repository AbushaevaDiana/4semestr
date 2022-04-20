#include "Encode.h"
#include <string>
#include <vector>

const std::string quot = "&quot;";
const std::string apos = "&apos;";
const std::string lt = "&lt;";
const std::string gt = "&gt;";
const std::string amp = "&amp;";

std::string HtmlEncode(std::string const& text)
{

    std::string textEncode;
    //int size_t
    for (size_t i = 0; i < text.length(); i++)
    {

        switch (text[i]) 
        {
            case '"':
                //append or +=
                textEncode += quot;
                break;
            case '\'':
                textEncode += apos;
                break;
            case '<':
                textEncode += lt;
                break;
            case '>':
                textEncode += gt;
                break;
            case '&':
                textEncode += amp;
                break;
            default:
                textEncode += text[i];
                break;
        }
    }
	return textEncode;
}
