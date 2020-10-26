#include "inf_int.h"

inf_int				operator-(const inf_int &a, const inf_int &b)
{
	inf_int			temp;
	unsigned int	idx;

	if (a.thesign != b.thesign)
	{
		temp.thesign =  a > b == true ? a.thesign : b.thesign;
		temp = b;
		return (a + temp);
	}
	else
	{
		idx = 0;
		while (idx < a.length)
		{
			temp.Add(a.digits[idx], idx + 1);
			idx++;
		}
		cout << temp.digits << endl;
		idx = 0;
		while (idx < b.length)
		{
			temp.Add(b.digits[idx], idx + 1);
			idx++;
		}
		temp.thesign = a.thesign;
		return (temp);
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
		cout << temp.digits << endl;
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
		return (b - temp);
	}
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
	if (a.thesign == true && b.thesign == false)
		return (true);
	else if (a.thesign == false && b.thesign == true)
		return (false);
	else if (strcmp(a.digits, b.digits) > 0)
	{
		if (a.thesign == true && b.thesign == true)
			return (true);
		else if (a.thesign == false && b.thesign == false)
			return (false);
	}
	else if (strcmp(a.digits, b.digits) < 0)
	{
		if (a.thesign == true && b.thesign == true)
			return (false);
		else if (a.thesign == false && b.thesign == false)
			return (true);
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

int				main(void)
{
	inf_int		a("517");
	inf_int		b("-83");
	inf_int		c = a - b;
}
