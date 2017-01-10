#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>

class Color {
private:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
public:
	Color();
	Color(unsigned char, unsigned char, unsigned char);
	~Color();
	virtual unsigned char* get_red();
	virtual unsigned char* get_green();
	virtual unsigned char* get_blue();
	Color(std::string hex_color);
	Color(const Color& other);
	bool is_hex(std::string hex_color);
	unsigned char string_to_hex(std::string& color, unsigned int position);
	void print_color() const;
	Color blend(const Color& other);
	void darken(float amount);
	void lighten(float amount);
	bool is_greater_255(float number);
	Color operator+(const Color& other);
	Color& operator++();
	Color operator++(int);
	Color darken2(float amount);
	Color& operator--();
	Color operator--(int);
};
