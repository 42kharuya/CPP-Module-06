#include "Serializer.hpp"

// ------------------------ Orthdox Canonical ------------------------
Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) { static_cast<void>(other); }

Serializer& Serializer::operator=(const Serializer &other) {
	static_cast<void>(other);
    return *this;
}
