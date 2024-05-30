#include "PoyoMole.h"

EnemigoPoyoMole::EnemigoPoyoMole() {
    if (!_textura.loadFromFile("imagenes/PoyoMole.png")) {
        exit(10);
    }
    _spritepoyomole.setTexture(_textura);
    _spritepoyomole.setScale(0.9f, 0.9f);

    _velocidad = 3.0f;
    _frame = 0;
    _direccion = 1;
    _PuntosVida = 1;

}

sf::FloatRect EnemigoPoyoMole::getBounds() const {
    return _spritepoyomole.getGlobalBounds();
}

void EnemigoPoyoMole::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spritepoyomole, states);
}

void EnemigoPoyoMole::PosicionInicial(float x, float y) {
    _spritepoyomole.setPosition(x, y);
}

void EnemigoPoyoMole::setposicion() {

    _spritepoyomole.setPosition(_correguirPosicion);

}

void EnemigoPoyoMole::Movimiento(int numero) {

    _correguirPosicion = _spritepoyomole.getPosition();

    _frame += 0.2f;
    if (_frame >= 2) {
        _frame = 0;
    }

    switch (numero) {
    case 0:
        _spritepoyomole.setTextureRect({ 0 + int(_frame) * 50,0,50,46 });
        _spritepoyomole.move(_velocidad * _direccion, 0);
        break;

    case 1:
        _spritepoyomole.setTextureRect({ 300 + int(_frame) * 50,0,50,46 });
        _spritepoyomole.move(_velocidad * -_direccion, 0);
        break;
    case 2:
        _spritepoyomole.setTextureRect({ 100 + int(_frame) * 50,0,50,46 });
        _spritepoyomole.move(0, _velocidad * _direccion);
        break;
    case 3:
        _spritepoyomole.setTextureRect({ 200 + int(_frame) * 50,0,50,46 });
        _spritepoyomole.move(0, _velocidad * -_direccion);
    }
}