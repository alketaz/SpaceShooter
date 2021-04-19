#ifndef VETTORE_H
#define VETTORE_H

template <class T>
class vettore{
private:
    int cap;
    int sze;
    T* info;
public:
    vettore();
    vettore(int, int =0);
    vettore(const vettore&);
    ~vettore();
    class iterator{
    private:
        T* punt;
        bool pte;   //Past The End
    public:
        iterator();
        iterator(T*, bool);
    };
    class const_iterator{
        const T* punt;
        bool pte;   //Past The End
    public:
        const_iterator();
        const_iterator(const T*, bool =false);
    };
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    int size() const;
    int capacity() const;
};

#endif // VETTORE_H
