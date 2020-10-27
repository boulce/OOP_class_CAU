#include "inf_int.h"

ostream				&operator<<(ostream& out, const inf_int& a)
{
	int				idx;

	if (a.thesign == false)
		out << '-';
	idx = a.length - 1;
	while (idx >= 0)
	{
		out << a.digits[idx];
		idx--;
	}
	return (out);
}

void				inf_int::Minus(const char num, const unsigned int index)
{
	if (this->length < index)
	{
		if (!(this->digits = (char *)realloc(this->digits, index + 1)))
		{
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		this->length = index;
		this->digits[this->length] = '\0';
	}
	if (this->digits[index - 1] < '0')
		this->digits[index - 1] = '0';
	this->digits[index - 1] -= (num - '0');
	if (this->digits[index - 1] < '0')
	{
		this->digits[index - 1] += 10;
		Minus('1', index + 1);
	}
}

void				inf_int::Add(const char num, const unsigned int index)
{
	if (this->length < index)
	{
		if (!(this->digits = (char *)realloc(this->digits, index + 1)))
		{
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		this->length = index;
		this->digits[this->length] = '\0';
	}
	if (this->digits[index - 1] < '0')
		this->digits[index - 1] = '0';
	this->digits[index - 1] += (num - '0');
	if (this->digits[index - 1] > '9')
	{
		this->digits[index - 1] -= 10;
		Add('1', index + 1);
	}
}

void				inf_int::Mul(const char a, const char b, const unsigned int index)
{
	char			mul;
	if (this->length < index)
	{
		if (!(this->digits = (char *)realloc(this->digits, index + 1)))
		{
			cout << "Memory reallocation failed, the program will terminate." << endl;
			exit(0);
		}
		this->length = index;
		this->digits[this->length] = '0';
	}
	if (this->digits[index - 1] < '0')
		this->digits[index - 1] = '0';
	this->digits[index - 1] += (a - '0') * (b - '0');
	if (this->digits[index - 1] > '9')
	{
		mul = (this->digits[index - 1] - '0') / 10 + '0';
		this->digits[index - 1] = ((this->digits[index - 1] - '0') % 10) + '0';
		Add(mul, index + 1);
	}
}

inf_int				operator*(const inf_int &a, const inf_int &b)
{
	inf_int			temp;
	unsigned int	a_idx;
	unsigned int	b_idx;

	if (a.thesign != b.thesign)
		temp.thesign = false;
	else
		temp.thesign = true;
	a_idx = 0;
	while (a_idx < a.length)
	{
		b_idx = 0;
		while (b_idx < b.length)
		{
			temp.Mul(a.digits[a_idx], b.digits[b_idx], a_idx + b_idx + 1);
			b_idx++;
		}
		a_idx++;
	}
	return (temp);
}

inf_int				operator-(const inf_int &a, const inf_int &b)
{
	inf_int			big;
	inf_int			little;
	inf_int			temp;
	unsigned int	idx;

	if (a.thesign != b.thesign)
	{
		temp = b;
		temp.thesign =  b.thesign == true ? false : true;
		return (a + temp);
	}
	else
	{
		if (a == b)
			return (temp);
		else if (temp.absolute(a, b) == true)
		{
			big = a;
			little = b;
			temp.thesign = a.thesign;
		}
		else if (temp.absolute(a, b) == false)
		{
			big = b;
			little = a;
			temp.thesign = !(b.thesign);
		}
		idx = 0;
		while (idx < big.length)
		{
			temp.Add(big.digits[idx], idx + 1);
			idx++;
		}
		idx = 0;
		while (idx < little.length)
		{
			temp.Minus(little.digits[idx], idx + 1);
			idx++;
		}
		idx = 0;
		while (temp.digits[idx] == '0')
			idx++;
		temp.digits = temp.digits + idx;
		return (temp);
	}
}

inf_int				operator+(const inf_int &a, const inf_int &b)
{
	inf_int			temp;
	unsigned int	idx;

	if (a.thesign == b.thesign)
	{
		idx = 0;
		while (idx < a.length)
		{
			temp.Add(a.digits[idx], idx + 1);
			idx++;
		}
		idx = 0;
		while (idx < b.length)
		{
			temp.Add(b.digits[idx], idx + 1);
			idx++;
		}
		temp.thesign = a.thesign;
		return (temp);
	}
	else
	{
		temp = b;
		temp.thesign = a.thesign;
		return (a - temp);
	}
}

bool				inf_int::absolute(inf_int a, inf_int b)
{
	int				idx;

	idx = 0;
	if (a.length > b.length)
			return (true);
	else if (a.length < b.length)
			return (false);
	else if (a.length == b.length)
	{
		idx = a.length;
		while (idx > 0)
		{
			if (a.digits[idx - 1] > b.digits[idx - 1])
				return (true);
			else if (a.digits[idx - 1] < b.digits[idx - 1])
				return (false);
			else
				idx--;
		}
	}
	return (false);
}

bool				operator<(const inf_int &a, const inf_int &b)
{
	if (operator>(a,b) || operator==(a,b))
		return (false);
	else
		return (true);
}

bool				operator>(const inf_int &a, const inf_int &b)
{
	int				idx;

	if (a.thesign == true && b.thesign == false)
		return (true);
	else if (a.thesign == false && b.thesign == true)
		return (false);
	if (a.length > b.length)
	{
		if (a.thesign == true)
			return (true);
		else if (a.thesign == false)
			return (false);
	}
	else if (a.length < b.length)
	{
		if (a.thesign == true)
			return (false);
		else if (a.thesign == false)
			return (true);
	}
	else if (a.length == b.length)
	{
		idx = a.length;
		while (idx > 0)
		{
			if (a.digits[idx - 1] > b.digits[idx - 1])
				return (true);
			else if (a.digits[idx - 1] < b.digits[idx - 1])
				return (false);
			else
				idx--;
		}
	}
	return (false);
}

bool				operator!=(const inf_int &a, const inf_int &b)
{
	return (!operator==(a,b));
}

bool				operator==(const inf_int &a, const inf_int &b)
{
	if ((strcmp(a.digits, b.digits) == 0) && (a.thesign == b.thesign))
		return (true);
	return (false);
}

inf_int				&inf_int::operator=(const inf_int &a)
{
	if (this->digits)
		delete (this->digits);
	this->digits = new char[a.length + 1];
	strcpy(this->digits, a.digits);
	this->length = a.length;
	this->thesign = a.thesign;
	return (*this);
}

inf_int::~inf_int()
{
	delete (digits);
}

inf_int::inf_int(const inf_int &a)
{
	this->digits = new char[a.length + 1];
	strcpy(this->digits, a.digits);
	this->length = a.length;
	this->thesign = a.thesign;
}

inf_int::inf_int(const char *str)
{
	int				len;
	int				start;
	int				idx;
	char			*buf;

	start = 0;
	if (str[0] == '-')
	{
		this->thesign = false;
		start = 1;
	}
	else
		this->thesign = true;
	len = 0;
	while (str[len])
		len++;
	if (!(buf = (char *)malloc(sizeof(char) * (len - start + 1))))
	{
		cout << "Memory allocate failed, the program will terminate." << endl;
		exit(0);
	}
	idx = 0;
	len--;
	while (len >= start)
	{
		buf[idx] = str[len];
		len--;
		idx++;
	}
	buf[idx] = '\0';
	this->length = idx;
	this->digits = new char[idx + 1];
	strlcpy(this->digits, buf, idx + 1);
	idx = -1;
}

inf_int::inf_int(int n)
{
	char			buf[100];
	int				i;

	if (n < 0)
	{
		this->thesign = false;
		n *= (-1);
	}
	else
		this->thesign = true;
	i = 0;
	while (n > 0)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (i == 0)
		new (this)inf_int();
	else
	{
		buf[i] = '\0';
		this->length = i;
		this->digits = new char[i + 1];
		strcpy(this->digits, buf);
	}
}

inf_int::inf_int()
{
	this->digits = new (char[2]);
	this->digits[0] = '0';
	this->digits[1] = '\0';
	this->length = 1;
	this->thesign = true;
}

// int			main(void)
// {
// 	inf_int		a("2014");
// 	inf_int		b("5263");
// 	inf_int		c;

// 	c = a * b;
// 	cout << c << endl;
// }
