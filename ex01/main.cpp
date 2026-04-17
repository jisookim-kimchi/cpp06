/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 12:47:39 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 14:05:33 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "kimchi";
    data.price = 3;

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "data Address : " << &data << std::endl;
    std::cout << std::endl;
   
    if (&data == deserialized)
    {
        std::cout << "ADDRESS MATCH!" << std::endl;
        std::cout << "deserialized Address : " << deserialized << std::endl;
        std::cout << "raw value(dex) : " << raw << std::endl;
        std::cout << std::hex << "0x" << raw << std::endl;
    }
    else
        std::cout << "ADDRESS DO NOT MATCH!" << std::endl;

    std::cout << "name: " << deserialized->name << std::endl;
    std::cout << "price: " << deserialized->price << std::endl;
    return 0;
}