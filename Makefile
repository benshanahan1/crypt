all: build test

build:
	mkdir -p bin/
	gcc cli.c crypt.c -o bin/crypt

test:
	mkdir -p bin/
	gcc test_crypt.c crypt.c -o bin/test_crypt
	@echo ""
	@echo "=== Running tests ==="
	@./bin/test_crypt

clean:
	rm -rf bin/
