#include "vettore.h"

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
int vettore<T>::size() const{return sze;}

template<class T>
int vettore<T>::capacity() const{return cap;}

template<class T>
vettore<T>::iterator::iterator(): punt(nullptr), pte(false){}

template<class T>
vettore<T>::iterator::iterator(T* t, bool past):punt(t->info), pte(past) {}

template<class T>
vettore<T>::const_iterator::const_iterator(const iterator& it): punt(it.punt), pte(it.pte) {}

template<class T>
vettore<T>::const_iterator::const_iterator(): punt(nullptr), pte(false){}

template<class T>
vettore<T>::const_iterator::const_iterator(const T* t, bool past): punt(t->info), pte(past) {}

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
    if(sze>=cap){
        cap*=2;
        T* aux = new T(info);
        delete[] info;
        info(new T(aux));
    }
    info[sze+1]=t;
    ++sze;
}
