#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

 /**
  * Overloads << operator to print User object.
  * @param os ofstream object.
  * @param user User object.
  */
std::ostream&
operator<<(std::ostream& os, const User& user)
{
  os << "User(name=" << user.get_name() << ", ";
  os << "friends=[";
  size_t size = user.size();
  for (size_t i = 0; i < size; ++i) {
    if (i < size - 1)
      os << user._friends[i] << ", ";
    else
      os << user._friends[i];
  }
  os << "])";
  return os;
}

/* User-defined destructor */
User::~User()
{
  delete [] _friends;
  _friends = nullptr;
}

/* User-defined copy constructor */
User::User(const User& user)
: _name(user._name), _friends(new std::string[user._capacity]), _size(user._size), _capacity(user._capacity)
{
  if (&user != this) {
    for (size_t i = 0; i < user._size; ++i)
      _friends[i] = user._friends[i];
  }
}

/* User-defined copy assignment operator */
User& User::operator=(const User& user)
{
  if (&user != this) {
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i)
      newFriends[i] = user._friends[i];
    delete [] _friends;
    _friends = newFriends;
  }
  return *this;
}

/* Overload += operator */
User& User::operator+=(User& other)
{
  if (&other != this) {
    this->add_friend(other.get_name());
    other.add_friend(this->get_name());
  }
  return *this;
}

/* Overload < operator */
bool User::operator<(const User& other) const
{
  if (this->_name < other._name)
    return true;
  else
    return false;
}