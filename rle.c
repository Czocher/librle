#include <stdio.h>
#include <stdlib.h>

int RLECompress(unsigned char *in, int inlen, unsigned char *out, int outlen) {
    unsigned char cur = 0;
    unsigned char count = 0;
    int inpos = 0;
    int outpos = 0;
    int i = 0;

    while(inpos < inlen && outpos < outlen) {
        cur = in[inpos];
        count = 1;

        for(i = inpos + 1; i < inlen; i++) {
            if(in[i] == cur) {
                count++;
                if(count == 255) {
                    break;
                }
            } else {
                break;
            }
        }

        inpos += count;
        out[outpos] = cur;
        out[outpos + 1] = count;
        outpos += 2;
    }
    return outpos;
}

int RLEDecompress(unsigned char *in, int inlen, unsigned char *out, int outlen) {
    unsigned char cur = 0;
    unsigned char count = 0;
    int inpos = 0;
    int outpos = 0;
    int i = 0;

    while(inpos < inlen && outpos < outlen) {
        cur = in[inpos];
        count = in[inpos + 1];

        for(i = 0; i < count; i++) {
            out[outpos + i] = cur;

            if(outpos + i >= outlen) {
                break;
            }
        }
        outpos += i;
        inpos += 2;
    }

    return outpos;
}
