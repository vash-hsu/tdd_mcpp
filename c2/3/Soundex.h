#ifndef Soundex_h
#define Soundex_h
#include <string>

static const size_t MaxCodeLength{4};


class Soundex
{

private:

    std::string zeroPad(const std::string& word) const
    {
        //int zerosNeeded = 4 - word.length();
        int zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }

    std::string head(const std::string& word) const
    {
        return word.substr(0, 1);
    }

    std::string encodedDigit() const
    {
        return "1";
    }

    std::string encodedDigits(const std::string& word) const
    {
        if (word.length() > 1)
        {
            //return "1";
            return encodedDigit();
        }
        else
        {
            return "";
        }
    }

public:

    std::string encode(const std::string& word) const
    {
        return zeroPad( head(word) + encodedDigits(word));
    }
};

#endif
