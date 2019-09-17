/* File:
 *	minunit.h
 *	Source code from www.jera./techinfo/jtns/jtn002.html
 *	(Title: JTN002 - MinUnit -- a minimal unit testing framework)
 */

#define MU_Assert(message, test) do { if (!(test)) return message; } while (0)
#define MU_Run_Test(test) do { char *message = test(); run_test++; \
	if (message) return message; } while (0)
extern int test_s_run;
