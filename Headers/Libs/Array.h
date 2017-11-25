//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_ARRAY_H
#define CPP_HERKANSING_ARRAY_H

#include<iostream>
#include<iomanip>
#include <memory>

template<class T>
class Array
{
    T *elems;
    int used;
    int size;
public:
    explicit Array(int s):size{s}, elems {new T[s]},used{0}{};

    Array(Array& other){
        std::uninitialized_copy(other.elems[0], other.elems[other.size], elems);
        size = other.size;
        used = other.used;
    }

    Array(Array&& other) noexcept :
            size{other.size},
            used{other.used},
            elems{other.elems} {
        other.size = 0;
        other.used = 0;
        other.elems = nullptr;
    }

    void push_back(T element){
        if(used < size){
            elems[used++] = element;
        }
        else{
            std::cout << "can't push back on array" << std::endl;
        }
    }

    ~Array()
    {
        delete[] elems;
    }

    T& operator[](int index)
    {
        return elems[index];
    }

    Array& operator=(const Array& other){ // copy assignment operator
        Array temp {other}; // use copy constructor
        *this = std::move(temp); // use move assignment operator
        return *this;
    }

    Array& operator=(Array&& other) noexcept { // move assignment operator
        delete[] elems;

        elems = other.elems;
        used = other.used;
        size = other.size;

        other.elems = nullptr;
        other.used = 0;
        other.size = 0;

        return *this;
    }

    int length() const{
        return size;
    }
};


#endif //CPP_HERKANSING_ARRAY_H
