#include "pch.h"

#include <gtest/gtest.h>

std::string reverse_words (std::string const &sentence) {
	std::string reversed;
	reversed.reserve (sentence.size ());
	
	auto isWordSep = [] (char c) { return c == ' ' || c == '\t' || c=='.';  };

	std::string word;
	std::for_each (sentence.begin (), sentence.end (), [&word, &reversed, isWordSep] (char c) {
		if (isWordSep (c)) {
			reversed.insert (0, word);
			reversed.insert (reversed.begin (), c);
			word.clear ();
		}
		else {
			word += c;
		}
	});

	if (!word.empty ()) {
		reversed.insert (0, word);
	}

	return reversed;
}

TEST (ReverseWordsTest, Basic) {

	std::string sentense = "Brown fox jumps over a lazy dog.";
	std::string reversed = reverse_words (sentense);
	EXPECT_EQ (reversed, ".dog lazy a over jumps fox Brown");

}

TEST (ReverseWordsTest, NoFinalWordSeparator) {
	std::string sentense = "Brown fox jumps over a lazy dog";
	std::string reversed = reverse_words (sentense);
	EXPECT_EQ (reversed, "dog lazy a over jumps fox Brown");
}