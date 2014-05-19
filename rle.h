#ifndef RLE_H

#define RLE_H

/**
 * Compress the in buffer to the out buffer.
 * The outlen argument should be at least x2 the inlen.
 *
 * @param in - input buffer
 * @param inlen - the length of the input buffer
 * @param out - the output buffer
 * @param outlen - the length of the output buffer
 * @return the size of the compressed data (number of out fields occupied by
 *         the compressed data)
 */
int RLECompress(unsigned char *in, int inlen, unsigned char *out, int outlen);


/**
 * Decompress the first outlen bytes of the in buffer to the out buffer.
 *
 * @param in - input buffer
 * @param inlen - the length of the input buffer
 * @param out - the output buffer
 * @param outlen - the length of the output buffer
 * @return the size of the decompressed data (number of out fields occupied by
 *         the decompressed data)
 */
int RLEDecompress(unsigned char *in, int inlen, unsigned char *out, int outlen);

#endif /* end of include guard: RLE_H */
