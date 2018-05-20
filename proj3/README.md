# CPSC 221 - Eleanor Wong 32507121 k1w8 | Programming Project 3
To compile this project, run `make`
To run a generator, run the following code:

`./gen# n | ./dict_runner - 10 . -mys01 -mys02 -mys03`

Time to complete: 8 hours

This project is an implementation of multiple dictionary operation generators in order to identify seven different mystery dictionaries. The following dictionaries and their characteristics are listed below:

mtf - unsorted link list with move to front on find
	insert -> o(1)
	remove -> o(n)
	find -> o(n)

sl - sorted vector
	insert -> log(n) + n
	find -> o(logn)

hch - hash table with chaining (fixed size 10000)
	insert -> o(1)
	remove -> o(1)
	find -> o(1)

hqp - hash table with double hashing
	insert -> o(1)
	remove -> o(1)
	find -> o(1)

bstT - binary search tree with tombstones
	insert -> o(logn)
	remove -> o(logn)
	find -> o(logn)

avl tree
	insert -> o(logn)
	remove -> o(logn)
	find -> o(logn)

splay tree
	insert -> o(logn)
	remove -> o(logn)
	find -> o(logn) FIND MOVES TO TOP

## Relevant Files
* generator0.cc - generator that inserts n values in the dictionary in rising order
* generator1.cc - generator that inserts n/3 values, finds n/3 values then removes n/3 values in rising order
* generator2.cc - generator that inserts n/2 values in order then tries to find all n/2 values but in reverse order
* generator3.cc - generator that inserts n/2 values in order then tries to find 1, the first inserted values n/2 times
* generator4.cc - generator that inserts odd numbers, then even numbers, then finds a number in the middle
