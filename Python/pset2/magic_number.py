min = 0
max = 100
ans = (max+min) / 2.0
guide = 'a'

("Please think of a number between 0 and 100: ")

while True:
    print('Is your secret number ' + str(ans) +'?')
    guide = str(raw_input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly. "))

    if guide == 'h':
        max = ans
    elif guide == 'l':
        min = ans
    elif guide == 'c':
        break;

    ans = (max+min) / 2.0

print ("Game over. Your secret number was: " + str(ans))


low = 0
high = 100
guess = (low + high)/2
ans = 'a'

print ("Please think of a number between 0 and 100!")
while ans != 'c':
    print ("Is your secret number", int(guess), "?")
    ans = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly: " )
    if ans == 'h':
            high = guess
    elif ans == 'l':
            low = guess
    elif ans == 'c':
        break
    else:
        print ("Sorry, I did not understand your input.")
    guess = (low + high)/2
print ("Game over. Your secret number was:", int(guess))
