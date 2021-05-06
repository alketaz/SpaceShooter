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
    deep_ptr<T>& operator=(const deep_ptr&);
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

#endif // DEEP_PTR_H
