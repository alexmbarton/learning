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

    ///////////////
    // Read Headers
    ///////////////


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;

    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    ///////////
    // Copies
    ///////////

    // create an address to a memory locaiton
    int *origonalHeight = malloc(sizeof(long));
    int *origonalWidth = malloc(sizeof(long));
    int *origonalPadding = malloc(sizeof(int));

    // Allocate the memory location with the current height
    *origonalHeight = bi.biHeight;
    *origonalWidth = bi.biWidth;
    *origonalPadding = (4 - (*origonalWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    ///////////
    // Headers
    ///////////

    // Simple multiples
    bi.biWidth *= resizeMultiple;
    bi.biHeight *= resizeMultiple;

    // // Padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // // Create biSizeImage
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);

    // // Create bf
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    ///////////
    // Image
    ///////////

    // Resize variable
    int resizeVariable;
    if (resizeMultiple < 1.0)
    {
        int subMultiple = 1 / resizeMultiple;

        resizeVariable = *origonalWidth * resizeMultiple;

        // 12 lines -> 6 lines
        for (int i = 0, biHeight = abs(*origonalHeight); i < biHeight; i++)
        {
            if(i % subMultiple == 0)
            {
                // loop over the initial file in terms of width
                for (int j = 0; j < *origonalWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


                    if(j % subMultiple == 0)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }

                // skip over padding, if any
                fseek(inptr, *origonalPadding, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int l = 0; l < padding; l++)
                {
                    fputc(0x00, outptr);
                }
            }
            else
            {
                // Skip extra rows
                fseek(inptr, (*origonalWidth * sizeof(RGBTRIPLE)) + *origonalPadding, SEEK_CUR);
            }
        }
    }
    else
    {
        // iterate over infile's scanlines

    for (int i = 0, biHeight = abs(*origonalHeight); i < biHeight; i++)
    {

        for (int v = 0; v < resizeMultiple-1; v++)
        {
            // Iterate of the row
            for (int j = 0; j < *origonalWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // Iterate over it n times
                for (int k = 0; k < resizeMultiple; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // then add it back (to demonstrate how)
            for (int l = 0; l < padding; l++)
            {
                fputc(0x00, outptr);
            }

            fseek(inptr,-(sizeof(RGBTRIPLE) * *origonalWidth), SEEK_CUR);
        }

        // Iterate of the row
        for (int j = 0; j < *origonalWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


            // Iterate over it n times
            for (int k = 0; k < resizeMultiple; k++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, *origonalPadding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int l = 0; l < padding; l++)
        {
            fputc(0x00, outptr);
        }
    }


    }



    ////////////////
    // Free Memory
    ////////////////

    // Free the origonal height
    free(origonalHeight);
    free(origonalWidth);
    free(origonalPadding);

    ////////////////////////
    // Close up and complete
    ////////////////////////

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}