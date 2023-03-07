
//Header file myString.h

#ifndef H_myString
#define H_myString

#include <iostream>
using namespace std; 

class newString
{
    //Overload the stream insertion and extraction operators.
    friend ostream& operator << (ostream&, const newString&);
    friend istream& operator >> (istream&, newString&); 
    
public:
    const newString& operator=(const newString&); 
    //overload the assignment operator
    
    //string concatenation
    const newString& operator+=(const newString&);
    //   const newString& operator+=(char *str);
    const newString& operator+=(char ch);
    
    newString operator+(const newString&);
    //    newString operator+(char *str);
    newString operator+(char ch);
    
    newString(const char *); 
    //constructor; conversion from the char string
    newString();  
    //Default constructor to initialize the string to nullptr
    newString(const newString&); 
    //Copy constructor
    ~newString(); 
    //Destructor
    
    int length();
    //Return the length of the string
    
    char &operator[] (int);  
    const char &operator[](int) const;
    
    //overload the relational operators
    bool operator==(const newString&) const;
    bool operator!=(const newString&) const;
    bool operator<=(const newString&) const;
    bool operator<(const newString&) const;
    bool operator>=(const newString&) const;
    bool operator>(const newString&) const;
    
private:
    char* strcopy(const char *str2);
    char* strcopy(char * str1, const char *str2);
    
    char* strConcat(char *str2);
    char* strConcat(char * &str1, const char *str2);
    
    char *strPtr;   //pointer to the char array 
    //that holds the string
    int strLength;  //variable to store the length 
    //of the string
};

#endif 
