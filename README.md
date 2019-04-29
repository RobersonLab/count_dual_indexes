# count_dual_indexes
C++ program to take the FASTQ files for two indexes and count the index pairs. Could be useful if you don't get the expected ratio of counts for demultiplexing or have other issues with the pair content of your output. Relatively speedy.

## Installation
Requires Makefile and a g++ compiler capable of using the C++11 standard.

```bash
make
```

This will compile the count_dual_indexes program, which can be copied to your user path for standard usage.

## Example usage
Standard FASTQ files, minimum 1000 reads to print a pair, print to standard out.
```bash
count_dual_indexes --index1 my_run_R2.fastq --index2 my_run_R3.fastq --threshold 1000
```

Standard FASTQ files, minimum 1000 reads to print a pair, print to file.
```bash
count_dual_indexes --index1 my_run_R2.fastq --index2 my_run_R3.fastq --threshold 1000 1>index_counts.tsv 2>errors.log
```

Bash environment, gzip FASTQ files (use process substitution), minimum 100,000 reads to print a pair, print to file. Run with no-hangup and in the background.
```bash
nohup count_dual_indexes --index1 <(gunzip -cd my_run_R2.fastq.gz) --index2 <(gunzip -cd my_run_R3.fastq.gz) --threshold 100000 1>index_counts.tsv 2>errors.log &
```
