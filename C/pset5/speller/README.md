# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

The longest word in the dictionaryo

## According to its man page, what does `getrusage` do?

Gets resource usage

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

To compare the difference before and after an operation we care about

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Main first checks for CLAs and rejects the command if it doesn't match. The dictionary is optional, reverting to the large dictionary by default. The programme then loads in the dictionary, then loads in the text file to be tested.
The file loops through each Character in the text file (as an unsigned char cast to an int) until it reaches the end of the file / error.
If the char is an alpha append the char to the word (max length 45+1 - for the \0) and advances the index to make sure that the length of word than the length of the word to stop a segmentation fault. If it it too long then
it consumes the rest of the chars and resets the index to zero.
If the word is a digit, then consume chars and set index to zero.

Now that we've found a word we need to null terminate the string (\0) and advance the words counter.
We check the word and a bool is returned.
If the word is mispelled then we print it out, reset the index and continue to the next char.

If there is an error, we close the file otherwise we close it properly.

We then get the size of the dictionary and unload it.

We then print out all the calculations of the programme.

Fin.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

We don't know the format of the file ahead of time, therefore it's better to run through the file unsigned char by unsigned char.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Because they should not mutate during the checking process.
