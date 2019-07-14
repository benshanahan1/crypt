/** Crypt
 *
 * Very simple CLI to perform XOR encryption and decryption. Inspired by problem 59 of Project Euler (https://projecteuler.net).
 */

#include "crypt.h"


/** Repeat key to length of full message.
 *
 * Note: this function allocates memory, be sure to free the returned result
 * when finished.
 *
 * @param char *key: Encryption key.
 * @param int keylen: Key length.
 * @param int msglen: Message length.
 */
char *repeat(char *key, int keylen, int msglen) {
    char *rv = malloc(sizeof(char) * msglen);
    if (msglen <= keylen) {
        // Key is either same length or longer than message. In either case,
        // just copy the key into allocated memory up to message length.
        strncpy(rv, key, msglen);
    } else {
        // Key is shorter than message. We need to repeat the key's characters
        // until we reach the same length as the message.
        int n_repeats = msglen / keylen;
        int remainder = msglen % keylen;
        // Copy key into rv n_repeats times.
        for (int r = 0; r < n_repeats; r++) {
            int i = r * keylen;
            strncpy(&rv[i], key, keylen);
        }
        // Add remainder letters of key to rv.
        strncpy(&rv[msglen - remainder], key, remainder);
    }
    return rv;
}



/** XOR encrypt/decrypt message with key.
 *
 * Since XOR restores the original text when the same key is used on the
 * encrypted text, we only need to define a single encryption function.
 *
 * NOTE: Be sure to free the pointer returned by this function when you're
 * finished with it.
 *
 * @param char *msg: Message to encrypt.
 * @param int msglen: Message length.
 * @param char *key: Encryption key.
 * @param int keylen: Key length.
 */
char *crypt(char *msg, int msglen, char *key, int keylen) {
    // Create full key.
    char *full_key = repeat(key, keylen, msglen);
    char *rv = malloc(sizeof(char) * msglen);
    // Apply XOR.
    for (int i = 0; i < msglen; i ++) {
        rv[i] = msg[i] ^ full_key[i];
    }
    // Clean up.
    free(full_key);
    return rv;
}


/** Print raw bytes. */
void print_bytes(char *str, int length) {
    for (int i = 0; i < length; i ++) {
        printf("\\x%02x", str[i]);
    }
    printf("\n");
}


/** File path exists and is readable. */
int file_exists(char *path) {
    int exists = access(path, F_OK);
    int readable = access(path, R_OK);
    return (exists != -1 && readable != -1) ? 0 : -1;
}
