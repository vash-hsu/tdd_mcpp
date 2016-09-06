#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>


static const size_t MaxCodeLength{4};


class Soundex
{

private:

    std::string zeroPad(const std::string& word) const
    {
        int zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }

    std::string head(const std::string& word) const
    {
        return word.substr(0, 1);
    }

    //std::string encodedDigit() const
    std::string encodedDigit(char letter) const
    {
        //return "1";
        const std::unordered_map<char, std::string> encodings
        {
            {'b', "1"},
            {'c', "2"},
            {'d', "3"}
        };
        return encodings.find(letter)->second;
    }

    std::string encodedDigits(const std::string& word) const
    {
        if (word.length() > 1)
        {
            //return encodedDigit();
            return encodedDigit(word[1]);
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
