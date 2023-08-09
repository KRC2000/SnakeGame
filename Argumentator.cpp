// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#include "Argumentator.hpp"

bool Argumentator::getIntValue(int args_amount, char ** arguments, std::string key, int & value, bool quiet)
{
	bool keyFound = false;

	for (int i = 0; i < args_amount; i++)
	{
		if (arguments[i] == key)
		{
			keyFound = true;
			if (args_amount-1 > i)
			{
				std::string arg_str(arguments[i+1]);
				try
				{
					value = stoi(arg_str);
				}
				catch(const std::invalid_argument& e)
				{
					printf("Can't convert \"%s\" to integer\n", arg_str.c_str());
				}
				return true;
			}
			else
			{
				printf("No value found after \"%s\" key\n", key.c_str());
			}
		}
	}

	if (!keyFound && !quiet)
	{
		printf("No parameter key \"%s\" found\n", key.c_str());
	}

	return false;
}

bool Argumentator::getFloatValue(int args_amount, char ** arguments, std::string key, float & value, bool quiet)
{
	bool keyFound = false;

	for (int i = 0; i < args_amount; i++)
	{
		if (arguments[i] == key)
		{
			keyFound = true;
			if (args_amount-1 > i)
			{
				std::string arg_str(arguments[i+1]);
				try
				{
					value = stof(arg_str);
				}
				catch(const std::invalid_argument& e)
				{
					printf("Can't convert \"%s\" to integer\n", arg_str.c_str());
				}
				return true;
			}
			else
			{
				printf("No value found after \"%s\" key\n", key.c_str());
			}
		}
	}

	if (!keyFound && !quiet)
	{
		printf("No parameter key \"%s\" found\n", key.c_str());
	}

	return false;
}

