#include <iostream>
#include "Vector.h"

Vector foo( Vector c);

int main()
{
   
Vector d;
 d.push_back(7);
 d.push_back(45);
 d.push_back(8);
 d.push_back(14);
 d.push_front(5);
 d.push_front(2);
 d.push_front(3);
 d.push_front(1);
 d.pop();
 d.push_back(3);

Vector c;
c.push_front(4);
c.push_front(3);
c.push_front(6);

Vector p =c;
c=d;
Vector k(foo(d));

Vector a;
a=foo(d);
Vector f;
f=p+c;

std::cout <<"d elements "<<std::endl;
for(int i = 0; i < d.get_size() ; ++i){
        std::cout<<d[i]<<std::endl;
}

std::cout <<"c elements "<<std::endl;
for(int i = 0; i < c.get_size() ; ++i){
        std::cout<<c[i]<<std::endl;
}

std::cout <<"k elements "<<std::endl;
for(int i = 0; i < k.get_size() ; ++i){
        std::cout<<k[i]<<std::endl;
}

std::cout <<"p elements "<<std::endl;
for(int i = 0; i < p.get_size() ; ++i){
        std::cout<<p[i]<<std::endl;
}

std::cout <<"a elements "<<std::endl;
for(int i = 0; i < a.get_size() ; ++i){
        std::cout<<a[i]<<std::endl;
}

std::cout <<"f elements "<<std::endl;
for(int i = 0; i < f.get_size() ; ++i){
        std::cout<<f[i]<<std::endl;
}


}

Vector foo( Vector c)
{
        Vector tmp;
        
        return c;
}