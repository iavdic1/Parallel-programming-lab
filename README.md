for this assignment I used Example_03 and tested three different versions of timestep code.

I compiled and ran each version and checked the results with LIKWID. All three gave the same result, 0.016964, but the performance was different.

Opt1 had 145 MFLOP/s, opt2 had 204 MFLOP/s and opt3 had 199 MFLOP/s.

Then I added two extra flags to opt3 (-fno-trapping-math and -fno-math-errno). After that, I got around 270 MFLOP/s and almost 100% vectorization.

So from my results, opt3 with the extra flags worked the best.