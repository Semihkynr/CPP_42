/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:31:31 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/17 13:54:45 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _max(n) {_data.reserve(n);}

Span::Span(const Span& other) : _max(other._max), _data(other._data) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _max  = other._max;
        _data = other._data;
    }
    return *this;}
Span::~Span() {}
const char* Span::FullException::what() const throw() {return "Span: kapasite dolu, yeni eleman eklenemez";}

const char* Span::NoSpanException::what() const throw() {return "Span: aralik hesaplamak icin yeterli eleman yok (en az 2 gerekli)";}
void Span::addNumber(int n) {
    if (_data.size() >= _max)
        throw FullException();
    _data.push_back(n);}
int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
    return *std::min_element(diffs.begin() + 1, diffs.end());}
int Span::longestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();
    int lo = *std::min_element(_data.begin(), _data.end());
    int hi = *std::max_element(_data.begin(), _data.end());
    return hi - lo;}