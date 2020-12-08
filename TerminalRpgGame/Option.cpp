#include "Option.h"
#include <string.h>
#include <iostream>

using namespace std;


Option::Option(const char* text)
{
	this->text = _strdup(text);
}


Option::Option(const Option &opt)
{
	this->text = _strdup(opt.text);
}


Option::~Option()
{
	delete[] text;
}

const char* Option::getText() const {
	return this->text;
}

ostream& operator<<(ostream &os, const Option &opt) {
	os << opt.getText();
	return os;
}