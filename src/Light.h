#ifndef LIGHT_H_
#define LIGHT_H_

#include "Vector.h"

class Light {
public:
	Light(const Vector4d& position, double intensity);

	double getIntensity() const;
	const Vector4d& getPosition() const;
private:
	Vector4d position;
	double intensity;
};

inline Light::Light(const Vector4d& position, double intensity) :
		position(position), intensity(intensity) {
}

inline double Light::getIntensity() const {
	return intensity;
}

inline const Vector4d& Light::getPosition() const {
	return position;
}

#endif /* LIGHT_H_ */
