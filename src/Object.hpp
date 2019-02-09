/**
 * 
 * A dynamic typing class for C++ written by Eyad-Mohammed-Osama:
 * https://github.com/Eyad-Mohammed-Osama/CPP-Dynamic-Typing
 * 
 * File:    Object.hpp
 * This file contains prototypes of methods being used in the implementation.
 * 
 * */

#include <iostream>     // needed to overload the << operator
#include <string>       // added to ease up your life

#ifndef _OBJECT_H_
#define _OBJECT_H_      // it's necessary to prevent this header from being included
                        // twice , otherwise errors may occur

namespace DynamicTyping {   // let's encapsulate everything in a nice namespace
    enum class Type {       // used to determine the internal type of the variable
        Char = 0,
        Bool = 1,
        Int16 = 2,
        UInt16 = 3,
        Int32 = 4,
        UInt32 = 5,
        Int64 = 6,
        UInt64 = 7,
        Float = 8,
        Double = 9,
        String = 10,
        Object = 11,
        Other = 12,
        NoType = 13
    };

    class Object {
        public:
        void *value;    // holds the value
        Type type;      // holds the type

        // Constructors for different primitive types
        Object();
        Object(char);                       // 8 bit ASCII character
        Object(bool);                       
        Object(short int);                  // 16 bit signed integer
        Object(unsigned short int);         // 16 bit unsigned integer
        Object(int);                        // 32 bit signed integer
        Object(unsigned int);               // 32 bit unsigned integer
        Object(long long int);              // 64 bit signed integer
        Object(unsigned long long int);     // 64 bit unsigned integer
        Object(float);                      // 32 bit floating point
        Object(double);                     // 64 bit floating point
        Object(std::string);                
        Object(const Object&);              // Copy constructor

        //  in case none of the above types has been assigned  
        //  this will be used instead
        template<typename T> 
        Object(const T &variable) {
            this->value = new T(variable);
            this->type = Type::Other;
        }

        friend std::ostream &operator<<(std::ostream &os, const Object &variable) {
            if (variable.type == Type::Char) {
                os << *((char*)variable.value);
            }
            else if (variable.type == Type::Bool) {
                os << *((bool*)variable.value);
            }
            else if (variable.type == Type::Int16) {
                os << *((short int*)variable.value);
            }
            else if (variable.type == Type::UInt16) {
                os << *((unsigned short int*)variable.value);
            }
            else if (variable.type == Type::Int32) {
                os << *((int*)variable.value);
            }
            else if (variable.type == Type::UInt32) {
                os << *((unsigned int*)variable.value);
            }
            else if (variable.type == Type::Int64) {
                os << *((long long int*)variable.value);
            }
            else if (variable.type == Type::UInt64) {
                os << *((unsigned long long int*)variable.value);
            }
            else if (variable.type == Type::Float) {
                os << *((float*)variable.value);
            }
            else if (variable.type == Type::Double) {
                os << *((double*)variable.value);
            }
            else if (variable.type == Type::String) {
                os << *((std::string*)variable.value);
            }
            else {
                os << "Object at memory address <" << (variable.value) << ">";
            }
            return os;
        }
        
        //  assignment operators , used for copy constructor and assignment

        Object operator=(const Object&);
        Object operator=(const char&);
        Object operator=(const bool&);
        Object operator=(const short int&);
        Object operator=(const unsigned short int&);
        Object operator=(const int&);
        Object operator=(const unsigned int&);
        Object operator=(const long long int&);
        Object operator=(const unsigned long long int&);
        Object operator=(const float&);
        Object operator=(const double&);
        Object operator=(const std::string&);

        //  in case none of the above types has been assigned
        //  this will be used instead
        template<typename T> 
        Object operator=(const T &variable) {
            this->value = new T(variable);
            this->type = Type::Other;
            return *this;
        }

        bool operator==(const Object&);     // check whether two variables point at the same instance or not
        bool operator!=(const Object&);     // inverse of the above
    };  // end of the class
}       // end of the namespace

#endif