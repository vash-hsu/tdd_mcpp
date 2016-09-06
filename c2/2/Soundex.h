#ifndef Soundex_h
#define Soundex_h
#include <string>


class Soundex
{

private:

    std::string zeroPad(const std::string& word) const
    {
        //Value of: "A100"
        //Expected: soundex.encode("Ab")
        //Which is: "A1000"
        int zerosNeeded = 4 - word.length();
        //return word + "000";
        return word + std::string(zerosNeeded, '0');
    }

public:

    std::string encode(const std::string& word) const
    {
        //Value of: "A100"
        //Expected: soundex.encode("Ab")
        //Which is: "Ab000"
        std::string encoded = word.substr(0, 1);
        if (word.length() > 1)
        {
            encoded += "1";
        }
        //return zeroPad(word);
        return zeroPad(encoded);
    }
};


#endif
