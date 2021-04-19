#include "vettore.h"
template<class T>
typename vettore<T>::iterator<T> iterator;

template<class T>
vettore<T>::vettore():cap(1), sze(0), info(new T[cap]){}

template<class T>
vettore<T>::vettore(int n_ele, int val):cap(n_ele), sze(n_ele), info(new T[cap]){
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
vettore<T>::begin(){}
