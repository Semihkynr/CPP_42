/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Home.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:01:53 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/12 15:01:54 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOME_HPP
# define HOME_HPP

# include <iostream>

class Home {
    public:
        virtual ~Home() {}
};

class A : public Home {};
class B : public Home {};
class C : public Home {};

#endif