librle
====

A simple RLE implementation without any external dependencies.

Usage example
-------------

    int inputSize = 10;
    unsigned char *input = NULL;
    unsigned char *output = NULL;

    input = calloc(inputSize, sizeof(*input));
    output = calloc(inputSize * 2, sizeof(*output));

    if(input == NULL || output == NULL) {
      perror("Memory allocation error");
      exit(EXIT_FAILURE);
    }

    input[5] = 1;
    input[6] = 1;

    /* The size of the output buffer should be at lest x2
       the size of the input buffer. */
    RLECompress(input, inputSize, output, inputSize * 2);

    RLEDecompress(output, inputSize * 2, input, inputSize);

    free(input);
    free(output);
    exit(EXIT_SUCCESS);
