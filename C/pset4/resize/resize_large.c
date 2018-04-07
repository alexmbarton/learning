#import <stdio.h>
#import <stdlib.h>

#import "bmp.h"

int main(int argc, char *argv [])
{
    ////////////////////////////
    // Check command line args
    ////////////////////////////

    if (argc != 4)
    {
        fprintf(stderr,"Please enter the correct args! Multiplyer, inFile, outFile\n");
        return 1;
    }

    if (atof(argv[1]) < 0.0 && atof(argv[1]) > 100.0)
    {
        fprintf(stderr,"Please enter a resize value between 1 & 100.\n");
        return 1;
    }

    ////////////////////
    // Collect inputs
    ////////////////////

    char *infile = argv[2];
    char *outfile = argv[3];
    float resizeMultiple = atof(argv[1]);


    ////////////////
    // Test file
    ////////////////

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");

    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    printf("Resize Variable: %f\n", resizeMultiple);

}