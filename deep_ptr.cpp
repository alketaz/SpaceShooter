#include "deep_ptr.h"

template<class T>
deep_ptr<T>::deep_ptr(T* t): info(t==nullptr ? nullptr : new T(t)){}

template<class T>
deep_ptr<T>::deep_ptr(const deep_ptr& dp): info(dp.info==nullptr ? nullptr : new T(dp.info)){}

template<class T>
deep_ptr<T>::~deep_ptr(){delete info;}

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
