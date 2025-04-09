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

std::string kYourName = "Jay Wang"; // Don't forget to change this!

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
std::unordered_set<std::string> get_applicants(std::string filename) {
  std::ifstream ifs(filename);
  std::string name;
  std::unordered_set<std::string> result;

  /* Check if file can be opened successfully */
  if(!ifs.is_open())
  {
    throw std::runtime_error("Unable to open the file");
  }

  /* Read each name from the file and put them into the unordered set */
  while(std::getline(ifs, name))
  {
    result.insert(name);
  }

  /* close file */
  ifs.close();
  return result;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  
  std::queue<const std::string*> matches;
  
  /* Traverse through the unordered set */
  for(const auto &student: students)
  {
    if((name[0] == student[0]) && (name[name.find(' ') + 1] == student[student.find(' ') + 1]))
    {
      std::cout << student << std::endl;
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
std::string get_match(std::queue<const std::string*>& matches) {
  std::string result;
  /* If the matches are empty, return the designated string. 
   * Return the last element in the queue otherwise.
   */
  if (matches.empty())
  {
    result = "NO MATCHES FOUND.";
  }
  else
  {
    result = *matches.back();
  }
  return result;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
