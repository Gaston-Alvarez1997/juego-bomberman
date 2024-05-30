#pragma once
#include <SFML/Graphics.hpp>

class ClaseEscenario{
private:
    int _matriz[13][15] = {};
    

public:

    sf::Texture _texturasuelo;
    sf::Sprite _spritesuelo;
    //sf::Texture _texturasolido;
    //sf::Sprite _spritesolido;
    //sf::Texture _texturabloque;
    //sf::Sprite _spritebloque;
    ////////////////////////////////////////////7
    ClaseEscenario();
    ///////////////////////
   
    int getmatriz(int x, int y);
 
    
    ///////////////////////////////////////////
    
    

};


