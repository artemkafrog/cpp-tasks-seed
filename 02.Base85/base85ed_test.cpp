#include <gtest/gtest.h>
#include <vector>
#include <cstdint>
#include <string>
#include <cstdlib>

#include "base85ed.h"

static std::vector<uint8_t> str2vec(const std::string& s)
{
    return std::vector<uint8_t>(s.begin(), s.end());
}

// ================= SHORT CASES =================
const std::vector<std::pair<const char *, const char * >> short_cases =
{
    { "",     ""     },
    { "F#",   "1"    },
    { "F){",  "12"   },
    { "F)}j", "123"  },
    { "F)}kW","1234" }
};

TEST(Base85ShortsEncode, TrivialShortEncodes)
{
    for (const auto &p : short_cases)
    {
        EXPECT_EQ(base85::encode(str2vec(p.second)), str2vec(p.first));
    }
}

TEST(Base85ShortsDecode, TrivialShortDecodes)
{
    for (const auto &p : short_cases)
    {
        EXPECT_EQ(base85::decode(str2vec(p.first)), str2vec(p.second));
    }
}

// ================= ROUND TRIP =================
TEST(Base85RoundTrip, RandomData)
{
    for (size_t len = 0; len < 512; ++len)
    {
        std::vector<uint8_t> data(len);
        for (size_t i = 0; i < len; ++i)
            data[i] = rand() % 256;

        auto encoded = base85::encode(data);
        auto decoded = base85::decode(encoded);

        EXPECT_EQ(decoded, data);
    }
}

// ================= FIXED LENGTHS =================
TEST(Base85VariousLengths, EdgeCases)
{
    std::vector<size_t> sizes = {0,1,2,3,4,5,10,100,1023};

    for (auto len : sizes)
    {
        std::vector<uint8_t> data(len, 'A');

        auto encoded = base85::encode(data);
        auto decoded = base85::decode(encoded);

        EXPECT_EQ(decoded, data);
    }
}

// ================= STRINGS =================
TEST(Base85Strings, HumanReadable)
{
    std::vector<std::string> cases = {
        "",
        "hello",
        "Base85 encoding test",
        "1234567890",
        std::string(200, 'x')
    };

    for (const auto& s : cases)
    {
        auto v = str2vec(s);

        auto encoded = base85::encode(v);
        auto decoded = base85::decode(encoded);

        EXPECT_EQ(decoded, v);
    }
}

// ================= INVALID =================
TEST(Base85Decode, InvalidInput)
{
    std::vector<uint8_t> bad = {'@', '@', '@', (uint8_t)255};

    EXPECT_THROW(base85::decode(bad), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}