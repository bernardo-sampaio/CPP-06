/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsampaio <bsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:16:59 by bsampaio          #+#    #+#             */
/*   Updated: 2026/08/24 14:27:12 by bsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void)obj;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string value)
{
    char* endptr;
    errno = 0;
    
    if (value.length() == 1 && !std::isdigit(value[0]))
    {
        char c = value[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }
    std::cout<<std::fixed<<std::setprecision(1);
    double d = std::strtod(value.c_str(), &endptr);

    if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "char: impossible\n";
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    if (std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
    if (!std::isnan(d) && !std::isinf(d)
        && (d > std::numeric_limits<float>::max()
        || d < -std::numeric_limits<float>::max()))
    {
        std::cout << "float: ";
        if (d > 0)
            std::cout << "+inff\n";
        else
            std::cout<<"-inff\n";
    }
    else
        std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}