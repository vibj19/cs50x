def main():
    height = get_height()
    build(height)


def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if height > 0 and height < 9:
                break
        except ValueError:
            pass
    return height


def build(height):
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)


main()
