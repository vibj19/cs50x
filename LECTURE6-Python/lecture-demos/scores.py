from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores = scores + [score]

print (f"Average: {sum(scores)/len(scores)}")
