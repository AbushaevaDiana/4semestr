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
    for (int i = 0; i < text.length(); i++)
    {

        switch (text[i]) 
        {
            case '"':
                textEncode = textEncode + quot;
                break;
            case '\'':
                textEncode = textEncode + apos;
                break;
            case '<':
                textEncode = textEncode + lt;
                break;
            case '>':
                textEncode = textEncode + gt;
                break;
            case '&':
                textEncode = textEncode + amp;
                break;
            default:
                textEncode = textEncode + text[i];
        }
    }
	return textEncode;
}
