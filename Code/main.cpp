#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
#ifdef RUNNABLE_PROBLEM
	run();
#endif // RUNNABLE_PROBLEM

	
	return 0;
}
