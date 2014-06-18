#ifndef MALIST_H

#define MALIST_H

#include <stdio.h>

template<class T>


class maList{

    T* array;
    int _size;


public:
    int size(){return _size;}


    maList(){
        _size = 0;
        array =  nullptr;
    }


    maList(const maList& source){
        if(this != &source){
            _size = source._size;
            if(source.array != nullptr)
            {
                array = new T[_size];
                for(int i=0;i<_size;i++)
                    array[i] = source.array[i];
            }

        }


    }


    T& get(int idx){

        if(idx >= _size || idx < 0)

            return array[0];


        return array[idx];

    }


    T& operator [](int i){

        return get(i);

    }


    bool operator ==(T source){

        if(source._size != this->_size)

            return false;


        if(_size == 0)

            return true;


        for(int i=0;i<_size;i++)

        {

            if(array[i] != source.array[i])

                return false;

        }


        return true;

    }


    bool exists(T source){

        if(array == nullptr)

            return false;


        for(int i=0;i<_size;i++){

            if(array[i] == source){

                return true;

            }

        }


        return false;

    }


    void removeObj (T source){

        if(array == nullptr)

            return;


        int idx = -1;


        for(int i=0;i<_size;i++){

            if(array[i] == source){

                idx = i;

                break;

            }

        }


        if(idx > 0)

            remove(idx);

    }


    void remove (int idx){

        if(array == nullptr || idx<0 || idx>=_size)

            return;


        T* tmp = new T[_size-1];

        int j=0;

        for(int i=0;i<_size;i++)

        {

            if(i == idx){

                continue;

            }

            tmp[j] = array[i];

            j++;

        }


        delete[] array;

        array = new T[_size-1];


        for(int k=0;k<_size-1;k++)

            array[k] = tmp[k];


        _size--;

    }


    void add(T source){

        T* tmp = new T[_size+1];


        int i;

        for(i=0;i<_size;i++)

            tmp[i] = array[i];


        tmp[i] = source;


        delete[] array;

        array = new T[_size+1];


        for(int j=0;j<_size+1;j++)

            array[j] = tmp[j];


        // On augmente la taille quand on est sûr d'avoir ajouter

        _size++;

    }

    maList& operator =(const maList& list){

        if(array != null)

            delete[] array;


        _size = list._size;

        array = new T[list.size];

        for(int i=0;i<list.size;i++)

            array[i] = list[i];


        return *this;

    }

    ~maList(){

        delete[] array;

    }


};



#endif // MALIST_H


