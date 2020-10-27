#include "greeter.h"

Greeter::Greeter()
{
	this->opt = 0;
}

void			Greeter::showTitle()
{

}

void			Greeter::get_result(inf_int a, char opt, inf_int b)
{
	inf_int		result;

	if (opt == '+')
		result = a + b;
	else if (opt == '-')
		result = a - b;
	else if (opt == '*')
		result = a * b;
	else
	{
		cout << "wrong input..." << endl;
	}
	cout << "result : " << result << endl;
}

void			Greeter::showInputMenu()
{
	while (true)
	{
		string		input;
		char		buffer[4096];
		string		str[4096];
		int			idx;

		system("clear");
		showTitle();
		cout << "press [0] to Exit" << endl;
		cout << "Input : [number] [operator] [number]" << endl;
		cout << "Input : " << flush;
		getline(std::cin, input);
		if (input == "0")
		{
			cout << "Exit Program ...." << endl;
			return ;
		}
		else
		{
			strcpy(buffer, input.c_str());
			char *tok = strtok(buffer, " ");
			idx = 0;
			while (tok != nullptr)
			{
				str[idx] = string(tok);
				tok = strtok(nullptr, " ");
				idx++;
			}
			if (idx != 3)
			{
				cout << "wrong input..." << endl;
				break;
			}
			strcpy(buffer, str[0].c_str());
			inf_int temp_a(buffer);
			this->a = temp_a;

			if (str[1].size() != 1)
			{
				cout << "wrong input..." << endl;
				break;
			}
			strcpy(buffer, str[1].c_str());
			this->opt = buffer[0];

			strcpy(buffer, str[2].c_str());
			inf_int temp_b(buffer);
			this->b = temp_b;

			get_result(this->a, this->opt, this->b);
		}
		cin.ignore();
		cin.clear();
	}
	return ;
}

// bool			Greeter::get_b(string input)
// {

// }
