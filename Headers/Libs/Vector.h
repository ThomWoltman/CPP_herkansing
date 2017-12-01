//
// Created by administrator on 23-11-17.
//

#ifndef CPP_HERKANSING_ARRAY_H
#define CPP_HERKANSING_ARRAY_H

#include<iostream>
#include<iomanip>
#include <memory>

template<class T>
class Vector
{
    T *elems;
    int used;
    int size;
public:
    explicit Vector():size{8}, elems {new T[8]},used{0}{};

    explicit Vector(int s):size{s}, elems{new T[s]}, used{0}{};

    Vector(const Vector& other){
        elems = new T[other.size];

        for(int i = 0; i < other.used; i++){
            elems[i] = other.elems[i];
        }

        size = other.size;
        used = other.used;
    }

    Vector(Vector&& other) noexcept :
            size{other.size},
            used{other.used},
            elems{other.elems} {
        other.size = 0;
        other.used = 0;
        other.elems = nullptr;
    }

    void push_back(const T& element){
        if(used < size){
            elems[used++] = element;
        }
        else{
            Vector temp{size*2};
            for(int i = 0; i < used; i++){
                temp.push_back(elems[i]);
            }
            temp.push_back(element);
            *this = std::move(temp);
        }
    }

    ~Vector()
    {
        delete[] elems;
    }

    T& operator[](int index) const
    {
        return elems[index];
    }

    Vector& operator=(const Vector& other){ // copy assignment operator
        Vector temp {other}; // use copy constructor
        *this = std::move(temp); // use move assignment operator
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept { // move assignment operator
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
        return used;
    }

    void clear() {
        Vector temp;
        *this = std::move(temp);
    };
};


#endif //CPP_HERKANSING_ARRAY_H
