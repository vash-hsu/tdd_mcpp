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

    std::string encodedDigits(const std::string& word) const
    {
        std::string encoding = "";
        for (auto letter: word)
        {
			// refactor to introduce length limitation
            //encoding += encodedDigit(letter);
			/*
			if (encoding.length() == MaxCodeLength - 1)
			{
				break;
			}
			encoding += encodedDigit(letter);
			*/
			
			// more readable code
			if (isComplete(encoding))
			{
				break;
			}
			encoding += encodedDigit(letter);
        }
        return encoding;
    }
    
    std::string tail(const std::string& word) const
    {
        return word.substr(1);
    }

public:

    std::string encode(const std::string& word) const
    {
        return zeroPad( head(word) + encodedDigits(tail(word)));
    }
};

#endif
