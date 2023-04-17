#ifndef CARTE_HPP
# define CARTE_HPP

#include <vector>
#include <string>
#include "TileMap.hpp"

class Carte{
    private:
    public:
        std::vector<std::vector<std::string>> rows;
        int height;
        int width;
        TileMap sprites;
        std::map<char, std::string> convert_map;

        Carte();  
        Carte(std::string filename);
        ~Carte();

        std::vector<std::string>   convert_row(std::string row);
        void render();
};

std::ostream &operator<<(std::ostream &out, Carte const & rhs);

#endif