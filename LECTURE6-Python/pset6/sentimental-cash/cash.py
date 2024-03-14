from cs50 import get_float

while True:
    try:
        change = get_float("Change: ")
        if change > 0:
            break
    except ValueError:
        pass

cents = round(100 * change)

count = 0

while cents > 0:
    if cents >= 25:
        cents -= 25
        count += 1
    elif cents >= 10:
        cents -= 10
        count += 1
    elif cents >= 5:
        cents -= 5
        count += 1
    else:
        cents -= 1
        count += 1

print(count)
