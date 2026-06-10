/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:31:35 by skaynar           #+#    #+#             */
/*   Updated: 2026/06/10 00:00:00 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>    // dahili depolama icin
# include <algorithm> // std::sort, std::min_element, std::max_element icin
# include <exception> // std::exception icin
# include <numeric>   // std::adjacent_difference icin
# include <iterator>  // std::distance icin

class Span {
public:
    // OCF: Orthodox Canonical Form - 4 zorunlu uye fonksiyon
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    /*
    ** addRange: iterator cifti alan sablon fonksiyon.
    ** vector, list, dizi pointer'i gibi her tur iterator kabul eder.
    ** std::distance ile gelen eleman sayisi hesaplanir; kapasite asiminda
    ** istisna firlatilir. Asil ekleme std::vector::insert ile yapilir -
    ** tek satir, sifir elle yazilmis dongu.
    */
    template <typename Iterator>
    void addRange(Iterator first, Iterator last) {
        unsigned int incoming =
            static_cast<unsigned int>(std::distance(first, last));
        if (_data.size() + incoming > _max)
            throw FullException();
        _data.insert(_data.end(), first, last);
    }

    int shortestSpan() const;
    int longestSpan()  const;

    // Kapsam doluysa firlatilir
    class FullException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Eleman sayisi hesaplama icin yetersizse firlatilir (0 veya 1 eleman)
    class NoSpanException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    unsigned int     _max;   // izin verilen maksimum eleman sayisi
    std::vector<int> _data;  // elemanlari tutan STL container
};

#endif
