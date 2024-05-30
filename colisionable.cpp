#include "colisionable.h"

bool Colision::escolisionable(Colision& obj)const {
	return getBounds().intersects(obj.getBounds());
}
