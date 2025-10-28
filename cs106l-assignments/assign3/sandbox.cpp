/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
void sandbox() {
  // default constructor
  ArmID employee1;
  employee1.display();

  // parameterized constructor
  ArmID employee2("Jay Wang", "Senior Software Engineer", 1000, 20000);
  employee2.promote("Director", 100000);
}