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
    
    bool isComplete(const std::string& encoding) const
    {
        return encoding.length() == MaxCodeLength - 1;
    }

    std::string head(const std::string& word) const
    {
        return word.substr(0, 1);
    }

    std::string encodedDigits(const std::string& word) const
    {
        std::string encoding = "";
        for (auto letter: word)
        {
            if (isComplete(encoding))
            {
                break;
            }
            // 1(1) -> 1
            else if (encodedDigit(letter) != lastDigit(encoding))
            {
                encoding += encodedDigit(letter);
            }
        }
        return encoding;
    }
    
    std::string lastDigit(const std::string& encoding) const
    {
        if (encoding.empty())
        {
            return "";
        }
        // A reference to the last character in the string.
        // If the string object is const-qualified, the function returns a const char&.
        // Otherwise, it returns a char&.
        return std::string(1, encoding.back());
    }
    
    std::string tail(const std::string& word) const
    {
        return word.substr(1);
    }

public:

    std::string encodedDigit(char letter) const
    {
        const std::unordered_map<char, std::string> encodings
        {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, 
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
        };
        auto result = encodings.find(letter);
        return result == encodings.end() ? "": result->second;
    }
    
    std::string encode(const std::string& word) const
    {
        return zeroPad( head(word) + encodedDigits(tail(word)));
    }
};

#endif
