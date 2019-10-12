# crypt
Very simple CLI to perform [XOR
encryption](https://en.wikipedia.org/wiki/XOR_cipher). Inspired by [Project
Euler problem 59](https://projecteuler.net/problem=59).

```txt
Usage: crypt MODE KEY IN [OUT]

Crypt uses a very simple XOR encryption. As a result, the longer the encryption key, the more secure the encryption.

    MODE  (-e/-d) encrypt or decrypt
    KEY   encryption key
    IN    input file
    OUT   output file; required if encrypting file
```

Example usage:
```bash
# encrypt /path/to/input file
crypt -e <key> /path/to/input /path/to/output

# decrypt /path/to/output file
crypt -d <key> /path/to/output
```

## Build / Install
To build and install `crypt` into '/usr/local/bin', where it will be available on your system PATH, run:
```bash
make install
```

You can also use `crypt` without installing it into the system path using:
```bash
make build
```
An executable is placed in the 'bin/' folder of the repo.

### Run tests
To run tests:
```bash
make test
```
