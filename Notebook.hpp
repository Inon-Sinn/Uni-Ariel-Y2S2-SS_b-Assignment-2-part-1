#include "Direction.hpp"
#include <iostream>
#include <string>

namespace ariel{

    class Notebook{
        
        private:
        // currently undefined
        public:

            //constuctor
            Notebook(){}

            //destructor
            ~Notebook(){}

            void write(unsigned int page, unsigned int row, unsigned int col, Direction direc, std::string input){}

            std::string read(unsigned int page, unsigned int row, unsigned int col,Direction direc, unsigned int length){
                return "empty";
            }

            void erase(unsigned int page, unsigned int row, unsigned int col,Direction direc, unsigned int length){}

            void show(unsigned int page){}
    };
};