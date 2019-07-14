#include "crypt.h"

#define BUFLEN 4096
#define ENCRYPT 0
#define DECRYPT 1


void print_usage() {
    printf("Usage: ./bin/crypt MODE KEY IN [OUT]\n");
    printf("\n");
    printf("    MODE  (-e/-d) encrypt or decrypt\n");
    printf("    KEY   encryption key\n");
    printf("    IN    input file\n");
    printf("    OUT   output file; required if `-f` flag set\n");
    exit(0);
}


int main(int nargc, char *argv[]) {
    // TODO: parse cmdline args

    // Check that key was provided.
    if (nargc < 4 || nargc > 5) {
        print_usage();
        exit(0);
    }

    // Get info from CLI args.
    char *key = argv[2];
    int mode = strcmp(argv[1], "-e") == 0 ? ENCRYPT : DECRYPT;
    char *in = argv[3];
    char *out = NULL;
    if (mode == ENCRYPT || nargc == 5) {
        out = argv[4];
    }
    if (mode == ENCRYPT && nargc != 5) {
        printf("Must include an OUTput filepath when encrypting.\n\n");
        print_usage();
        exit(0);
    }

    // Load message from input file.
    char msg[BUFLEN] = {0};
    FILE *f_in;
    if (mode == ENCRYPT) {
        printf("Read plain text.\n");
        f_in = fopen(in, "r");
    } else {
        printf("Read bytes.\n");
        f_in = fopen(in, "rb");
    }
    size_t msglen = fread(msg, 1, BUFLEN, f_in);
    fclose(f_in);

    // Run encryption/decryption and write to STDOUT.
    int keylen = strlen(key);
    char *crypted = crypt(msg, msglen, key, keylen);

    if (mode == ENCRYPT && out == NULL) {
        printf("ERROR: out file path is unexpectedly null.\n");
        exit(1);
    }

    if (out != NULL) {
        // Save bytes to output file.
        FILE *f_out;
        if (mode == ENCRYPT) {
            printf("Wrote bytes.\n");
            f_out = fopen(out, "wb");
        } else {
            printf("Wrote plain text.\n");
            f_out = fopen(out, "w");
        }
        fwrite(crypted, 1, msglen, f_out);
        fclose(f_out);
    } else {
        printf("Decrypted message:\n%s\n", crypted);
    }

    // Clean up.
    free(crypted);

    return 0;
}
