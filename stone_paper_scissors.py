import random
import shutil

def play(l):
    comp_score=0
    yr_score=0
    while True:
        yr_choice= int(input())
        if yr_choice in l:
            comp_choice=random.choice([1,2,3])
            print("you: " , yr_choice ,"-> " , l[yr_choice])
            print("computer: ",comp_choice ,"-> " , l[comp_choice])
        
            if yr_choice == comp_choice:
                pass
            elif (yr_choice == 1 and comp_choice == 3) or (yr_choice == 3 and comp_choice == 2) or (yr_choice == 2 and comp_choice ==1):
                yr_score+=1
            elif (yr_choice == 3 and comp_choice == 1) or (yr_choice == 2 and comp_choice == 3) or (yr_choice == 1 and comp_choice == 2):
                comp_score+=1

            print("current score--> computer: ",comp_score ," | " , yr_score , ": you")
            print()
        elif yr_choice == "":
            break
        else:
            print()
            print("Game Ended")
            break
    return comp_score , yr_score

l=shutil.get_terminal_size().columns
print("WELCOME TO STONE PAPER SCISSOR".center(l))
print("1.stone  2.paper  3.scissor" .center(l))
print("Press any other key to stop" .center(l))
print("ENTER to Begin" .center(l))
l= {1:"stone" , 2: "paper" , 3: "scissor"}

comp_score ,yr_score = play(l)

if comp_score > yr_score:
    print("COMPUTER WON")
elif comp_score < yr_score:
    print("YOU WON")
else:
    print("DRAW")
print("Final score: computer: ",comp_score ," | " , yr_score , ": you")
