#include "vecDemo.h"

using namespace std;

//initialization
vecDemo::vecDemo():vec_var(LEN)
{
	d_var[0] = 1.1;
	d_var[1] = 2.1;
	d_var[2] = 3.1;
	d_var[3] = 4.1;

	vec_var[0] = 1.1;
	vec_var[1] = 2.1;
	vec_var[2] = 3.1;
	vec_var[3] = 4.1;

	arr_var = { 1.1, 2.2, 3.4, 5.6 };
}


vecDemo::~vecDemo()
{
}

void vecDemo::printVar()
{
	using namespace std;
	cout << "double variable" << endl;
	cout << d_var[0] << endl << d_var[1] << endl << d_var[2] << endl << d_var[3] << endl << endl;
	cout << "vector variable" << endl;
	cout << vec_var[0] << endl << vec_var[1] << endl << vec_var[2] << endl << vec_var[3] << endl << endl;
	cout << "array variable" << endl;
	cout << arr_var[0] << endl << arr_var[1] << endl << arr_var[2] << endl << arr_var[3] << endl << endl;
}

int main()
{
	vecDemo vec;
	vec.printVar();
	cin.get();
	return 0;
}