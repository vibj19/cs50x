from cs50 import get_string

text = get_string("Text: ")

NumS = 0
NumW = 1
NumL = 0

for i in range(len(text)):
    if text[i] == "." or text[i] == "!" or text[i] == "?":
        NumS += 1
    elif text[i].isalpha() == True:
        NumL += 1
    elif text[i].isspace() == True:
        NumW += 1


L = (NumL * 100) / NumW
S = (NumS * 100) / NumW

index = (0.0588 * L) - (0.296 * S) - 15.8
X = round(index)


if X >= 1 and X < 16:
    print(f"Grade {X}")
elif X < 1:
    print("Before Grade 1\n")
elif X > 16:
    print("Grade 16+\n")
