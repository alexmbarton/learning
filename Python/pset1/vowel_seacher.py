str = input("Hit me with a string: ")

vowel_count = 0

vowels = ["a","e","i","o","u"]

for i in str:
    if i in vowels:
        vowel_count += 1

print(vowel_count)
