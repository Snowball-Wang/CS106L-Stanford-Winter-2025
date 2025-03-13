/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

std::string kYourName = "Masky White"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename)
{
  // STUDENT TODO: Implement this function.

  std::set<std::string> applicants;

  std::ifstream file(filename);
  std::string line;

  while (std::getline(file, line))
  {
    applicants.insert(line);
  }

  file.close();
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string *> find_matches(std::string name, std::set<std::string> &students)
{
  // STUDENT TODO: Implement this function.
  std::queue<const std::string *> matches;

  // Helper function to get initials from a name
  auto get_initials = [](const std::string &full_name) -> std::string {
    std::string initials;
    bool new_word = true;

    for (char ch : full_name) {
      if (new_word && std::isalpha(ch)) {
        initials += std::toupper(ch);
        new_word = false;
      }
      else if (ch == ' ') {
        new_word = true;
      }
    }
    return initials;
  };

  std::string target_initials = get_initials(name);

  // Find all names with matching initials
  for (const auto& student : students) {
    if ( student != name && target_initials == get_initials(student)) {
      matches.push(&student);
    }
  }

  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string *> &matches)
{
  // STUDENT TODO: Implement this function.

  // If no matches are found, return an error message
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }

  // If there is only one match, return it
  size_t queue_size = matches.size();
  if (queue_size == 1) {
    return *matches.front();
  }

  // Generate a random position in the queue
  size_t target_pos = rand() % queue_size;

  // Move through the queue until we reach the target position  
  for (size_t i = 0; i < target_pos; i++) {
    matches.push(matches.front());
    matches.pop();
  }

  return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
