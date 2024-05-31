#include "bomba.h"

CBomba::CBomba() {

	if (!_texturaBomba.loadFromFile("imagenes/bomba.png")) {
		exit(19);
	}
	if (!_texturaexplosion.loadFromFile("imagenes/explosion.png")) {
		exit(19);
	}
	

	_estadoExplosion = false;
	_viva = false;
	_frame = 0;
}
///////////////////

void CBomba::setBombaPosicion (int x,int y) {
	_spriteBomba.setPosition(x,y);
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
	target.draw(_spriteBomba, states);
}

sf::FloatRect CBomba::getBounds() const {
	return _spriteBomba.getGlobalBounds();
}
///////////////////////////////////////
void	CBomba::animacionBomba() {
	
	_spriteBomba.setTexture(_texturaBomba);
	
	for (int x = 0; x < 30; x++) {
		_frame += 0.1f;

		if (_frame >= 3) {
			_frame = 0;
		}

		_spriteBomba.setTextureRect({ 0 + int(_frame) * 50,0,50,42 });
	}
			_estadoExplosion = true;
}



