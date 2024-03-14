people = {
    "Carter": "111111111",
    "David": "222222222",
    "John": "333333333",
}

name = input("Name: ")

if name in people:
    number = people[name]
    print (f"Found {number}")

else:
    print("Not found")
