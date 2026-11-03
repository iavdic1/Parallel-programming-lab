I copied main.c, sum_algorithms.c, sum_algorithms.h and Makefile. Added the missing functions in sum_algorithms.c. Changed main.c to test all methods. Fixed some errors in the code and Makefile.
Used make to compile and ./sum_test to run. Saved results in results.txt and took a screenshot.
Made a Google Sheets table.

Results explanation:
Normal double had the biggest error. Long double was better because it has more precision. Pairwise sums numbers in pairs, and Kahan and Knuth use corrections to make the result more accurate.

For my test, Pairwise, Kahan and Knuth showed 0 error, but they took a bit more time.


Google Sheets:
https://docs.google.com/spreadsheets/d/1DpfYlaFc52XenozEofSm6Iyu7e23vl4vFwucsevFobA/edit?usp=sharing
