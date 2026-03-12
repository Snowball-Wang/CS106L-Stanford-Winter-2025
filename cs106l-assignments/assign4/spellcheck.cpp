#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

/*
 * reference:
 * 1. https://github.com/NoughtQ-Selfstudy/CS106L-assignments/blob/main/assign4/spellcheck.cpp
 */

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(const std::string& source) {
  /* Step 1. Identify all iterators to space characters */
  auto spaces = find_all(source.begin(), source.end(), isspace);
  /* Step 2. Generate tokens between consecutive space characters */
  Corpus corpus{};
  /* Step 2.1 Make sure we have tokens from source */
  if (spaces.size() <= 1) {
    std::cout << "Warning: no tokens taken from source" << std::endl;
    return corpus;
  }
  /* Step 2.2 The two input variables in transform have to be equally sized */
  std::transform(spaces.begin(), spaces.end() - 1,
                 spaces.begin() + 1,
                 std::inserter(corpus, corpus.end()),
                 [&source](auto it1, auto it2) -> Token {
                    return Token {source, it1, it2};
                 });
  /* Step 3. Get rid of empty tokens */
  auto is_empty_token = [](const auto& token) { return token.content.empty(); };
  std::erase_if(corpus, is_empty_token);
  return corpus;
}

std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto view = source |
    /* Step 1. Skip words that are already correctly spelled */
    rv::filter([&dictionary](Token t) { return !dictionary.contains(t.content);} ) |
    /* Step 2. Find one-edit-away words in the dictionary using Damerau-Levenshtein */
    rv::transform([&dictionary](Token t) -> Mispelling {
      /* Go through dictionary and find suggestions for each misspelled word */
      auto suggestion = dictionary | rv::filter([&t](std::string w) {
        return (levenshtein(w, t.content) == 1);
      });
      std::set<std::string> suggestions(suggestion.begin(), suggestion.end());
      return Mispelling {t, suggestions};
    }) |
    /* Step 3. Drop misspellings with no suggestions */
    rv::filter([](Mispelling var) { return !(var.suggestions.empty()); });

  std::set<Mispelling> results(view.begin(), view.end());
  return results;
};

/* Helper methods */

#include "utils.cpp"