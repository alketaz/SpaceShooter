#ifndef VETTORE_H
#define VETTORE_H
#include "deep_ptr.h"

template <class T>
class vettore{
public:
    class iterator;
    class const_iterator;
private:
    int cap;
    int sze;
    T info;
public:
    vettore();
    vettore(int, int =0);
    vettore(const vettore&);
    ~vettore();

    class iterator{
    private:
        T* punt;
        bool pte;   //Past The End
    public:
        iterator();
        iterator(T&, bool =false);
        iterator operator++(int);
        iterator& operator++();
        iterator operator--(int);
        iterator& operator--();
        bool operator==(const iterator&) const; //missing
        bool operator!=(const iterator&) const; //missing
    };
    class const_iterator{
    private:
        friend class vettore<T>;
        const T* punt;
        bool pte;   //Past The End
    public:
        const_iterator();
        const_iterator(const iterator&);
        const_iterator(const T&, bool =false);
        const_iterator operator++(int);
        const_iterator& operator++();
        const_iterator operator--(int);
        const_iterator& operator--();
        bool operator==(const const_iterator&) const; //missing
        bool operator!=(const const_iterator&) const; //missing
    };


    int size() const;
    int capacity() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    void push_back(const T&);
    void pop_back();
    void erase(int);
    void erase(iterator, iterator);
    void clear();
};

#endif // VETTORE_H
