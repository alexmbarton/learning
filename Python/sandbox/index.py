
min = 0
max = 100
ans = (max+min) / 2.0
guide = 'a'

print("Please think of a number between 0 and 100: ")

while True:
    print('Is your secret number ' + str(ans) +'?')
    guide = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly. ")

    if guide == 'h':
        max = ans
    elif guide == 'l':
        min = ans
    elif guide == 'c':
        break;
    else:
        print("Sorry, I did not understand your input.")
        continue

    ans = (max+min) // 2.0

print ("Game over. Your secret number was: " + str(ans))
