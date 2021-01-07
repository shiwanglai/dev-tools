#include <stdio.h>

static int foo_count;
static int goo_count;
static int hoo_count;

void hoo()
{
	for (int i = 0; i < 100000; i++) {
		hoo_count++;
	}
}

void goo()
{
	for (int i = 0; i < 10000000; i++) {
		goo_count++;
	}

	for (int i = 0; i < 1000; i++) {
		goo_count++;
		hoo();
	}
}

void foo()
{
	for (int i = 0; i < 10; i++) {
		foo_count++;
		goo();
	}
}

int main()
{
	foo();
	goo();
	printf("%d %d %d\n", foo_count, goo_count, hoo_count);

	return 0;
}

