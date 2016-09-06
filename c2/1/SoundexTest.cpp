#include <gmock/gmock.h>

using namespace testing;


class Soundex
{

private:

    std::string zeroPad(const std::string& word) const
    {
        return word + "000";
    }

public:

    std::string encode(const std::string& word) const
    {
        //return "";
        //return word + "000";
        return zeroPad(word);
    }
};


//class SoundexEncoding: public testing::Test
class SoundexEncoding: public Test
{

public:
    Soundex soundex;

};


//TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Soundex soundex;
    // soundex was move to fixture (i.e. installation)
    // == do ==
    // SoundexTest.cpp:12:7: error: ‘encoded’ does not name a type
    // auto encoded = soundex.encode("A");
    // auto was removed after c++11
    std::string encoded = soundex.encode("A");
    // == check ==
    // SoundexTest.cpp:22:2: error: ‘ASSERT_THAT’ was not declared in this scope
    // ASSERT_THAT(encoded, testing::Eq("A");
    ASSERT_EQ(encoded, "A000");
    /*
    [ RUN      ] SoundexEncoding.RetainsSoleLetterOfOneLetterWord
    /home/vash_hsu/working/TDD/c2/1/SoundexTest.cpp:24: Failure
    Value of: "A"
    Expected: encoded
    Which is: ""
    [  FAILED  ] SoundexEncoding.RetainsSoleLetterOfOneLetterWord (0 ms)
    */
}

//TEST(SoundexEncoding,_PadsWithZeroZerosToEnsourceThreeDigits)
TEST_F(SoundexEncoding,_PadsWithZeroZerosToEnsourceThreeDigits)
{
    //Soundex soundex;
    std::string encoded = soundex.encode("I");
    ASSERT_EQ(encoded, "I000");
}

int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
