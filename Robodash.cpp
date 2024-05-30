#include "Robodash.h"

EnemigoRobo::EnemigoRobo() {
    if (!_textura.loadFromFile("imagenes/robodash.png")) {
        exit(10);
    }
    _spriterobo.setTexture(_textura);
    _spriterobo.setScale(0.9f, 0.9f);

    _velocidad = 3.0f;
    _frame = 0;
    _direccion = 1;
    _PuntosVida = 2;
}

void EnemigoRobo::PosicionInicial(float x, float y) {
    _spriterobo.setPosition(x, y);
}

sf::FloatRect EnemigoRobo::getBounds() const {
    return _spriterobo.getGlobalBounds();
}


void EnemigoRobo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spriterobo, states);
}

void EnemigoRobo::setposicion() {

    _spriterobo.setPosition(_correguirPosicion);

}

void EnemigoRobo::Movimiento(int numero) {

    _correguirPosicion = _spriterobo.getPosition();
    if (_PuntosVida == 1) {
        _velocidad = 6.0f;
    }

    _frame += 0.2f;
    if (_frame >= 3) {
        _frame = 0;
    }

    switch (numero) {
    case 0:
        _spriterobo.setTextureRect({ 450 + int(_frame) * 50,0,50,46 });
        _spriterobo.move(_velocidad * _direccion, 0);
        break;

    case 1:
        _spriterobo.setTextureRect({ 150 + int(_frame) * 50,0,50,46 });
        _spriterobo.move(_velocidad * -_direccion, 0);
        break;
    case 2:
        _spriterobo.setTextureRect({ 300 + int(_frame) * 50,0,50,46 });
        _spriterobo.move(0, _velocidad * _direccion);
        break;
    case 3:
        _spriterobo.setTextureRect({ 0 + int(_frame) * 50,0,50,46 });
        _spriterobo.move(0, _velocidad * -_direccion);
    }
}