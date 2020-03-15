#include "./presentation/ui.h"
#include "./infrastructure/test_lists.h"
#include "./business/test_services.h"

int main(int argc, char** argv)
{
	/*
	 * main loop holder
	 */
	RunAllListTests();
	RunAllServiceTests();
	RunUI();
	return 0;
}
