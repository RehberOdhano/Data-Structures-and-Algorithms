from collections import deque

d = deque()
for i in range(1, 6):
    d.append(i)

print(d)
rightmost_element = d.pop()
print(f"removed rightmost element: {rightmost_element}")
print(d)

leftmost_element = d.popleft()
print(f"removed leftmost element: {leftmost_element}")
print(d)

d.extend([1, 2])
print(d)

d.extendleft([5,6])
print(d)

print("clearing/removing all the elements from deque")
d.clear()
print(d)

print("creating a new deque")
[d.append(i) for i in range(1,6)]
print(d)

print("reversing the deque")
d.reverse()
print(d)

print("rotating the deque by k elements")
d.rotate(1) # rotating the deque by 1 element to the right
print(d)
d.rotate(-1) # rotating the deque by 1 element to the left (because the value is negative)
print(d)