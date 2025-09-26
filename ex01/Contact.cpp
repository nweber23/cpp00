#include "Contact.hpp"

std::string Contact::get_first_name() const
{
	return (this->first_name);
}

std::string Contact::get_last_name() const
{
	return (this->last_name);
}

std::string Contact::get_nick_name() const
{
	return (this->nick_name);
}

std::string Contact::get_phonenumber() const
{
	return (this->phonenumber);
}

std::string Contact::get_darkest_secret() const
{
	return (this->darkest_secret);
}

void Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void Contact::set_nick_name(std::string str)
{
	this->nick_name = str;
}

void Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

int Contact::set_phonenumber(std::string str)
{
	size_t i = 0;
	if (str[i] == '+')
		i++;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (-1);
	}
	this->phonenumber = str;
	return (0);
}
