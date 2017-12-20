#include "splitter.h"
bool Splitter::isSeparator(char token)
{
	auto m_sep_data = m_sep.data();
	auto sz = m_sep.size();
	for (auto index = 0; index < sz; ++index)
	{
		if ( m_sep_data[index] == token ) return true;
	}
	return false;
}
Splitter::Splitter(const char * separators)
{
	m_sep = std::string(separators);
}
std::vector<std::string>Splitter::split(std::string &rString)
{
	std::vector<std::string> strings;
	auto state = State::start;
	std::string sx; 
	for (auto it = rString.begin(); it != rString.end(); ++it)
	{
		auto token = *it; 
		if (state == State::start){
		
			state = isSeparator(token) ? State::sep : State::nosep;
		
		}
		if (state == State::sep){
		
			if (isSeparator(token)) /*then*/ continue;
			sx+=token;
			state = State::nosep;
		
		} else {
			
			if (!isSeparator(token)){ sx+=token; continue; }
			strings.push_back(sx);
			sx.clear();
			state = State::sep;
		
		}
	}
	if(!sx.empty()) strings.push_back(sx);
	return strings;
}
std::vector<std::string> Splitter::getlines(std::string&rString)
{
	Splitter s{"\n"};
	return s.split(rString);
}


















