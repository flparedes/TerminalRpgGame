#pragma once

#ifndef _OPTION_H_
#define _OPTION_H_

class Option
{
private:
	const char* text;
public:
	Option(const char* text = "");
	Option(const Option &opt);
	~Option();
	const char* getText() const;
};

#endif