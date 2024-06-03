#include "gameplay.h"
#include "CEscenario.h"
#include "spritebloque.h"
#include "spritesolido.h"
#include "personaje.h"
#include "bomba.h"
#include "Poyo.h"
#include "Robodash.h"
#include "sr.Moai.h"
#include "PoyoMole.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>


Gameplay::Gameplay() {}

void Gameplay::compilarJuego() {
    ClaseEscenario mapa;
    Spritebloque bloque;
    Spritesolido solido;
    CBomba nuevabomba;
    Personaje bomberboy;
    EnemigoPoyo poyo;
    EnemigoRobo robodash;
    EnemigoMoai moai;
    EnemigoPoyoMole poyomole;
    int movimientorandompoyo=0;
    int movimientorandomrobo = 0;
    int movimientorandommoai = 0;
    int movimientorandompoyomole = 0;
    std::vector<Spritebloque> bloques;
    std::vector<Spritesolido> solidos;
    std::vector<sf::Vector2i> posicionesLibres;
    

    const float tamCeldas = 54;
    const float tamCeldasy = 46;
    
    std::srand(std::time(nullptr));

    for (int x = 0; x < 13; ++x) {
        for (int y = 0; y < 15; ++y) {
            if (mapa.getmatriz(x, y) == 2) {
                posicionesLibres.push_back(sf::Vector2i(x, y));
            }
        }
    }

    ///posicionandolo en alguna de las casillas libres del mapa
    for (int x = 0; x < 4; x++) {
        int indiceAleatorio = std::rand() % (posicionesLibres.size() - 1);
        sf::Vector2i posicionEnemigo = posicionesLibres[indiceAleatorio];
        if (x == 0) {
            poyo.PosicionInicial(posicionEnemigo.x * tamCeldas, posicionEnemigo.y * tamCeldasy);
        }
        if (x == 1) {
            robodash.PosicionInicial(posicionEnemigo.x * tamCeldas, posicionEnemigo.y * tamCeldasy);
        }
        if (x == 2) {
            moai.PosicionInicial(posicionEnemigo.x * tamCeldas, posicionEnemigo.y * tamCeldasy);
        }
        if (x == 3) {
            poyomole.PosicionInicial(posicionEnemigo.x * tamCeldas, posicionEnemigo.y * tamCeldasy);
        }
   }

    // Inicializar bloques y bloques sólidos según el mapa
    for (int x = 0; x < 13; ++x) {
        for (int y = 0; y < 15; ++y) {
            int valor = mapa.getmatriz(x, y);
            if (valor == 3) { // Bloques destruibles
                Spritebloque bloque;
                bloque._spritebloque.setPosition(x * tamCeldas, y * tamCeldasy);
                bloques.push_back(bloque);
            }
            else if (valor == 1) { // Bloques sólidos
                Spritesolido solido;
                solido._spritesolido.setPosition(x * tamCeldas, y * tamCeldasy);
                solidos.push_back(solido);
            }
        }
    }


    //////////INICIO DEL BUCLE DEL JUEGO

    sf::RenderWindow window(sf::VideoMode(702, 690), "Bomber boy"); ///54,46
    window.setFramerateLimit(30);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bomberboy.movimiento();
        poyo.Movimiento(movimientorandompoyo);
        robodash.Movimiento(movimientorandomrobo);
        moai.Movimiento(movimientorandommoai);
        poyomole.Movimiento(movimientorandompoyomole);
        
        ///intento de crear una bomba
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            nuevabomba.setBombaPosicion(bomberboy.getPosicion().x, bomberboy.getPosicion().y);
            nuevabomba.setestado(true);
        }

        nuevabomba.estadosParaDibujo();
        

        // Verificar colisiones con bloques destruibles
        for (auto& bloque : bloques) {
            if (bomberboy.escolisionable(bloque)) {
                std::cout << "Colision con bloque en: " << bloque.getBounds().left << ", " << bloque.getBounds().top << std::endl;
                bomberboy.setSpritePosicion();
            }
            if (poyo.escolisionable(bloque)) {
                poyo.setposicion();
                movimientorandompoyo= std::rand() % 4;
            }
            if (robodash.escolisionable(bloque)) {
                robodash.setposicion();
                movimientorandomrobo = std::rand() % 4;
            }
            if (moai.escolisionable(bloque)) {
                moai.setposicion();
                movimientorandommoai = std::rand() % 4;
            }
            if (poyomole.escolisionable(bloque)) {
                poyomole.setposicion();
                movimientorandompoyomole = std::rand() % 4;
            }
        }

        // Verificar colisiones con bloques sólidos
        for (auto& solido : solidos) {
            if (bomberboy.escolisionable(solido)) {
                std::cout << "Colision con bloque sólido en: " << solido.getBounds().left << ", " << solido.getBounds().top << std::endl;
                bomberboy.setSpritePosicion();
            }
            if (poyo.escolisionable(solido)) {
                poyo.setposicion();
                movimientorandompoyo = std::rand() % 4;
            }
            if (robodash.escolisionable(solido)) {
                robodash.setposicion();
                movimientorandomrobo = std::rand() % 4;
            }
            if (moai.escolisionable(solido)) {
                moai.setposicion();
                movimientorandommoai = std::rand() % 4;
            }
            if (poyomole.escolisionable(solido)) {
                poyomole.setposicion();
                movimientorandompoyomole = std::rand() % 4;
            }
        }



        window.clear();

        /// DIBUJANDO EL MAPA
        for (int x = 0; x < 13; ++x) {
            for (int y = 0; y < 15; ++y) {
                switch (mapa.getmatriz(x, y)) {
                case 0:
                    mapa._spritesuelo.setPosition(x * tamCeldas, y * tamCeldasy);
                    window.draw(mapa._spritesuelo);

                    break;
                case 1:

                    solido._spritesolido.setPosition(x * tamCeldas, y * tamCeldasy);
                    window.draw(solido);

                    break;
                case 2:
                    mapa._spritesuelo.setPosition(x * tamCeldas, y * tamCeldasy);
                    window.draw(mapa._spritesuelo);

                    break;
                case 3:

                    bloque._spritebloque.setPosition(x * tamCeldas, y * tamCeldasy);
                    window.draw(bloque);

                    break;
                }
            }
        }

       
        
        window.draw(nuevabomba);
        
        window.draw(poyo);
        window.draw(poyomole);
        window.draw(robodash);
        window.draw(moai);
        window.draw(bomberboy);

        window.display();
    }
}

