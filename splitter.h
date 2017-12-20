#include <vector>
#include <string>
class Splitter
{
	std::string m_sep;
	bool isSeparator(char token);
	enum class State{
		start,
		sep,
		nosep
	};
public: 
	Splitter(const char * separators = " ");
	std::vector<std::string>split(std::string &rString);
	static std::vector<std::string> getlines(std::string&rString);
};
