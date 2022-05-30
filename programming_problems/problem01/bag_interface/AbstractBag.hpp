/** @file AbstractBag.hpp */
#ifndef ABSTRACT_BAG_
#define ABSTRACT_BAG_

using namespace std;
#include<cstdlib>

template<typename T> 
class AbstractBag
{
    public:
        AbstractBag();

        virtual ~AbstractBag();

        virtual size_t getCurrentSize() const = 0;

        virtual bool isEmpty() const = 0;

        virtual bool add(const T& entry) = 0;

        virtual bool remove(const T& entry) = 0;

        virtual void clear() = 0;

        virtual size_t getFrequencyOf(const T& entry) const = 0;

        virtual bool contains(const T& entry) const = 0;

        static const size_t MAXSIZE = 100;

    private:
        size_t size;
  
        T data[MAXSIZE];
};    


#endif
        
