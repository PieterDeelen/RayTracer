#ifndef COLOR_CPP_
#define COLOR_CPP_

#include <algorithm>

class Color {
public:
	Color(double red, double green, double blue);

	double getRed() const;
	double getGreen() const;
	double getBlue() const;

private:
	double red;
	double green;
	double blue;
};

inline Color::Color(double red, double green, double blue)
	: red(red), green(green), blue(blue)
{}

inline Color operator+(const Color& lhs, const Color& rhs) {
	return Color(
			lhs.getRed() + rhs.getRed(),
			lhs.getGreen() + rhs.getGreen(),
			lhs.getBlue() + rhs.getBlue());
}

inline Color operator*(const Color& lhs, double rhs) {
	return Color(lhs.getRed() * rhs, lhs.getGreen() * rhs, lhs.getBlue() * rhs);
}

double clampColor(double value) {
	return std::max(0.0, std::max(value, 1.0));
}

inline Color clamp(const Color& color) {
	return Color(
			clampColor(color.getRed()),
			clampColor(color.getGreen()),
			clampColor(color.getBlue()));
}

#endif /* COLOR_CPP_ */
