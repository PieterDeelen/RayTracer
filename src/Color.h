#ifndef COLOR_CPP_
#define COLOR_CPP_

#include <algorithm>

class Color {
public:
	Color(double red, double green, double blue);

	double getRed() const;
	double getGreen() const;
	double getBlue() const;

	Color& operator+=(const Color& other) {
		red += other.red;
		green += other.green;
		blue += other.blue;
		return *this;
	}

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

inline Color operator*(double lhs, const Color& rhs) {
	return rhs * lhs;
}

inline double clampColor(double value) {
	return std::max(0.0, std::min(value, 1.0));
}

inline Color clamp(const Color& color) {
	return Color(
			clampColor(color.getRed()),
			clampColor(color.getGreen()),
			clampColor(color.getBlue()));
}

inline double Color::getRed() const {
	return red;
}

inline double Color::getGreen() const {
	return green;
}

inline double Color::getBlue() const {
	return blue;
}

#endif /* COLOR_CPP_ */
