
// objet cin et cout qui vont correspondre a la sortie ou lentree
// ajout des >> et << 


#include <iostream>

int main(void)
{
    char buff[200];

    std::cout << "Hello World" << " salut" << std::endl;
    std::cin >> buff;

    std::cout << "copy:" << buff  << std::endl;
}