##Huffman Code Generator

A simple [Huffman Code](https://en.wikipedia.org/wiki/Huffman_coding) generator tool.

###Compiling
```
$ make
```

###Usage
```huffman``` takes the symbol-probability pairs for an application, and finds an optimal Huffman code for them:

```
# Sum of all the probabilities should be 1
$ bin/huffman <symbol1> <prob1> <symbol2> <prob2> ...

# Example:
$ bin/huffman a 0.1 b 0.2 c 0.6 d 0.06 e 0.04
Huffman Code:
(b, 01)
(c, 1)
(a, 001)
(d, 0001)
(e, 0000)
Average code length: 1.7
Entropy: 1.66805
Efficiency: 98.1203%
```

### License

[Apache v2.0](https://github.com/udeyrishi/huffman_code_gen/blob/master/LICENSE)