#ifndef VETTORE_H
#define VETTORE_H
#include "model/deep_ptr.h"
#include <iostream>
#include "enemy.h"

template <class T>
class vettore{
private:
    int cap;
    int sze;
    T* info;
public:
    vettore();
    vettore(int, T);
    vettore(const vettore&);
    ~vettore();

    vettore<T>& operator=(const vettore<T>&);

    class iterator{
    private:
        T* punt;
    public:
        iterator();
        iterator(T*);
        iterator operator++(int);
        iterator& operator++();
        iterator operator--(int);
        iterator& operator--();
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        T& operator*() const;
        T* operator->() const;
    };
    class const_iterator{
    private:
        iterator ite;
    public:
        const_iterator();
        const_iterator(const iterator&);
        const_iterator(T*);
        const_iterator operator++(int);
        const_iterator& operator++();
        const_iterator operator--(int);
        const_iterator& operator--();
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
        const T& operator*() const;
        const T* operator->() const;
    };


    int size() const;
    int capacity() const;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;
    void push_back(const T&);
    void pop_back();
    void erase(int);
    void erase(iterator, iterator);
    void clear();
};

template<class T>
std::ostream& operator<<(std::ostream& os, const vettore<T>& v){
    for(typename vettore<T>::const_iterator it = v.begin(); it++; it!=v.end())
        os<<*it<<" ";
    return os;
}

#include "model/vettore.h"

template<class T>
vettore<T>::vettore():cap(1), sze(0), info(new T[1]){}

template<class T>
vettore<T>::vettore(int n_ele, T val):cap(n_ele), sze(n_ele), info(new T[cap]){
    for(int i=0; i<cap; i++)
        info[i]=val;
}

template<class T>
vettore<T>::vettore(const vettore& v): cap(v.cap), sze(v.sze), info(new T[cap]){
    for(int i=0; i<sze; i++)
        info[i]=v.info[i];
}

template<class T>
vettore<T>::~vettore<T>(){delete[] info;}

template<class T>
vettore<T>& vettore<T>::operator=(const vettore<T>& v){
    if(this!=&v){
        delete[] info;
        sze=v.sze;
        cap=v.cap;
        info = new T[cap];
        for(int i=0; i<sze; i++)
            info[i]=v.info[i];
    }
    return *this;
}

template<class T>
vettore<T>::iterator::iterator(): punt(nullptr){}

template<class T>
vettore<T>::iterator::iterator(T* t):punt(t){}

template<class T>
typename vettore<T>::iterator vettore<T>::iterator::operator++(int){
    vettore<T>::iterator it = *this;
    punt++;
    return it;
}

template<class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator++(){
    ++punt;
    return *this;
}

template<class T>
typename vettore<T>::iterator vettore<T>::iterator::operator--(int){

}

template<class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator--(){
    --punt;
    return *this;
}

template<class T>
bool vettore<T>::iterator::operator==(const iterator& it) const{return punt==it.punt;}

template<class T>
bool vettore<T>::iterator::operator!=(const iterator& it) const{return punt!=it.punt;}

template<class T>
T& vettore<T>::iterator::operator*() const{return *punt;}

template<class T>
T* vettore<T>::iterator::operator->() const{return punt;}

template<class T>
vettore<T>::const_iterator::const_iterator(const iterator& it): ite(it){}

template<class T>
vettore<T>::const_iterator::const_iterator(): ite(nullptr, false){}

template<class T>
vettore<T>::const_iterator::const_iterator(T* t): ite(t){}

template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator--(int){
    vettore<T>::const_iterator it=*this;
    ite--;
    return it;
}

template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator--(){
    return --ite;
}

template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator++(int){
    vettore<T>::const_iterator it=*this;
    ite++;
    return it;
}

template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator++(){
    return ++ite;
}

template<class T>
bool vettore<T>::const_iterator::operator==(const const_iterator& it) const{return ite==it.ite;}

template<class T>
bool vettore<T>::const_iterator::operator!=(const const_iterator& it) const{return ite!=it.ite;}

template<class T>
const T& vettore<T>::const_iterator::operator*() const{return ite.operator*();}

template<class T>
const T* vettore<T>::const_iterator::operator->() const{return ite.operator->();}

template<class T>
int vettore<T>::size() const{return sze;}

template<class T>
int vettore<T>::capacity() const{return cap;}

template<class T>
typename vettore<T>::iterator vettore<T>::begin() {
    return info;
}

template<class T>
typename vettore<T>::iterator vettore<T>::end() {return info+sze;}

template<class T>
typename vettore<T>::const_iterator vettore<T>::begin() const {
    return info;
}

template<class T>
typename vettore<T>::const_iterator vettore<T>::end() const {return info+sze;}

template<class T>
T& vettore<T>::operator[](unsigned int i){return info[i];}

template<class T>
const T& vettore<T>::operator[](unsigned int i) const{return info[i];}

template<class T>
void vettore<T>::push_back(const T& t){
    if(sze==cap){
        cap*=2;
        T* aux = new T[sze];
        for(int i=0;i<sze; i++)
            aux[i]= info[i];
        delete[] info;
        info = new T[cap];
        for(int i=0;i<sze; i++)
            info[i]=aux[i];
    }
    info[sze] = t;
    sze++;
}

template<class T>
void vettore<T>::pop_back(){
    if(sze>0){
        sze--;
        T* aux = new T[sze];
        for(int i=0;i<sze; i++)
            aux[i]= info[i];
        delete[] info;
        info = new T[cap];
        for(int i=0;i<sze; i++)
            info[i]=aux[i];
    }
}

template<class T>
void vettore<T>::erase(int i){
    if(i==sze-1)
        pop_back();
    else if(0<=i && i<sze-1){
        for(int j=i; j<sze-1; j++)
            info[j]=info[j+1];
        pop_back();
    }
    else
        throw "index out of range";
}

template<class T>
void vettore<T>::clear(){
    sze=0;
}



#endif // VETTORE_H
