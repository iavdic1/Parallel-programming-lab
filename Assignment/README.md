# Assignment 8 - Ilda Avdic

## Results

I ran the program with 2, 4 and 8 processes. These are the results:

| Processes | Elements per process |     Total sum | Compute time (s) | Scatter time (s) | Reduce time (s) |
| --------- | -------------------: | ------------: | ---------------: | ---------------: | --------------: |
| 2         |                5,000 | 50,005,000.00 |         0.000016 |         0.000063 |        0.000014 |
| 4         |                2,500 | 50,005,000.00 |         0.000008 |         0.000109 |        0.000086 |
| 8         |                1,250 | 50,005,000.00 |         0.000004 |         0.000205 |        0.000135 |

_The times shown are from rank 0._

The expected sum is 50,005,000.00 and I got the correct result in all three tests.

## Code

I added the code for dividing the array between processes using `rank` and `nprocs`. Each process gets its part of the array.

I used `MPI_Allgather` to collect the sizes of all parts, and `MPI_Scatterv` to distribute the elements from rank 0 to other processes.

Each process then calculates its own sum. At the end, `MPI_Reduce` combines these sums into one final result on rank 0.

For memory management, rank 0 frees the main array, while every process frees its own local array.

## Screenshots

### 2 Processes

![2 processes](<screenshots/2 process.png>)

### 4 Processes

![4 processes](<screenshots/4 proces.png>)

### 8 Processes

![8 processes](<screenshots/8 proces.png>)

## My Thoughts

All three tests gave the same correct sum, so the program worked as expected.
When I increased the number of processes, each process had fewer elements to calculate. With 2 processes each one had 5,000 elements, while with 8 processes each one had only 1,250.
I also noticed that the computation time for rank 0 became smaller when using more processes. Also the scatter and reduce times increased. Scatter took 0.000063 seconds with 2 processes and 0.000205 seconds with 8.
From these results, I can see that using more processes reduces the amount of work for each process, but it also requires more communication between them. Since the array is not very large, adding more processes does not necessarily make the whole program faster.
