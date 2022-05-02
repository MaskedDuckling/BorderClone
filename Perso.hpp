#include <raylib.h>
#include "Vector.hpp"

class Perso
{
private:
    Vector _Position;
    int _mSpeed;
    int _Health;
public:
    Perso();
    ~Perso();
    void    move_x();

};

Perso::Perso() : Position(150, 150), _mSpeed(5), _Health(10)
{
}

Perso::~Perso()
{
}
