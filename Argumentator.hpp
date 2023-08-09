// SPDX-FileCopyrightText: 2023 <copyright holder> <email>
// SPDX-License-Identifier: MIT

#ifndef ARGUMENTATOR_H
#define ARGUMENTATOR_H

#include <string>
#include <stdexcept>

/**
 * @todo write docs
 */
class Argumentator
{
public:
	static bool getIntValue(int args_amount, char** arguments, std::string key, int & value, bool quiet = true);
	static bool getFloatValue(int args_amount, char** arguments, std::string key, float & value, bool quiet = true);
};

#endif // ARGUMENTATOR_H
