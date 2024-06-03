#include "bomba.h"

CBomba::CBomba() {

	if (!_texturaBomba.loadFromFile("imagenes/bomba.png")) {
		exit(19);
	}
	if (!_texturaexplosion.loadFromFile("imagenes/explosion.png")) {
		exit(19);
	}
	
	_spriteBomba.setTexture(_texturaBomba);
	_spriteExplosion.setTexture(_texturaexplosion);
	_spriteExplosion.setScale(0.9f, 0.9f);
	

	_estadoExplosion = false;
	_viva = false;
	_frame = 0;
}
///////////////////

void CBomba::setBombaPosicion (int x,int y) {
	_spriteBomba.setPosition(x,y);
	_tiempo.restart();
}

void CBomba::setestado(bool cambio) {
	_viva = cambio;
}

bool CBomba::getestado() {
	return _viva;
}

bool CBomba::getexplision() {
	return _estadoExplosion;
}
/////////////////////
void CBomba::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (_viva) {
		target.draw(_spriteBomba, states);
	}
	else if (_estadoExplosion) {
		target.draw(_spriteExplosion, states);
	}
}

sf::FloatRect CBomba::getBounds() const {
	return _spriteBomba.getGlobalBounds();
}
///////////////////////////////////////
void	CBomba::animacionBomba() {
	

	for (int x = 0; x < 30; x++) {
		_frame += 0.1f;

		if (_frame >= 3) {
			_frame = 0;
		}

		_spriteBomba.setTextureRect({ 0 + int(_frame) * 50,0,50,42 });
	}
	
}


void CBomba::animacionExplosion() {
	

	_frame += 0.1f;

	if (_frame >= 3) {
		_frame = 0;
		_estadoExplosion = false;
		_viva = false;
	}

	_spriteExplosion.setTextureRect({ 0 + int(_frame) * 50,0,50,46 });

}


void CBomba::estadosParaDibujo() {
	if (_viva && _tiempo.getElapsedTime().asSeconds() >= 3) {
		_viva = false;
		_estadoExplosion = true;
		_spriteExplosion.setPosition(_spriteBomba.getPosition());
	} 

	if (_estadoExplosion) {
		animacionExplosion();
	}
	else if (_viva) {
		animacionBomba();
	}
}

