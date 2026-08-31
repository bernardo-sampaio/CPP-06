/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:05:47 by bsampaio          #+#    #+#             */
/*   Updated: 2026/08/28 08:44:52 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;

    Data *ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data *result = Serializer::deserialize(raw);

    if (result == ptr)
        std::cout<<"A serialização/desserialização funcionou.\n";
    std::cout<<"Data - ptr = "<<ptr<<std::endl;
    std::cout<<"uintptr_t - raw =  "<<raw<<std::endl;
    std::cout<<"Data - result = "<<result<<std::endl;

    return 0;
}