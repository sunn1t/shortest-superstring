#ifndef TST_STRTEST_H
#define TST_STRTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <algorithms.h>

//using namespace testing;

static std::string test_set1[] = {"aaabb", "bccccc", "ccdd", "dddee", "eee"};
static std::string test_set2[] = {"mmsstQ", "JccdddgZ", "QaajjuuuasdfJ", "ZZZZ", "Zhh"};
static std::string test_set3[] = {"Abc", "Bcd", "Cde"};
static std::string test_set4[] = {"bLLSeiidofeiobdleids", "UdiOOqieJdibLLSeiido"};
static std::string test_set5[] = {"AubSIdle", "GoicRaiYY", "oicRaiYYAubSIdl"};
static std::string test_set6[] = {"cde", "abc", "eab", "fgh", "ghf", "hed"};
static std::string test_set7[] = {"waiwa", "digoe", "socib", "dsoec", "isdie", "cibis"};
static std::string test_set8[] = {"urobsb", "ionnao", "pmequd",
                                  "xxpmtu", "nrmseh", "cbivkc"
                                  "cdcsfx", "xcxkvk", "qbsgcq"};
static std::string test_set9[] = {"gfffdddfafga", "gcedcfcgbdbc",
                                 "bffccbgcfagd", "bcedgfcebdfc",
                                 "cfdffegccdgg", "fccbeefcabff"};
static std::string test_set10[] = {"hnem", "fnhg", "liid", "mfai", "nddg",
                                  "fkig", "almj", "bine", "iajj", "janh"};

TEST(ExactTest, Simple)
{
    EXPECT_EQ(ExactSolution(5, test_set1), "aaabbcccccdddeee");
    EXPECT_EQ(ExactSolution(5, test_set2), "mmsstQaajjuuuasdfJccdddgZZZZhh");
    EXPECT_EQ(ExactSolution(3, test_set3), "CdeBcdAbc");
    EXPECT_EQ(ExactSolution(2, test_set4), "UdiOOqieJdibLLSeiidofeiobdleids");
    EXPECT_EQ(ExactSolution(3, test_set5), "GoicRaiYYAubSIdle");
}

TEST(ApprTest, Simple)
{
    EXPECT_EQ(AlgorithmBJLTY(6, test_set6), "cdeabcfghfhed");
    EXPECT_EQ(AlgorithmBJLTY(6, test_set7), "waiwadigoesocibisdiedsoec");
    EXPECT_EQ(AlgorithmBJLTY(9, test_set8), "urobsbionnaopmequdnrmsehcbivkccdcsfxxpmtuxcxkvkqbsgcqgfffdddfafga");
    EXPECT_EQ(AlgorithmBJLTY(6, test_set9), "gfffdddfafgagcedcfcgbdbcedgfcebdfccbeefcabffccbgcfagdcfdffegccdgg");
    EXPECT_EQ(AlgorithmBJLTY(10, test_set10), "hnemfaiajjbinealmjanhfnhgliidnddgfkig");
}

#endif // TST_STRTEST_H

