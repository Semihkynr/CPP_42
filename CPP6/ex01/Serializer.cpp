/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaynar <skaynar@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:35:32 by skaynar           #+#    #+#             */
/*   Updated: 2026/03/06 15:33:58 by skaynar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) { (void)src; }
Serializer& Serializer::operator=(const Serializer& rhs) { (void)rhs; return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {return reinterpret_cast<uintptr_t>(ptr);}
Data* Serializer::deserialize(uintptr_t raw) {return reinterpret_cast<Data*>(raw);}