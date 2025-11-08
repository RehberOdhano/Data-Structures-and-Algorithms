from collections import Counter

characters = "aaaabbbccccd"
counter = Counter(characters)
print(counter)
print(counter.most_common(1)[0][1])

nums = [1,1,1,6,8,2,1,2,2,6,8,8]
counter = Counter(nums)
print(counter)

nums = tuple(nums)
counter = Counter(nums)
print(counter)

