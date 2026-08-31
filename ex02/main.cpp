/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:25:55 by bsampaio          #+#    #+#             */
/*   Updated: 2026/08/31 07:35:57 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    srand(std::time(0));
    Base *base = generate();
    Base &ref = *base;
    
    identify(base);
    identify(ref);
    
    Base *base1 = generate();
    Base &ref1 = *base1;
    
    identify(base1);
    identify(ref1);

    delete base;
    delete base1;
    return 0;
}