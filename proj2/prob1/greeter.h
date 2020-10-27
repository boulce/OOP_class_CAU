#ifndef _GREETER_H_
#define _GREETER_H_

#include "inf_int.h"

class			Greeter
{
private:
	inf_int		a;
	inf_int		b;
	char		opt;


public:
	Greeter();
	void		showTitle();
	void		showInputMenu();
	void		get_result(inf_int a, char opt, inf_int b);
};

#endif
