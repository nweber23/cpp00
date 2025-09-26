#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0), index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	std::string input;
	int ret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contacts[index].set_first_name(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contacts[index].set_last_name(input);
	std::cout << "Enter nick name: ";
	std::getline(std::cin, input);
	contacts[index].set_nick_name(input);
	while (1)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		ret = contacts[index].set_phonenumber(input);
		if (ret == 0)
			break;
		std::cout << "Invalid phone number. Please enter again." << std::endl;
	}
	if (size < 8)
		size++;
	index = (index + 1) % 8;
}

void PhoneBook::search_contact()
{
	if (size == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	auto format = [](const std::string &s)
	{
		if (s.length() > 10)
			return s.substr(0, 9) + ".";
		return s;
	};
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::string fn = format(contacts[i].get_first_name());
		std::string ln = format(contacts[i].get_last_name());
		std::string nn = format(contacts[i].get_nick_name());
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << fn << "|"
				  << std::setw(10) << ln << "|"
				  << std::setw(10) << nn << std::endl;
	}
	std::string input;
	std::cout << "Enter index to view details: ";
	if (!std::getline(std::cin, input) || input.empty())
	{
		std::cout << "No index entered." << std::endl;
		return;
	}
	int idx;
	try
	{
		size_t pos = 0;
		idx = std::stoi(input, &pos);
		if (pos != input.size())
			throw std::invalid_argument("bad");
	}
	catch (...)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (idx < 0 || idx >= size)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[idx].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[idx].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[idx].get_nick_name() << std::endl;
	std::cout << "Phone number: " << contacts[idx].get_phonenumber() << std::endl;
}
