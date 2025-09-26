#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

class Contact
{
	public:
	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nick_name() const;
	std::string	get_phonenumber() const;
	std::string	get_darkest_secret() const;
	int			set_phonenumber(std::string str);
	void		set_first_name(std::string str);
	void		set_last_name(std::string str);
	void		set_nick_name(std::string str);
	void		set_darkest_secret(std::string str);
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phonenumber;
	std::string	darkest_secret;
};

#endif