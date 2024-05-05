#include "../src/data_structures/tries.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>

using std::vector, std::string;

TEST(TriesTests, InitialValues) {
    tries::trie t;

    vector<string> ordered = t.get_ordered_values();

    EXPECT_EQ(t.size(), 0);
    EXPECT_EQ(ordered.size(), 0);
    EXPECT_FALSE(t.search_value(""));
    EXPECT_FALSE(t.search_value("test"));
    EXPECT_NO_FATAL_FAILURE(t.delete_value(""));
    EXPECT_NO_FATAL_FAILURE(t.delete_value("test"));
}

TEST(TriesTests, SingleValueInsert) {
    tries::trie t;

    t.insert_value("test");
    vector<string> ordered = t.get_ordered_values();
    vector<string> expected { "test" };

    EXPECT_EQ(t.size(), 1);
    EXPECT_EQ(ordered.size(), 1);
    EXPECT_FALSE(t.search_value(""));
    EXPECT_TRUE(t.search_value("test"));
    EXPECT_FALSE(t.search_value("tes"));
    EXPECT_NO_FATAL_FAILURE(t.delete_value(""));

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i));
    }
}

TEST(TriesTests, SingleValueInsertDelete) {
    tries::trie t;

    t.insert_value("test");
    t.delete_value("test");
    vector<string> ordered = t.get_ordered_values();

    EXPECT_EQ(t.size(), 0);
    EXPECT_EQ(ordered.size(), 0);
    EXPECT_FALSE(t.search_value(""));
    EXPECT_FALSE(t.search_value("test"));
    EXPECT_NO_FATAL_FAILURE(t.delete_value(""));
    EXPECT_NO_FATAL_FAILURE(t.delete_value("test"));
}

TEST(TriesTests, MultiValueInsert) {
    tries::trie t;

    t.insert_value("words");
    t.insert_value("woods");
    t.insert_value("wood");
    t.insert_value("table");
    t.insert_value("tracks");
    vector<string> ordered = t.get_ordered_values();
    vector<string> expected { "table", "tracks", "wood", "woods", "words" };

    EXPECT_EQ(t.size(), expected.size());
    EXPECT_EQ(ordered.size(), expected.size());
    EXPECT_FALSE(t.search_value(""));
    EXPECT_TRUE(t.search_value("wood"));
    EXPECT_TRUE(t.search_value("woods"));
    EXPECT_TRUE(t.search_value("words"));
    EXPECT_FALSE(t.search_value("word"));
    EXPECT_NO_FATAL_FAILURE(t.delete_value(""));

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i));
    }
}

TEST(TriesTests, MultiValueInsertDelete) {
    tries::trie t;

    t.insert_value("words");
    t.insert_value("woods");
    t.insert_value("wood");
    t.delete_value("wood");
    t.insert_value("table");
    t.insert_value("tracks");
    t.delete_value("table");
    vector<string> ordered = t.get_ordered_values();
    vector<string> expected { "tracks", "woods", "words" };

    EXPECT_EQ(t.size(), expected.size());
    EXPECT_EQ(ordered.size(), expected.size());
    EXPECT_FALSE(t.search_value(""));
    EXPECT_TRUE(t.search_value("woods"));
    EXPECT_TRUE(t.search_value("words"));
    EXPECT_TRUE(t.search_value("tracks"));
    EXPECT_FALSE(t.search_value("table"));
    EXPECT_FALSE(t.search_value("wood"));
    EXPECT_NO_FATAL_FAILURE(t.delete_value(""));

    for (int i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected.at(i), ordered.at(i));
    }
}
