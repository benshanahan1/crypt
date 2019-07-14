# crypt
Very simple CLI to perform [XOR
encryption](https://en.wikipedia.org/wiki/XOR_cipher). Inspired by [Project
Euler problem 59](https://projecteuler.net/problem=59).

```bash
Usage: ./bin/crypt MODE KEY IN [OUT]

    MODE  (-e/-d) encrypt or decrypt
    KEY   encryption key
    IN    input file
    OUT   output file; required if `-f` flag set
```

Example usage:
```bash
# encrypt /path/to/input file
./bin/crypt -e <key> /path/to/input /path/to/output

# decrypt /path/to/output file
./bin/crypt -d <key> /path/to/output
```

## Build
Clone the repository, then run
```bash
make all
```
This command will build the `crypt` executable and place it in 'bin/'. It will then run all tests.
