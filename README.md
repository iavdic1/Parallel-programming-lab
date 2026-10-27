Lab 4 - Assignment - fixed

I copied the Makefile and aosoa_measurement.cpp from GitHub.

In the cpp file I added:
    new[] for memory allocation
    R, G and B values using rand()
    delete[] to free memory

I also changed TARGET_SRC in Makefile.
Problems
At first the code didn’t compile because I had a mistake in the Makefile. I fixed the file name and then it worked.
Testing
I ran these commands in terminal:
make test_1K
make test_10K
make test_100K
make test_1M
make test_10M
All tests worked and results were saved in CSV files.
I tested different V values: 2, 4, 8, 16, 32, 64, 128 and 256.
Results:
    1K: fastest was V=64 (0.058708 ms)
    10K: fastest was V=128 (0.593114 ms)
    10M: fastest was V=32 (595.288 ms)

I noticed that bigger N takes more time. Also bigger V doesn’t always mean faster execution.
Graph

I put my results in Google Sheets and made a graph.

Google Sheets Results: https://docs.google.com/spreadsheets/d/1s6CYwvw5bS9B7MssV9my3gflXBFvGMcXTlzQI3sqEDw/edit?usp=sharing