#ifndef DEEP_PTR_H
#define DEEP_PTR_H
#include<iostream>

template<class T>
class deep_ptr{
private:
    T* info;
public:
    deep_ptr(T* =nullptr);
    deep_ptr(const deep_ptr&);
    ~deep_ptr();
    deep_ptr<T>& operator=(const deep_ptr<T>&);
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    T& operator[](unsigned int);
    const T& operator[](unsigned int) const;
    T* get();
    const T* get() const;
    void reset(T* =new T);
    explicit operator bool() const;
    T* release();
    void swap(deep_ptr&);
};

template<class T>
std::ostream& operator<<(std::ostream& os, const deep_ptr<T>& dp){
    return os<<*dp;
}

#include "deep_ptr.h"

template<class T>
deep_ptr<T>::deep_ptr(T* t): info(t==nullptr ? nullptr : t->clone()){}

template<class T>
deep_ptr<T>::deep_ptr(const deep_ptr<T>& dp): info(dp.info==nullptr ? nullptr : new T(*(dp.info))){}

template<class T>
deep_ptr<T>::~deep_ptr(){delete info;}

template<class T>
deep_ptr<T>& deep_ptr<T>::operator=(const deep_ptr& dp){
    if(this!=&dp){
        delete info;
        info = dp.get()->clone();
    }
    return *this;
}

template<class T>
T& deep_ptr<T>::operator*(){return *info;}

template<class T>
const T& deep_ptr<T>::operator*() const{return *info;}

template<class T>
T* deep_ptr<T>::operator->(){return info;}

template<class T>
const T* deep_ptr<T>::operator->() const{return info;}

template<class T>
T& deep_ptr<T>::operator[](unsigned int i){return info[i];}

template<class T>
const T& deep_ptr<T>::operator[](unsigned int i) const{return info[i];}

template<class T>
T* deep_ptr<T>::get(){return info;}

template<class T>
const T* deep_ptr<T>::get() const{return info;}

template<class T>
void deep_ptr<T>::reset(T* ptr){
    delete info;
    info=ptr;
}

template<class T>
deep_ptr<T>::operator bool() const{return info!=nullptr;}

template<class T>
T* deep_ptr<T>::release(){
    T*aux = new T(info);
    delete info;
    return aux;
}

template<class T>
void deep_ptr<T>::swap(deep_ptr(& dp)){
    T* aux = new T(info);
    info = new T(dp.info);
    dp.info = aux;
}




#endif // DEEP_PTR_H
