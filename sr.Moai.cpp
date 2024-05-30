#include "sr.Moai.h"

EnemigoMoai::EnemigoMoai() {
    if (!_textura.loadFromFile("imagenes/Moai.png")) {
        exit(10);
    }
    _spritemoai.setTexture(_textura);
    _spritemoai.setScale(0.9f, 0.9f);

    _velocidad = 4.0f;
    _frame = 0;
    _direccion = 1;
    _PuntosVida = 4;

}

void EnemigoMoai::PosicionInicial(float x, float y) {
    _spritemoai.setPosition(x, y);
}

void EnemigoMoai::setposicion() {

    _spritemoai.setPosition(_correguirPosicion);

}

void EnemigoMoai::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spritemoai, states);
}

sf::FloatRect EnemigoMoai::getBounds() const {
    return _spritemoai.getGlobalBounds();
}


void EnemigoMoai::Movimiento(int numero) {

    _correguirPosicion = _spritemoai.getPosition();

    _frame += 0.2f;
    if (_frame >= 3) {
        _frame = 0;
    }

    switch (numero) {
    case 0:
        _spritemoai.setTextureRect({ 350 + int(_frame) * 50,0,50,46 });
        _spritemoai.move(_velocidad * _direccion, 0);
        break;

    case 1:
        _spritemoai.setTextureRect({ 150 + int(_frame) * 50,0,50,46 });
        _spritemoai.move(_velocidad * -_direccion, 0);
        break;
    case 2:
        _spritemoai.setTextureRect({ 0 + int(_frame) * 50,0,50,46 });
        _spritemoai.move(0, _velocidad * _direccion);
        break;
    case 3:
        _spritemoai.setTextureRect({ 300,0,50,46 });
        _spritemoai.move(0, _velocidad * -_direccion);
    }
}