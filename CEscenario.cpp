#include "CEscenario.h"

#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

 ////////////////////////////////////////////7
ClaseEscenario::ClaseEscenario() {
    
    srand(time(NULL()));
    for (int x = 0; x < 13; x++) {
        for (int y = 0; y < 15; y++) {
            if (x == 0 || y == 0 || x == 13 - 1 || y == 15 - 1) {         ///genera los bondes limitantes
                _matriz[x][y] = 1;
            }
            else {
                if (x % 2 == 0 && y % 2 == 0) {             ///genera los bloques del medio indestructibles como los bordes
                    _matriz[x][y] = 1;
                }
                else {

                    if (x == 1 && y == 1 || x == 1 && y == 2 || x == 2 && y == 1 || x == 13 - 2 && y == 15 - 2 || x == 13 - 2 && y == 15 - 3 || x == 13 - 3 && y == 15 - 2) {
                        _matriz[x][y] = 0;               ///genera las esquinas libres para poder caminar el comienzo
                    }
                    else {
                        _matriz[x][y] = rand() % 2 + 2;       ///genera random los bloques del mapa,siendo 2 un lugar libre y 3 un bloque destruible
                    }
                }
            }
        }
    }
    
    if (!_texturasuelo.loadFromFile("imagenes/suelo.png")) {
        exit(10);
    }
   // if (!_texturasolido.loadFromFile("imagenes/solido.png")) {
     //   exit(10);
    //}
    //if (!_texturabloque.loadFromFile("imagenes/bloque.png")) {
     //   exit(10);
    //}
    _spritesuelo.setTexture(_texturasuelo);
    //_spritesolido.setTexture(_texturasolido);
    //_spritebloque.setTexture(_texturabloque);

    
    
 

}


 
    //////////////////////////////////

    int ClaseEscenario::getmatriz(int x, int y) {
        return _matriz[x][y];
    }
    
 
    
    ///////////////////////////////////////////
    

    



