#include <iostream>
#include "vettore.h"

//costruttori
template<class T>
vettore<T>::vettore():cap(1), sze(0), info(new T[cap]){}

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
        delete info;
        info=v.info;
        sze=v.sze;
        cap=v.cap;
    }
    return *this;
}

//iterator
template<class T>
vettore<T>::iterator::iterator(): punt(nullptr), pte(false){}

template<class T>
vettore<T>::iterator::iterator(T& t, bool past):punt(t.info), pte(past) {}

template<class T>
typename vettore<T>::iterator vettore<T>::iterator::operator++(int){
    vettore<T>::iterator it=*this;
    punt++;
    return it;
}

template<class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator++(){
    return ++punt;
}

template<class T>
typename vettore<T>::iterator vettore<T>::iterator::operator--(int){
    vettore<T>::iterator it=*this;
    punt--;
    return it;
}

template<class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator--(){
    return --punt;
}

template<class T>
bool vettore<T>::iterator::operator==(const iterator& it) const{return punt==it.punt;}

template<class T>
bool vettore<T>::iterator::operator!=(const iterator& it) const{return punt!=it.punt;}

//const_iterator
template<class T>
vettore<T>::const_iterator::const_iterator(const iterator& it): punt(it.punt), pte(it.pte) {}

template<class T>
vettore<T>::const_iterator::const_iterator(): punt(nullptr), pte(false){}

template<class T>
vettore<T>::const_iterator::const_iterator(const T& t, bool past): punt(t.info), pte(past) {}

template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator--(int){
    vettore<T>::const_iterator it=*this;
    punt--;
    return it;
}

template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator--(){
    return --punt;
}

template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator++(int){
    vettore<T>::const_iterator it=*this;
    punt++;
    return it;
}

template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator++(){
    return ++punt;
}

template<class T>
bool vettore<T>::const_iterator::operator==(const const_iterator& it) const{return punt==it.punt;}

template<class T>
bool vettore<T>::const_iterator::operator!=(const const_iterator& it) const{return punt!=it.punt;}

//metodi
template<class T>
int vettore<T>::size() const{return sze;}

template<class T>
int vettore<T>::capacity() const{return cap;}

template<class T>
typename vettore<T>::iterator vettore<T>::begin() {return info[0];}

template<class T>
typename vettore<T>::iterator vettore<T>::end(){return info[sze];}

template<class T>
typename vettore<T>::const_iterator vettore<T>::begin() const {return info[0];}

template<class T>
typename vettore<T>::const_iterator vettore<T>::end() const {return info[sze];}

template<class T>
void vettore<T>::push_back(const T& t){
    if(sze==cap){
        cap*=2;
        T* aux = new T[cap];
        for(int i=0;i<sze; i++)
            aux[i]=info[i];
        delete[] info;
        info = aux;
    }
    info[sze]=t;
    sze++;
}

template<class T>
void vettore<T>::pop_back(){
    if(sze==0)
        throw "exception";      //ATTENZIONE! SOSTITUIRE CON ECCEZIONE VERA
    else sze--;
}

template<class T>
void vettore<T>::erase(int i){
    if(0<=i<=sze){
        for(int j=i; j<sze-1; j++)
            info[j]=info[j+1];
        sze--;
    }
    else
        throw "index out of range";
}

template<class T>
void vettore<T>::clear(){
    sze=0;
}

