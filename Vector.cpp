#include "Vector.h"
#include <iostream>

Vector operator+(const Vector& c, const Vector& d)
{
    Vector m;
    m.m_capacity = c.m_capacity + d.m_capacity;
    for(int i = 0 ; i < c.m_size ; ++i){
        m.push_back(c.m_arr[i]);
    }

    for(int i = 0 ; i < d.m_size ; ++i){
        m.push_back(d.m_arr[i]);
    }

    std::cout << "operator + " << std::endl;

    return m;
}
Vector::Vector()
        : m_size{0}
        , m_capacity{4}
        , m_arr {new int [m_capacity]}
{
     
     std::cout<<"default ctor"<<std::endl;
     
}

Vector::Vector(const Vector& cop)
{
    this->m_size=cop.m_size;
    this->m_capacity= cop.m_capacity;
    m_arr=new int [m_capacity];
    for(int i = 0 ; i<m_size; i++){
        m_arr[i] = cop.m_arr[i];
    }
    std::cout<<"copy ctor"<<std::endl;
}

Vector& Vector::operator=(const Vector& rhs)
{
    if(this==&rhs){
        return *this;
    }
   delete[]m_arr;
   this->m_size = rhs.m_size;
   this->m_capacity = rhs.m_capacity;
   m_arr = new int[m_capacity];
   for(int i = 0 ; i < m_size ; ++i){
       m_arr[i] = rhs.m_arr[i];
   }
   std::cout<<"operator ="<<std::endl;
   return *this;
}
Vector::Vector( Vector&& tmp)
{
    m_size=tmp.m_size;
    m_capacity= tmp.m_capacity;
    m_arr=tmp.m_arr;
    tmp.m_arr = nullptr;
    tmp.m_size = 0;
    tmp.m_capacity = 0;
    std::cout<<"muve ctor"<<std::endl;
}

 Vector& Vector::operator=( Vector&& mopt)
{
    m_size = mopt.m_size;
    m_capacity = mopt.m_capacity;
    delete[] m_arr;
    m_arr = mopt.m_arr;
    mopt.m_arr = nullptr;
    mopt.m_size = 0;
    mopt.m_capacity = 0;
    std::cout<<"Move assignment operator "<<std::endl;
    return *this;


}

void Vector::push_back(int element)
{
    if(m_size >= m_capacity){
        m_capacity *=2;
        int* tmp = new int[ m_capacity ];
        for(int i = 0; i < m_size ; ++i){
         tmp[i] = m_arr[i];
        }
      delete[] m_arr;
      m_arr = tmp;
    }

    m_arr[ m_size ] = element;
    ++m_size;   
}

void Vector::push_front(int element)
{
     if(m_size >= m_capacity){
        m_capacity *=2;
        int* tmp = new int[ m_capacity ];
        for(int i = 0; i < m_size ; ++i){
         tmp[i] = m_arr[i];
        }
      delete[] m_arr;
      m_arr = tmp;

      for(int j = m_size-1; j >= 0 ; --j){
          m_arr[ j+1 ] = m_arr[ j ];
      }
     }
      else
          for(int j = m_size-1; j >=0 ; --j){
          m_arr[ j+1 ] = m_arr[ j ];
          }
      
       m_arr[0] = element;
       ++m_size;

    
}

int  Vector::operator[]( int number)
{
    if ( m_size < number ){
        std::cout << "incorrect input" << std::endl;
        return 0;
    }
    else
    return m_arr[number];
}

void Vector::pop()
{
    --m_size;
}

    
                      