#include "myString.h"

/*
class newString
{
    //Overload the stream insertion and extraction operators.
    
    ; 
    
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
*/

ostream& operator << (ostream& os, const newString& obj)
{
    for(int i = 0; i < obj.strLength - 1; i++)
    {
        os << obj.strPtr[i];
    }
}

istream& operator >> (istream& is, newString& obj)
{
    
}

