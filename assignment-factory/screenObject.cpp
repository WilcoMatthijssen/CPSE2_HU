#include "screenObject.hpp"

const std::string screenObject::whatAmI() { 
	return "screenObject"; 
}
std::ostream& operator << (std::ostream& out, screenObject& shape)
{
	out << shape.whatAmI();
	return out;
}