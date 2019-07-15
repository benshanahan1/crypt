all:
	@echo "Make targets:"
	@echo "  build      Build program."
	@echo "  test       Build program and run tests."
	@echo "  install    Build program and add to PATH."
	@echo "  uninstall  Remove program from PATH."
	@echo "  clean      Remove build directory."

build:
	mkdir -p bin/
	gcc -Wall cli.c crypt.c -o bin/crypt

test:
	mkdir -p bin/
	gcc -Wall test_crypt.c crypt.c -o bin/test_crypt
	@echo ""
	@echo "=== Running tests ==="
	@./bin/test_crypt

install: build
	sudo cp ./bin/crypt /usr/local/bin

uninstall:
	sudo rm -f /usr/local/bin/crypt

clean:
	rm -rf bin/
