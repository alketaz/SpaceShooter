#ifndef DEEP_PTR_H
#define DEEP_PTR_H

template<class T>
class deep_ptr{
private:
    T* info;
public:
    deep_ptr(T* =nullptr);
    deep_ptr(const deep_ptr&);
    ~deep_ptr();
    deep_ptr& operator=(const deep_ptr&);
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    T& operator[](unsigned int);
    T* get();
    void reset();
    operator bool() const;
};

#endif // DEEP_PTR_H
