/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:07:01 by skaynar           #+#    #+#             */
/*   Updated: 2026/05/21 13:07:02 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
    T* array;
    unsigned int lenght;
    public:
    Array();
    Array(unsigned int len);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
    
    class OutOfException : public std::exception {
        const char* what() const throw();
    };
    
};

#include "Array.tpp"

#endif