#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>




class Vector
{
    private:
     int m_size;
     int m_capacity; 
     int* m_arr;

    public:
    Vector();
    Vector(const Vector& cop);
    Vector& operator=(const Vector& rhs);
    Vector(Vector&& tmp);
    Vector& operator=( Vector&& mopt);
    virtual ~Vector(){ delete[]m_arr;
     std::cout<<"default dtor"<<std::endl;}

    
   
   virtual void push_back(int element);
   virtual void push_front(int element);
   virtual int operator[](int number);
   virtual int get_size(){return m_size;}
   virtual void pop();
   virtual int get_capacity(){return m_capacity;}


    friend  Vector operator+(const Vector& c, const Vector& d);
};

#endif // VECTOR_H