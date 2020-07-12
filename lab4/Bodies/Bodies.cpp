#include "Interface.h"

int main()
{
	vector<shared_ptr<CBody>> bodies;
	BodyController(bodies, cin, cout);
	return 0;
}