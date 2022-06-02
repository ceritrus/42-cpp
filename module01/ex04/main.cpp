#include <iostream>
#include <fstream>
#include <sstream>

int parsing (int argc, char **argv, std::ifstream* input, std::ofstream* output)
{
	if (argc > 4)
	{
		std::cerr << "Error: too namy parameters [" << argc - 1 << " > 3]" << std::endl;
		return 1;
	}
	if (argc < 4)
	{
		std::cerr << "Error: not enough parameters [" << argc - 1 << " < 3]" << std::endl;
		return 1;
	}
	std::string filename(argv[1]);
	input->open(filename.c_str());
	if (input->fail())
	{
		std::cerr << "Error: failed to open input file [" << filename << "]" << std::endl;
		return 1;
	}
	filename.append(".replace");
	output->open(filename.c_str());
	if (output->fail())
	{
		input->close();
		std::cerr << "Error: failed to open output file [" << filename << "]" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	std::ifstream input;
	std::ofstream output;
	
	if (parsing(argc, argv, &input, &output))
		return 1;
	std::stringstream buffer;
	buffer << input.rdbuf();
	std::string text(buffer.str());
	std::string search(argv[2]);
	std::string replace(argv[3]);
	int pos = 0;
	int prevpos = 0;
	while ((pos = text.find(search, prevpos)) != EOF)
	{
		output << text.substr(prevpos, pos - prevpos);
		output << replace;
		prevpos = pos + search.length();
	}
	output << text.substr(prevpos, text.length() - prevpos);
	input.close();
	output.close();
}

