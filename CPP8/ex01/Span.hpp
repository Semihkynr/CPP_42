/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:31:35 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/17 13:53:01 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception> 
# include <numeric>
# include <iterator>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int n);
    template <typename Iterator>
    void addRange(Iterator first, Iterator last) {
        unsigned int incoming =
            static_cast<unsigned int>(std::distance(first, last));
        if (_data.size() + incoming > _max)
            throw FullException();
        _data.insert(_data.end(), first, last);}

    int shortestSpan() const;
    int longestSpan()  const;
    class FullException : public std::exception {
    public:
        const char* what() const throw();};
    class NoSpanException : public std::exception {
    public:
        const char* what() const throw();};
private:
    unsigned int     _max;
    std::vector<int> _data;
};

#endif