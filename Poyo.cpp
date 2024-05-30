#include "Poyo.h"

EnemigoPoyo::EnemigoPoyo() {
    if (!_textura.loadFromFile("imagenes/Poyo.png")) {
        exit(10);
    }
    _spritepoyo.setTexture(_textura);
    _spritepoyo.setScale(0.9f, 0.9f);

    _velocidad = 3.0f;
    _frame = 0;
    _direccion = 1;
    _PuntosVida = 1;

}

void EnemigoPoyo::PosicionInicial(float x, float y) {
    _spritepoyo.setPosition(x, y);
}

void EnemigoPoyo::setposicion() {

    _spritepoyo.setPosition(_correguirPosicion);

}



sf::FloatRect EnemigoPoyo::getBounds() const {
    return _spritepoyo.getGlobalBounds();
}


void EnemigoPoyo::Movimiento(int numero) {

    _correguirPosicion = _spritepoyo.getPosition();

    _frame += 0.2f;
        if (_frame >= 2) {
            _frame = 0;
        }

        switch (numero){
        case 0:
            _spritepoyo.setTextureRect({ 300 + int(_frame) * 50,0,50,46 });
            _spritepoyo.move(_velocidad * _direccion, 0);
            break;
        
        case 1:
            _spritepoyo.setTextureRect({ 100 + int(_frame) * 50,0,50,46 });
            _spritepoyo.move(_velocidad * -_direccion, 0);
            break;
        case 2:
            _spritepoyo.setTextureRect({ 0 + int(_frame) * 50,0,50,46 });
            _spritepoyo.move(0, _velocidad * _direccion);
            break;
        case 3:
            _spritepoyo.setTextureRect({ 200 + int(_frame) * 50,0,50,46 });
            _spritepoyo.move(0, _velocidad * -_direccion);
        }
}


void EnemigoPoyo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spritepoyo, states);
}