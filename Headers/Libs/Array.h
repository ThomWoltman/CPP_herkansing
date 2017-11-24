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
    Array(int s):size{s}, elems {new T[s]},used{0}{};

    void push_back(T  elelement){
        elems[used++] = elelement;
    }



    ~Array()
    {
        delete[] elems;
    }

    T& operator[](int index)
    {
        return elems[index];
    }

    void operator=(T temp)
    {
        for(int i=0;i<size;i++)
            elems[i]=temp;
    }

    Array& operator=(const Array& other){
        if(this != &other){
            std::uninitialized_copy(other.elems[0], other.elems[other.size], elems);
        }
    }

    T& operator=(T&& temp){
        elems = temp[0];
        return *this;
    }
};


#endif //CPP_HERKANSING_ARRAY_H
