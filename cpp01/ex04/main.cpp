/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:06:54 by emauduit          #+#    #+#             */
/*   Updated: 2024/05/20 17:15:47 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


void replace_occurrences(std::ifstream &inputFile, std::ofstream &outputFile, \
                        const std::string s1, const std::string s2)
{
    std::string line;
    
    while (std::getline(inputFile, line)){
        size_t pos = 0;
        while ((pos = line.find(s1,pos)) != std::string::npos){
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
            
        }
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
}

static void open_files(const std::string &file, const std::string s1, const std::string s2)
{
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()){
        std::cerr << "Error can't open: " << file << std::endl;
        return ;
    }
    std::string output_file = file + ".replace";
    std::ofstream outputFile(output_file.c_str());
    if (!outputFile.is_open()){
        std::cerr << "Error can't open: " << output_file << std::endl;
        inputFile.close();
        return ;
    }
    replace_occurrences(inputFile, outputFile, s1, s2);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "You need 4 arg: <file name> <S1> <S2>" << std::endl;
        return (1);
    }

    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    open_files(file, s1, s2);
    return (0);
}
