#include "personaje.h"
#include "bomba.h"

Personaje::Personaje() {
	if (!_textura.loadFromFile("imagenes/sprite.png")) {
		exit(19);
	}
	_sprite.setTexture(_textura);
	_sprite.setTextureRect({ 158, 0, 50, 42 });
	_sprite.setPosition(54, 46);
	_sprite.setScale(0.9f, 0.9f);


	_velocidad = 6;
	_frame = 0;
}
/////////////////
void Personaje::setSpritePosicion() {
	_sprite.setPosition(_correguirPosicion);
}

void Personaje::setCorreguirPosicion() {
	_correguirPosicion = _sprite.getPosition();
}

sf::Vector2f Personaje::getCorreguirPosicion(){
	return _correguirPosicion;
}

/////////////////////
sf::FloatRect Personaje::getBounds() const {
	return _sprite.getGlobalBounds();
}
//////////////////////

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite,states );
}

///////////////////////

void Personaje::movimiento() {

	_frame += 0.2f;

	if (_frame >= 3) {
		_frame = 0;
	}
	
	setCorreguirPosicion();

	///mueve al PJ
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_sprite.setTextureRect({ 0 + int(_frame)*52,0,50,42 });
		_sprite.move(0, -_velocidad);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_sprite.setTextureRect({ 488 + int(_frame) * 52,0,50,42 });
		_sprite.move(-_velocidad,0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_sprite.setTextureRect({ 326 + int(_frame) * 52,0,50,42 });
		_sprite.move(+_velocidad, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_sprite.setTextureRect({ 162 + int(_frame) * 52,0,50,42 });
		_sprite.move(0, +_velocidad);
	}

	///valida que el PJ no se vaya de la pantalla

	if (_sprite.getPosition().x < 0) {
		_sprite.setPosition(0, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().y < 0) {
		_sprite.setPosition(_sprite.getPosition().x,0);
	}
	if (_sprite.getPosition().x+_sprite.getGlobalBounds().width > 702) {
		_sprite.setPosition(702- _sprite.getGlobalBounds().width, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().y+ _sprite.getGlobalBounds().width > 690) {
		_sprite.setPosition(_sprite.getPosition().x,690 - _sprite.getGlobalBounds().width);
	}

}

///////////////////// CREAR BOMBA
/*
void Personaje::crearBomba() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		CBomba bomba1;
		bomba1.setBombaPosicion(_sprite.getPosition().x, _sprite.getPosition().y);
		
		bomba1.animacionBomba();
	}
}*/



