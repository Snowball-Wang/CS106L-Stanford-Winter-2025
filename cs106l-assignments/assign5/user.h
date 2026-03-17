/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  /* Overload << operator */
  friend std::ostream& operator<<(std::ostream& os, const User& user);
  /* User-defined destructor */
  ~User();
  /* User-defined copy constructor */
  User(const User& user);
  /* User-defined copy assignment operator */
  User& operator=(const User& user);
  /* Prevent the User class from being move constructed/assigned */
  User(const User&& user) = delete;
  User& operator=(User&& user) = delete;
  /* Overload += operator */
  User& operator+=(User& other);
  /* Overload < operator */
  bool operator<(const User& other) const;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};