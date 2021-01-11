/*==================================
 IMPLEMENTATION FILE FOR COMPOSER.H
 ===================================*/

/*===================================
 DEFAULT CONSTRUCTOR
 The default constructor does nothing.
 Doesn't receive or return anything.
 ====================================*/
#include "Composer.h"
Composer::Composer()
{
}

/*==========================================
 OVERLOADED CONSTRUCTOR
 Receives a string and int which are
 assigned to name and date member variables
============================================*/
Composer::Composer(string name, int date):name(name),date(date){}

/*============================
 DESTRUCTOR
 Does nothing. Doesn't receive
 or return anything.
==============================*/
Composer::~Composer()
{
}

/*===========================
 getName FUNCTION
 This function return the value
 stored inside string member
 variable.
============================*/
string Composer::getName()const
{
    return name;
}

/*===========================
 getDate FUNCTION
 Returns the value stored inside
 date member variable.
============================*/
int Composer::getDate()const
{
    return date;
}

/*===============================
 setName FUNCTION
 Receives a string argument whose
 value is assigned to name member
 variable. Return Nothing
=================================*/
void Composer::setName(string n)
{
    name = n;
}

/*=================================
 setDate FUNCTON
 Receives an integer argument whose
 value is assigned to data member
 variable. Returns Nothing.
===================================*/
void Composer::setDate(int d)
{
    date = d;
}

/*========================================
 OVERLOADING == OPERATOR
 This function receives a Composer object
 passed by constant reference. It checks
 if the data stored in the calling object is
 the same as the data passed as an argument
 and returns true. Otherwise returns false.
==========================================*/
bool Composer::operator==(const Composer& abc)
{
    if (name == abc.name || date == abc.date)
        return true;
    return false;
}

/*================================================
 OVERLOADING < OPERATOR
 Function receives Composer object passed
 by constant reference. It checks if date in
 calling object is less than the argument.
 If yes, returns true otherwise it returns false.
==================================================*/
bool Composer::operator<(const Composer& abc)
{
    if (date < abc.date)
        return true;
    return false;
}

/*==========================================
 OVERLOADING != OPERATOR
 Function receives Composer object passed
 by constant reference. It checks if data in
 calling object and argument is not equal. If
 it is not equal true is returned else false.
=============================================*/
bool Composer::operator!=(const Composer& abc)
{
    if (name != abc.name && date != abc.date)
        return true;
    return false;
}

/*=========================================
 OVERLOADING << OPERATOR
 Recveives an ostream reference object &
 a const Composer object as reference. It
 displays the values stored in the object
 & returns a reference to an ostream
 object.
 ==========================================*/
ostream& operator<<(ostream& os,const Composer& composer)
{
    os << composer.name << " - " << composer.date;
    return os;
}


