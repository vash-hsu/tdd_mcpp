#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;


class SoundexEncoding: public Test
{

public:
    Soundex soundex;

};


TEST_F(SoundexEncoding, LimitsLenghtToFourCharacters)
{
	// ./runTests
    /*
    [ RUN      ] SoundexEncoding.LimitsLenghtToFourCharacters
    unknown file: Failure
    C++ exception with description "basic_string::_M_create" thrown in the test body.
    [  FAILED  ] SoundexEncoding.LimitsLenghtToFourCharacters (0 ms)
    */
	// ulimit -c unlimited
	// ./runTests --gtest_catch_exceptions=0
	/*
	[ RUN      ] SoundexEncoding.LimitsLenghtToFourCharacters
	terminate called after throwing an instance of 'std::length_error'
	  what():  basic_string::_M_create
	Aborted (core dumped)
	*/
	/*
	#6  0x00007f9bc4b1526f in std::__throw_length_error(char const*) () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#7  0x00007f9bc4b7e099 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long) ()
	   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#8  0x00007f9bc4b7e12c in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct(unsigned long, char) ()
	   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#9  0x000000000046251e in Soundex::zeroPad(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) const ()
	#10 0x0000000000462ed2 in Soundex::encode(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) const ()
	*/
	// CMakeList.txt
	// set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2 -g")
	/*
	#6  0x00007f10a774f26f in std::__throw_length_error(char const*) () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#7  0x00007f10a77b8099 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long) ()
	   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#8  0x00007f10a77b812c in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct(unsigned long, char) ()
	   from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
	#9  0x000000000045a4a6 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string (__a=..., __c=48 '0', __n=<optimized out>, 
		this=0x7fffc94cdbf0) at /usr/include/c++/5/bits/basic_string.h:466
	#10 Soundex::zeroPad (this=0x7f10a70cb008, word="D2341") at /home/vash_hsu/working/TDD/c2/7/Soundex.h:19
	*/
	// 
    ASSERT_EQ(soundex.encode("Dcdlb").length(), 4u);
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    EXPECT_EQ(soundex.encode("Acdl"), "A234");
}


TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    EXPECT_EQ(soundex.encode("Ab"), "A100");
    EXPECT_EQ(soundex.encode("Ac"), "A200");
    EXPECT_EQ(soundex.encode("Ad"), "A300");
    EXPECT_EQ(soundex.encode("Ax"), "A200");
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
    ASSERT_EQ(soundex.encode("A#"), "A000");
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    std::string encoded = soundex.encode("A");
    ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding,_PadsWithZeroZerosToEnsourceThreeDigits)
{
    std::string encoded = soundex.encode("I");
    ASSERT_EQ(encoded, "I000");
}

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
