#import <stdio.h>

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        fprintf(stderr,"Please enter the required arguments.\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");

    // Check that file exists
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // look for JPEG signal
    // 0xff 0xd8 0xff
    // Read 512 bytes
    // Is there an end signal?
    unsigned char buffer[512];
    FILE* picture = NULL;


    int jpegFound = 0;

    int fileCounter = 0;


    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0
            )
        {
            if (jpegFound == 1) {
                fclose(picture);
            } else {
                jpegFound = 1;
            }


            char filename[8];
            sprintf(filename, "%03d.jpg", fileCounter);
            picture = fopen(filename, "a");
            fileCounter++;

        }

        if (jpegFound == 1)
        {
            fwrite(buffer, 512, 1, picture);
        }
    }



    // close infile
    fclose(inptr);

    return 0;
}