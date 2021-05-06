#include "deep_ptr.h"

template<class T>
deep_ptr<T>::deep_ptr(T* t): info(t==nullptr ? nullptr : new T(t)){}

template<class T>
deep_ptr<T>::deep_ptr(const deep_ptr& dp): info(dp.info==nullptr ? nullptr : new T(dp.info)){}

template<class T>
deep_ptr<T>::~deep_ptr(){delete info;}

template<class T>
deep_ptr<T>& deep_ptr<T>::operator=(const deep_ptr& dp){
    if(this!=&dp){
        delete info;
        info = new T(dp.info);
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
