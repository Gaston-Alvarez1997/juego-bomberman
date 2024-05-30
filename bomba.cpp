/*#include "bomba.h"

CBomba::CBomba() {

	if (!_texturaBomba.loadFromFile("imagenes/bomba.png")) {
		exit(19);
	}
	_spriteBomba.setTexture(_texturaBomba);

}
///////////////////

void CBomba::setBombaPosicion(int x,int y) {
	_spriteBomba.setPosition(x,y);
}

/////////////////////
void CBomba::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_spriteBomba, states);
}

///////////////////////////////////////
void	CBomba::animacionBomba() {

	bool bandera=true;

	for (int x = 0; x < 45; x++) {
		if (bandera==true) {
			_frame += 0.2f;
			_spriteBomba.setTextureRect({ 0 + int(_frame) * 50,0,50,42 });
			if (_frame == 3) {
				bandera = false;
			}
		}
		if (bandera==false) {
			_frame -= 0.2f;
			_spriteBomba.setTextureRect({ 0 + int(_frame) * 50,0,50,42 });
			if (_frame == 0) {
				bandera = true;
			}
		}
	}
}
*/