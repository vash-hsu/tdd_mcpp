#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;


class SoundexEncoding: public Test
{

public:
    Soundex soundex;

};

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    //SoundexTest.cpp:17: Failure
    //Value of: "A100"
    //Expected: soundex.encode("Ab")
    //Which is: "Ab000"
    ASSERT_EQ(soundex.encode("Ab"), "A100");
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
