#include <gtest/gtest.h>
#include "StringUtils.h"
//returns the string in between the given start and end, 0 is first entry
//negatives begin at the end of string
TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(StringUtils::Slice("hello", 0, 5), "hello");
    EXPECT_EQ(StringUtils::Slice("hello", 1, 4), "ell");
    EXPECT_EQ(StringUtils::Slice("hello", -2, 0), "lo");
    EXPECT_EQ(StringUtils::Slice("hello", -4, -1), "ell");
    EXPECT_EQ(StringUtils::Slice("hello", 2, 0), "llo");
    EXPECT_EQ(StringUtils::Slice("hello", 10, 0), "");
}
//returns string with proper capitalization
TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(StringUtils::Capitalize(""),std::string(""));
    EXPECT_EQ(StringUtils::Capitalize("hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Capitalize(" hello world"),std::string(" hello world"));
    EXPECT_EQ(StringUtils::Capitalize("hello world"),std::string("Hello world"));
    EXPECT_EQ(StringUtils::Capitalize("HELLO WORLD"),std::string("Hello world"));
}
// all lowercase input sould result in uppercase output
TEST(StringUtilsTest, Upper){
    EXPECT_EQ(StringUtils::Upper(""), "h");
    EXPECT_EQ(StringUtils::Upper("hello"), "HELLO");
    EXPECT_EQ(StringUtils::Upper("Hello World!"), "HELLO WORLD!");
    EXPECT_EQ(StringUtils::Upper("123abc"), "123ABC");
}
// all uppercase input sould result in lowercase output
TEST(StringUtilsTest, Lower){
    EXPECT_EQ(StringUtils::Lower(""), "h");
    EXPECT_EQ(StringUtils::Lower("HELLO"), "hello");
    EXPECT_EQ(StringUtils::Lower("Hello World!"), "hello world!");
    EXPECT_EQ(StringUtils::Lower("123ABC"), "123abc");
}
//strip space from the left of string
TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(StringUtils::LStrip("Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip(" Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip("Hello "),std::string("Hello "));
    EXPECT_EQ(StringUtils::LStrip("   Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::LStrip(" \r \t \nHello"),std::string("Hello"));
}
//strip from right of string
TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(StringUtils::RStrip("      "),std::string(""));
    EXPECT_EQ(StringUtils::RStrip(""),std::string(""));
    EXPECT_EQ(StringUtils::RStrip("Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello "),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip(" Hello"),std::string(" Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello   "),std::string("Hello"));
    EXPECT_EQ(StringUtils::RStrip("Hello \r \t \n"),std::string("Hello"));
}
//strip both sides of string
TEST(StringUtilsTest, Strip){
    EXPECT_EQ(StringUtils::Strip(" Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("Hello "),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("   Hello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip(" \r \t \nHello"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("      "),std::string(""));
    EXPECT_EQ(StringUtils::Strip(""),std::string(""));
    EXPECT_EQ(StringUtils::Strip("Hello   "),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip("Hello \r \t \n"),std::string("Hello"));
    EXPECT_EQ(StringUtils::Strip(" \r \t \nHello \r \t \n"),std::string("Hello"));
}
//center string at a set length, can specify fill character
TEST(StringUtilsTest, Center){
    EXPECT_EQ(StringUtils::Center("hi", 6), "  hi  ");
    EXPECT_EQ(StringUtils::Center("hi", 5), " hi  ");
    EXPECT_EQ(StringUtils::Center("hi", 2), "hi");
    EXPECT_EQ(StringUtils::Center("hi", 6, '*'), "**hi**");
}
//adjust string to left of given length, can specify fill character
TEST(StringUtilsTest, LJust){
    EXPECT_EQ(StringUtils::LJust("hi", 5), "hi   ");
    EXPECT_EQ(StringUtils::LJust("hi", 5, '*'), "hi***");
    EXPECT_EQ(StringUtils::LJust("hello", 3), "hello");
}
//same but right
TEST(StringUtilsTest, RJust){
    EXPECT_EQ(StringUtils::RJust("hi", 5), "   hi");
    EXPECT_EQ(StringUtils::RJust("hi", 5, '*'), "***hi");
    EXPECT_EQ(StringUtils::RJust("hello", 3), "hello");
}
//first input given be replaced by second input given in string
TEST(StringUtilsTest, Replace){
    EXPECT_EQ(StringUtils::Replace("hello world", "world", "there"), "hello there");
    EXPECT_EQ(StringUtils::Replace("aaaa", "a", "b"), "bbbb");
    EXPECT_EQ(StringUtils::Replace("hello", "x", "y"), "hello");
    EXPECT_EQ(StringUtils::Replace("ababab", "ab", "cd"), "cdcdcd");
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
