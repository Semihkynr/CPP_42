/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:57:13 by skaynar           #+#    #+#             */
/*   Updated: 2025/11/02 14:02:24 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl();
    void complain( std::string level );
};
    
#endif