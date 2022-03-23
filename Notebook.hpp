#include "Direction.hpp"
#include <iostream>
#include <string>

namespace ariel{

    /**
     * This class will implement a notebook
     * 
     * Methods:
     *  - write: write on the notenook (horizontal/vertical)
     *  - read: read a line of the notebook (horizontal/vertical)
     *  - earse: erase a line on the notebook (horizontal/vertical)
     *  - show: prints the notebook
     * 
     * features:
     *  - infinte pages
     *  - infinte rows per page
     *  - 100 character limit per row
     *  - Cant write on written text and erased text 
     *  
     */

    class Notebook{
        
        private:
        // currently undefined

        public:

            //constuctor
            Notebook(){}

            //destructor
            ~Notebook(){}

            // given the page,row and col write the given string, horizontal or vertical
            void write(unsigned int page, unsigned int row, unsigned int col, Direction direc, std::string input){}

            // given the page,row and col read the given amount of characters, horizontal or vertical
            std::string read(unsigned int page, unsigned int row, unsigned int col,Direction direc, unsigned int length){
                return "empty";
            }

            // given the page,row and col earse the given given amount of characters, horizontal or vertical
            void erase(unsigned int page, unsigned int row, unsigned int col,Direction direc, unsigned int length){}

            // prints the notebook
            void show(unsigned int page){}
    };
};