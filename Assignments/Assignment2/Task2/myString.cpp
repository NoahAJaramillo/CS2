#include "myString.h"


ostream& operator << (ostream& os, const newString& obj)
{
    for(int i = 0; i < obj.strLength - 1; i++)
    {
        os << obj.strPtr[i];
    }
}

istream& operator >> (istream& is, newString& obj)
{
    for(int i = 0; i < obj.strLength - 1; i++)
    {
        is >> obj.strPtr[i];
    }
}

const newString& newString::operator=(const newString& obj)
{
    this->strLength = obj.strLength;
    delete [] strPtr;
    strPtr = new char [strLength];
    for (int i = 0; i < this->strLength - 1; i++)
    {
        strPtr[i] = obj.strPtr[i];
    }
}

const newString& newString::operator+=(const newString& obj)
{
    //TODO: need to fix the + operators due to constructing new string of new size
    int length = this->strLength;
    this->strLength += obj.strLength;
    newString temp(strPtr);
    delete [] strPtr;
    strPtr = new char [strLength];
    for(int i = 0; i < temp.strLength - 1; i++)
    {
        strPtr[i] = temp[i];
    }
    for(int i = length; i < strLength; i++)
    {
        strPtr[i] = obj.strPtr[i];
    }
}

const newString& newString::operator+=(char ch)
{
    //TODO: need to fix the + operators due to constructing new string of new size
    this->strLength += 1;
    newString temp(strPtr);
    delete [] strPtr;
    for(int i = 0; i < strLength - 2; i++)
    {
        strPtr[i] = temp.strPtr[i];
    }
    strPtr[strLength - 1] = ch;
}

newString newString::operator+(const newString& obj)
{
    //TODO: need to fix the + operators due to constructing new string of new size
    newString str = newString();
    str.strLength = strLength + obj.strLength;
    delete [] str.strPtr;
    str.strPtr = new char [str.strLength];
    bool lhs = true;

    for(int i = 0; i < str.strLength - 1; ++i)
    {
        if (lhs)
        {
            if (strPtr[i] == '\0') lhs = false;

            str.strPtr[i] = strPtr[i];
        }
        else
        {
            str.strPtr[i] = obj.strPtr[i - strLength];
        }
    }

    return str;
}

newString newString::operator+(char ch)
{
    newString str = newString(strPtr);
    str.strLength = this->strLength + 1;
    delete [] str.strPtr;
    str.strPtr = new char [str.strLength];
    for(int i = 0; i < str.strLength - 1; i++)
    {
        str.strPtr[i] = strPtr[i];
    }
    str.strPtr[str.strLength - 1] = ch;
    return str;
}

newString::newString(const char * ch)
{
    strLength = 0;
    while(*ch != '\0')
    {
        strLength++;
        ch++;
    }
    strPtr = new char[strLength];
    for(int i = 0; i < strLength - 1; i++)
    {
        strPtr[i] = ch[i];
    }

}

    //constructor; conversion from the char string
newString::newString()
{
    strLength = 0;
    strPtr = new char [1];
    strPtr = nullptr;
}  
    //Default constructor to initialize the string to nullptr
newString::newString(const newString& obj)
{
    delete[] strPtr;
    strPtr = new char [obj.strLength];
    strLength = obj.strLength;
    strPtr = obj.strPtr;
} 
    //Copy constructor
newString::~newString()
{
    delete[] strPtr;
}
    //Destructor

int newString::length()
{
    return strLength;
}
    //Return the length of the string

char& newString::operator[] (int index)
{
    if (index < 0 || index > strLength)
    {
        std::cout << "Index out of bounds!" << endl;
    }

    return strPtr[index];
} 

const char& newString::operator[](int index) const
{
    if(index < 0 || index > strLength)
    {
        std::cout << "Index out of Bounds!" << endl;
    }

    return strPtr[index];
}

//overload the relational operators
bool newString::operator==(const newString &obj) const
{
    if (strLength != obj.strLength)
    {
        return false;
    }

    for (int i = 0; i < strLength - 1; i++)
    {
        if (strPtr[i] != obj.strPtr[i])
        {
            return false;
        }
    }
    return true;
}
bool newString::operator!=(const newString & obj) const
{
    if (strLength != obj.strLength)
    {
        return true;
    }

    for (int i = 0; i < strLength - 1; i++)
    {
        if (strPtr[i] != obj.strPtr[i])
        {
            return true;
        }
    }
    return false;
}

bool newString::operator<=(const newString & obj) const
{
    return (*this == obj) || (this->strLength < obj.strLength);
}
bool newString::operator<(const newString & obj) const
{
    return (this->strLength < obj.strLength);
}
bool newString::operator>=(const newString & obj) const
{
    return (*this == obj) || (this->strLength > obj.strLength);
}
bool newString::operator>(const newString & obj) const
{
    return (this->strLength > obj.strLength);
}

char* newString::strcopy(const char *str2)
{
    int i = 0;
    while(str2[i] != '\0')
    {
        ++strLength;
        strPtr[i] = str2[i];
        ++i;
    }

    return strPtr;
}

char* newString::strcopy(char *str1, const char *str2)
{
    int i = 0;
    while(str2[i] != '\0')
    {
        str1[i] = str2[i];
        ++i;
    }

    return str1;
}

char* newString::strConcat(char *str2)
{
    int i = 0;
    while(str2[i] != '\0')
    {
        ++strLength;
        strPtr[i + strLength - 1] = str2[i];
    }
    return strPtr;
}
char* newString::strConcat(char *&str1, const char *str2)
{
    int i = 0;
    int length = 0;
    while(str1[i] != '\0')
    {
        ++length;
    }
    while(str2[i] != '\0')
    {
        str1[i + length] = str2[i];
    }
    return str1;
}