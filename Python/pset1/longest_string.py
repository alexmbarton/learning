# Find longest string where current letter > last_letter

s = 'azcbobobegghakl'

last_letter = '';
current_word = '';
longest_word = '';

for i in s:
    if i >= last_letter:
        current_word += i
        last_letter = i
        if len(current_word) > len(longest_word):
            longest_word = current_word

    else:
        last_letter = i
        current_word = i
    
print("Longest substring in alphabetical order is:",longest_word)
