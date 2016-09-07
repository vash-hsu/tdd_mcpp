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
		// https://en.wikipedia.org/wiki/Soundex
        // a e h i o u w y -> 0
		// b f p v -> 1
		// c g j k q s x z -> 2
		// d t -> 3
		// l -> 4
		// m n -> 5
		// r -> 6
        const std::unordered_map<char, std::string> encodings
        {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
		    {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, 
			{'d', "3"}, {'t', "3"},
			{'l', "4"},
			{'m', "5"}, {'n', "5"},
			{'r', "6"}
        };
		/*
		if there is no {'z', "2"} in encodings
		Core was generated by `./runTests'.
		Program terminated with signal SIGSEGV, Segmentation fault.
		#0  0x00007f1bc73259bb in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
		#1  0x00000000004601f4 in Soundex::encodedDigit[abi:cxx11](char) const ()
		#2  0x00000000004602f7 in Soundex::encodedDigits(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) const ()
		*/
        // return encodings.find(letter)->second;
		//
		// http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
		// Return value
		// An iterator to the element, if the specified key value is found, or unordered_map::end if the specified key is not found in the container.
		
		//if ( encodings.find(letter) != encodings.end() )
		//{
		//	return encodings.find(letter)->second;
		//}
		//else
		//{
		//	return "";
		//}
		auto result = encodings.find(letter);
		return result == encodings.end() ? "": result->second;
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