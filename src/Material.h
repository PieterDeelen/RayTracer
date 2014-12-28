#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "Color.h"

class Material {
public:

	Material(const Color& color, double ambient, double diffuse, double specular, double reflectivity);

	double getAmbient() const;
	const Color& getColor() const;
	double getDiffuse() const;
	double getReflectivity() const;
	double getSpecular() const;

private:
	Color color;
	double ambient;
	double diffuse;
	double specular;
	double reflectivity;
};

inline Material::Material(const Color& color, double ambient, double diffuse,
		double specular, double reflectivity)
	: color(color),
	  ambient(ambient),
	  diffuse(diffuse),
	  specular(specular),
	  reflectivity(reflectivity)
{}

inline double Material::getAmbient() const {
	return ambient;
}

inline const Color& Material::getColor() const {
	return color;
}

inline double Material::getDiffuse() const {
	return diffuse;
}

inline double Material::getReflectivity() const {
	return reflectivity;
}

inline double Material::getSpecular() const {
	return specular;
}

#endif /* MATERIAL_H_ */
