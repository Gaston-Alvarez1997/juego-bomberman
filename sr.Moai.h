#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class EnemigoMoai : public sf::Drawable, public Colision {

private:
	sf::Texture _textura;
	sf::Sprite _spritemoai;
	sf::Vector2f _correguirPosicion;
	int _direccion;
	float _velocidad;
	float _frame;
	int _PuntosVida;

public:

	EnemigoMoai();

	void setposicion();

	void PosicionInicial(float x, float y);

	void Movimiento(int numero);

	sf::FloatRect getBounds() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;


};