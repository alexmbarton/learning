// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator;
    int denominator;

    numerator = atoi(&fraction[0]);
    denominator = atoi(&fraction[2]);

    if (numerator != 1)
    {
        return numerator;
    }

    return 8 / denominator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // int n = atoi(note);
    int octave = note[strlen(note) - 1];

    // Reduce to actual int with a bit of ascii math
    octave -= 48;

    double freq = 0.0;

    // An opportunity to refactor this with Ascii math
    switch(note[0])
    {
        case 'C':
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D':
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E':
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F':
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G':
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default:
            return 0;
            break;
    }

    // Let's sort out the octaves
    if (octave > 4)
    {
        for(int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    } else if (octave < 4)
    {
        for(int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // Finally let's reduce for # / b
    if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    } else if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }

    freq = round(freq);

    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s,"") == 0)
    {
        return 1;
    }

    return 0;
}
