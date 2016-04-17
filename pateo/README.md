## Find The Longest Path

### Simple run
Windows: `solve.exe < input.txt`
Linux: `./solve.bin < input.txt`

### Description
Choose menu: (1: pathFromRandomMatrix, 2: pathFromGivenMatrix, 0: exit)
- when 1.pathFromRandomMatrix is chosen
*insert dimension:* is showen and need to insert *N*.
And it shows random generated matrix like below
```
Choose menu: (1: pathFromRandomMatrix, 2: pathFromGivenMatrix, 0: exit) 1
insert dimension: 8

Matrix is generated in random
 14 46 51 27 47 45 59 35
 40 39 20 11 42 61 37 33
 29 28 49 18 60 22 41 52
 10  1  8  2  6 57 30 13
  9 44 56  4 32 15 21 55
 25 62 17  7 31 38 19 16
 53 26 34 48 63 58 64 50
  3 24 36 23 54 12  5 43

Longest Length: 2

Tracing:
39 - 40
```

- when 2.pathFromGivenMatrix is chosen
*insert dimension first* is showen and after that you need to insert matrix values (N x N).
Example can be seen like below.

```
Choose menu: (1: pathFromRandomMatrix, 2: pathFromGivenMatrix, 0: exit) 2
choose dimension first: 3

Please insert matrix values
ex)
 6 9 8
 4 5 7
 1 2 3

 6 9 8
 4 5 7
 1 2 3

Longest Length: 4
Tracing:
5 - 6 - 7 - 8
```

- when 0 is chosen program ends.


