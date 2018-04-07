# Grab input
input = int(raw_input("Int me: "))

# Write the output
if input % 2 == 0:
    if input % 3 == 0:
        print('Divisible by 2 and 3')
    else:
        print('Divisible by 2 and not by 3')
elif input % 3 == 0:
    print('Divisible by 3 and not by 2')
else:
    print('Not divisible by 2 nor 3')

x = 4 > 5 or 3 < 4 and 9 > 8

print(x)
