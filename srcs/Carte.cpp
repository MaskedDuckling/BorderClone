#include "Carte.hpp"

#include <fstream>
#include <iostream>

std::vector<std::string>   Carte::convert_row(std::string row)
{
    std::vector<std::string> res;

    for (size_t i = 0; i < row.size(); i++)    {
        if (convert_map.count(row[i]))
            res.push_back(convert_map[row[i]]);
    }
    return (res);
}

Carte::Carte(std::string filename): sprites("sprites/props.png"){
    std::fstream file(filename);
    std::string row;
    
    while (getline (file, row)) {
        if (row[0] == '#')
            convert_map[row[1]] = row.substr(3);
        else    {
            auto crow = convert_row(row);
            rows.push_back(crow);
        }
    }
    height = rows.size();
    width = rows[0].size();
    std::cout << "CARTE : " << height << ", " << width << std::endl;
}
Carte::~Carte(){}

void Carte::render()
{
    for (int i = 0; i < height; i++)    {
        for (int j = 0; j < width; j++) {
            sprites.render(j, i, rows[i][j]);
        }
    }
}

std::ostream &operator<<(std::ostream &out, Carte const & rhs){
    for (auto it = rhs.rows.begin(); it != rhs.rows.end(); it++){
        for (std::string s : *it)
            out << "\"" << s << "\" ";
        out << std::endl;
    }
    return (out);
}