#ifndef VETTORE_H
#define VETTORE_H

template <class T>
class vettore{
public:
    class iterator;
    class const_iterator;
private:
    friend class const_iterator;
    int cap;
    int sze;
    T* info;
public:
    vettore();
    vettore(int, int =0);
    vettore(const vettore&);
    ~vettore();
    int size() const;
    int capacity() const;

    class iterator{
    private:
        friend class vettore<T>;
        T* punt;
        bool pte;   //Past The End
    public:
        iterator();
        iterator(T*, bool =false);
    };
    class const_iterator{
    private:
        friend class vettore<T>;
        const T* punt;
        bool pte;   //Past The End
    public:
        const_iterator();
        const_iterator(const iterator&);
        const_iterator(const T*, bool =false);
    };

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    void push_back(const T&);
    void pop_back();
    void erase(iterator);
    void erase(iterator, iterator);
};

#endif // VETTORE_H
