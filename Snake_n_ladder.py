import random

def play():
    print("Enter any no. from 1 to 6 to roll dice and any other key to stop the game")
    score=0
    while True:
        print()
        c=input()
        if c in "123456":
            d=random.choice(dice)
            if score+int(d) <= 100:
                score+=int(d)
            else:
                print ("try again")

            print("dice value: ",d)
            if score <100:
                if score == 6:
                    print(score," you got a ladder")
                    score =27
                if score == 18:
                    print(score," you got a ladder")
                    score =49
                if score ==55:
                    print(score," you got a ladder")
                    score=77
                if score ==62:
                    print(score," you got a ladder")
                    score=98
                if score==99:
                    print(score," Snake got you")
                    score =35
                if score == 72:
                    print(score," Snake got you")
                    score =14
                if score ==61:
                    print(score," Snake got you")
                    score =25
                if score ==50:
                    print(score," Snake got you")
                    score= 41

                print("your current score: ", score)
                
                    
            if score == 100:
                print("your current score: ", score)
                return score
        else:
            print("Game ended")
            break
    return score        


dice=[1,2,3,4,5,6]
score=0
print("WELCOME TO SNAKE AND LADDER GAME")
print()
while True:
    print("Enter any no.from 1 to 6 to roll dice")
    x=input()
    if x in "123456":
        d=random.choice(dice)
        print("dice value: ", d)
        if d == 6:
            print()
            print("You got 6 you can begin the game now")
            print()
            score = play()
            break
        else:
            print("Try again to get 6")

    else:
        print("game ended")
        break
    print()
if score == 100:
    print()
    print("CONGRATS You finished the game")
    