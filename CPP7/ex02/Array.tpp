    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   Array.tpp                                          :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2026/05/21 11:07:03 by skaynar           #+#    #+#             */
    /*   Updated: 2026/05/21 13:07:48 by skaynar          ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #include "Array.hpp"

    template <typename T>
    Array<T>::Array() : array(NULL), lenght(0){}

    template <typename T>
    Array<T>::Array(unsigned int len) : lenght(len){
    if(len == 0)
            array = NULL;
        else
            array = new T[lenght];
    }

    template <typename T>
    Array<T>::Array(const Array& other) : lenght(other.lenght){
        if(lenght == 0)
            array = NULL;
        else
        {
            array =  new T[lenght];
            for(unsigned int i = 0; i < lenght; ++i)
                array[i] = other.array[i];
        }
    }

    template <typename T>
    Array<T>& Array<T>::operator=(const Array& other){
        if(this != &other){
            delete [] array;
            lenght = other.lenght;
            if(lenght == 0)
                array = NULL;
            else
            {
                array = new T[lenght];
                for(unsigned int i = 0; i < lenght; ++i)
                    array[i] = other.array[i];
            }
        }
        return *this;
    }

    template <typename T>
    Array<T>::~Array(){
        delete [] array;
    }

    template <typename T>
    T& Array<T>::operator[](unsigned int index){
        if(index >= lenght)
            throw OutOfException();
        return array[index];
    }

    template <typename T>
    const T& Array<T>::operator[](unsigned int index) const{
        if(index >= lenght)
            throw OutOfException();
        return array[index];
    }

    template <typename T>
    unsigned int Array<T>::size() const{
        return lenght;
    }

    template <typename T>
    const char* Array<T>::OutOfException::what() const throw(){
        return "Index out of bounds";
    }