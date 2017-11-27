//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_STRING_H
#define CPP_HERKANSING_STRING_H

#include <iostream>
#include <cstring>

using namespace std;
class String {
public:
    explicit String(const char* arg)
            : cstring(new char[std::strlen(arg)+1]) // allocate
    {
        std::strcpy(cstring, arg); // populate
    }

    explicit  String() : cstring(nullptr){}

    ~String()
    {
        delete[] cstring;  // deallocate
    }
    String(const String& other) // copy constructor
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }
    String(String&& other) noexcept : cstring(other.cstring)// move constructor
    {
        other.cstring = nullptr;
    }
    String& operator=(const String& other) // copy assignment
    {
        auto* tmp_cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(tmp_cstring, other.cstring);
        delete[] cstring;
        cstring = tmp_cstring;
        return *this;
    }
    String& operator=(String&& other) // move assignment
    {
        if(this!=&other) // prevent self-move
        {
            delete[] cstring;
            cstring = other.cstring;
            other.cstring = nullptr;
        }
        return *this;
    }

    char operator[](int index)
    {
        return cstring[index];
    }

    friend istream& operator>>(istream& strm, String &string) {
        if(strm){
            char temp[50];

            if(strm >> temp){
                string = String{temp};
            }
        }

        return strm;
    }

    friend ostream& operator<<(ostream& strm, String &string) {
        if(strm){
            strm << string.get_string();
        }

        return strm;
    }

    const bool equals(const char* char_array) const;
    const void print();

    char* get_string() const{
        return cstring;
    }

private:
    char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
};


#endif //CPP_HERKANSING_STRING_H
