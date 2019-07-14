#include "crypt.h"
#include "test_crypt.h"


/** Test repeat function. */
int test_repeat() {
    int rv = 0;

    char *x = repeat("ben", 3, 10);
    if (strcmp("benbenbenb", x) != 0) {
        printf("ERROR: %s not equal to benbenbenb.\n", x);
        rv ++;
    }
    free(x);

    x = repeat("testing", 7, 7);
    if (strcmp("testing", x) != 0) {
        printf("ERROR: %s not equal to testing.\n", x);
        rv ++;
    }
    free(x);
   
    x = repeat("longertexthere", 14, 10);
    if (strcmp("longertext", x) != 0) {
        printf("ERROR: %s not equal to longertext.", x);
        rv ++;
    }
    free(x);

    return rv;
}


/** Test crypt function in both direction (encrypt/decrypt). */
int test_crypt() {
    int rv = 0;
    char *msg = "hello, ߐ!";
    int msglen = strlen(msg);
    char *key = "abcde";
    int keylen = strlen(key);
    char *expect = "\x09\x07\x0f\x08\x0a\x4d\x42\xffffffbc\xfffffff4\x44";
    char *encrypted = crypt(msg, msglen, key, keylen);
    char *decrypted = crypt(encrypted, msglen, key, keylen);
    if (strcmp(expect, encrypted) != 0) {
        printf("ERROR:\n");
        print_bytes(encrypted, msglen);
        printf("not equal to\n");
        print_bytes(expect, msglen);
        rv ++;
    }
    if (strcmp(msg, decrypted) != 0) {
        printf("ERROR: %s not equal to %s\n", decrypted, msg);
        rv ++;
    }
    free(encrypted);
    free(decrypted);
    return rv;
}


int main(int argc, char *argv[]) {
    int rv = 0;
    rv += test_repeat();
    rv += test_crypt();
    if (rv == 0) {
        printf("All tests passed.\n");
    }
    return rv;
}
