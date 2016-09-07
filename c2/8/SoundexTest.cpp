#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;


class SoundexEncoding: public Test
{

public:
    Soundex soundex;

};


TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
    // {'b', "1"}, {'f', "1"}
    // {'c', "2"}, {'g', "2"}
    // {'d', "3"}, {'t', "3"},
    ASSERT_EQ(soundex.encodedDigit('b'), soundex.encodedDigit('f'));
    ASSERT_EQ(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
    ASSERT_EQ(soundex.encodedDigit('d'), soundex.encodedDigit('t'));
    /*
    Soundex.h:32:17: error: ¡¥std::__cxx11::string Soundex::encodedDigit(char) const¡¦ is private
    std::string encodedDigit(char letter) const
    */
    ASSERT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{    
    ASSERT_EQ(soundex.encode("Baeiouhycdl"), "B234");
}

TEST_F(SoundexEncoding, LimitsLenghtToFourCharacters)
{
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
