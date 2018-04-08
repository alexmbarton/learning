str = input("Hit me with some Bobs: ")

bob_count = 0
n = 0

while n+2 < len(s):
    if s[n] + s[n + 1] + s[n + 2] == 'bob':
        bob_count += 1
    n +=1

print(bob_count)
