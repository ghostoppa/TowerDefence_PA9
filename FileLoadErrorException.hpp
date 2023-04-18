#pragma once

#include <stdexcept>
class FileLoadError : public std::runtime_error
{
public:
	FileLoadError() : runtime_error("Unable To open File") {};
};
