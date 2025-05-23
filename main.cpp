#include <iostream>

int main() {

    std::cout << "Hello and welcome to \n";

    for (int y=0; y<20; y++) {
        for (int x=0; x<20; x++) {
            std::cout << "# " << " ";
        }
        std::cout << std::endl;
    }

    return 0;
   }