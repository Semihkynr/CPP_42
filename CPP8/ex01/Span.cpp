/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:31:31 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/10 00:00:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// OCF: parametreli constructor - kapasite belirlenir, bellek on-ayrilir
Span::Span(unsigned int n) : _max(n) {
    // reserve: toplu ekleme (addRange) sirasinda gereksiz reallocation onler
    _data.reserve(n);
}

// Kopyalama constructor'i: derin kopya, vector kendi ic bellegini kopyalar
Span::Span(const Span& other) : _max(other._max), _data(other._data) {}

// Atama operatoru: oz-atama kontrolu, ardindan derin kopya
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _max  = other._max;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

// İstisna mesajlari: Span icindeki ic siniflar oldugu icin Span:: oneki zorunlu
const char* Span::FullException::what() const throw() {
    return "Span: kapasite dolu, yeni eleman eklenemez";
}

const char* Span::NoSpanException::what() const throw() {
    return "Span: aralik hesaplamak icin yeterli eleman yok (en az 2 gerekli)";
}

// Tekli eleman ekleme: kapasite asiminda FullException firlatilir
void Span::addNumber(int n) {
    if (_data.size() >= _max)
        throw FullException();
    _data.push_back(n);
}

/*
** shortestSpan - En kisa aralik:
**   Siralamas yapilmis bir dizide en kucuk fark MUTLAKA komsu iki eleman
**   arasindadir. Bu gercegi kullanarak:
**     1) Kopyayi sirala     -> std::sort
**     2) Komsu farklari hesapla -> std::adjacent_difference
**        (diffs[0] = sorted[0] kopyasi; gercek farklar diffs[1..] de)
**     3) En kucuk farki bul -> std::min_element
**   Hic elle yazilmis dongu yok; tamamen STL.
*/
int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

    // diffs[0] sorted[0]'in kendisidir, gercek farklar index 1'den baslar
    return *std::min_element(diffs.begin() + 1, diffs.end());
}

/*
** longestSpan - En uzun aralik:
**   En buyuk ve en kucuk elemanlarin farki, tum olasi ciftlerin en buyuk
**   araligini verir. std::min_element ve std::max_element ile iki tarama.
*/
int Span::longestSpan() const {
    if (_data.size() < 2)
        throw NoSpanException();

    int lo = *std::min_element(_data.begin(), _data.end());
    int hi = *std::max_element(_data.begin(), _data.end());
    return hi - lo;
}
