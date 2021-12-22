def playGame(goal):
    print("Welcome to the Number Guessing Game!")
    # goal = int(input("Please enter the target number："))
    min = 0
    max = 10

    while True:
        guess = showRange(min, max)
        if guess > goal:
            max = guess-1
        elif guess < goal:
            min = guess+1
        else:
            print("Bingo!")
            break


def showRange(min, max):
    return int(input(f"Please enter a number between {min} and {max}: "))


if __name__ == "__main__":
    playGame(5)
