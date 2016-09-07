#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;


class SoundexEncoding: public Test
{

public:
    Soundex soundex;

};


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
