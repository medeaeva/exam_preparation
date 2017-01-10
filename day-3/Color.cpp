#include "color.h"
#include <iostream>

using namespace std;

Color::Color() {
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::~Color() {
}

unsigned char* Color::get_red() {
	return &red;
}

unsigned char* Color::get_green() {
	return &green;
}

unsigned char* Color::get_blue() {
	return &blue;
}

Color::Color(string hex_color) {
	if (is_hex(hex_color)) {
		red = string_to_hex(hex_color, 1);
		green = string_to_hex(hex_color, 3);
		blue = string_to_hex(hex_color, 5);
	}
	else {
		throw;
	}
}

bool Color::is_hex(string hex_color) {
	if (hex_color.length() == 7 && hex_color[0] == '#') {
		for (unsigned int i = 1; i < hex_color.length(); ++i) {
			if (!isxdigit(hex_color[i])) {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}

unsigned char Color::string_to_hex(string& color, unsigned int position) {
	stringstream str;
	str << color.substr(position, 2);
	int result;
	str >> std::hex >> result;
	return unsigned char(result);
}

Color::Color(const Color& other) {
	red = other.red;
	green = other.green;
	blue = other.blue;
}

void Color::print_color() const {
	cout << "rgb(" << (int)red << ", " << (int)green << ", " << (int)blue << ")" << endl;
}

Color Color::blend(const Color& other) {
	unsigned char _red = ((int(red) + int(other.red)) / 2);
	unsigned char _green = ((int(green) + int(other.green)) / 2);
	unsigned char _blue = ((int(blue) + int(other.blue)) / 2);
	return Color(_red, _green, _blue);
}

void Color::darken(float amount) {
	red = (int(red) * (1 - amount));
	green = (int(green) * (1 - amount));
	blue = (int(blue) * (1 - amount));
}

void Color::lighten(float amount) {
	if (is_greater_255(int(red) * (1 + amount))) {
		red = 255;
	}
	else {
		red = (int(red) * (1 + amount));
	}
	if (is_greater_255(int(green) * (1 + amount))) {
		green = 255;
	}
	else {
		green = (int(green) * (1 + amount));
	}
	if (is_greater_255(int(blue) * (1 + amount))) {
		blue = 255;
	}
	else {
		blue = (int(blue) * (1 + amount));
	}
}

bool Color::is_greater_255(float number) {
	if (number > 255) {
		return true;
	}
	else {
		return false;
	}
}

Color Color::operator+(const Color& other) {
	Color blended_color;
	blended_color = blend(other);
	return blended_color;
}

Color& Color::operator++() {
	this->lighten(0.1);
	return *this;
}

Color Color::operator++(int) {
	Color temp(*this);
	operator++();
	return temp;
}

Color Color::darken2(float amount) {
	red = (int(red) * (1 - amount));
	green = (int(green) * (1 - amount));
	blue = (int(blue) * (1 - amount));

	return Color(red, green, blue);
}

Color& Color::operator--() {
	Color darker_color;
	darker_color = darken2(0.2);
	return darker_color;
}

Color Color::operator--(int) {
	Color temp(*this);
	operator--();
	return temp;
}
