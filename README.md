# N-Queen Problem

### Fining Solution for N-Queen Cs Problem Using OR-Tools

##### Here I have Used C++ for Solving Problem. There are N Variables with {1 .. N} Doamin, determining Row of the Queens. With this Formulation There is no Column Attack and also there are 3 Alldifferent Constraints for supporting Row Attacks and Diagonal Attacks. At last code returns row number of queen of each column and print a chess board with located Queens. 

###### for running code first download and install Google OR-Tools : https://developers.google.com/optimization/install

Open a command window at the top level of the directory where you installed OR-Tools, and enter:

```sh
$ make run SOURCE= relative path/ N-Queens.cc
```
This will Create executable file in bin directory. so for running:


```sh
$ cd bin
$ ./N-Queens
```