# =-=-=-=-=-=-=-=-=-=-=-=-=
# EETG3024 Lab 6
# Super Fun Adventure Game
# Corey Biluk | W0425561          
# January 29, 2021                
# =-=-=-=-=-=-=-=-=-=-=-=-=

# This is a very short text-based game.
# Audio files are being played by pygame.

## Updated Feb 2 -
## Mixed volume levels for audio
## Added shorter delay times for storyline for faster debuging

## MODULES
import time
import pygame.mixer

## Initialize mixer
pygame.mixer.init()                           

## SFX Audio Files and Volume Levels
wall = pygame.mixer.Sound('wall.wav')
pygame.mixer.Sound.set_volume(wall, 0.8)

hum = pygame.mixer.Sound('hum.wav')
pygame.mixer.Sound.set_volume(hum, 0.3)

whoosh = pygame.mixer.Sound('whoosh.wav')
pygame.mixer.Sound.set_volume(whoosh, 0.3)

morning = pygame.mixer.Sound('morning.wav')
pygame.mixer.Sound.set_volume(morning, 0.7)

floor = pygame.mixer.Sound('wall.wav')
pygame.mixer.Sound.set_volume(floor, 0.8)

fall = pygame.mixer.Sound('fall.wav')
pygame.mixer.Sound.set_volume(fall, 0.7)

splat = pygame.mixer.Sound('splat.wav')
pygame.mixer.Sound.set_volume(splat, 0.6)

death = pygame.mixer.Sound('death.wav')
pygame.mixer.Sound.set_volume(death, 0.7)

def game():
    #SpeechVolume = 1
## Delay time variables for debugging (Sped up)
#     dTimeS = 0.5
#     dTimeL = 1
## Delay time variables for story flow timing
    dTimeS = 4
    dTimeL = 8   
## Prompt user for name    
    name = input("\n\nPlease enter your name:\n")
    name = name.upper()
## Music starts (1 loop total)
    pygame.mixer.music.set_volume(0.4)
    pygame.mixer.music.load('muzic3a.mp3')
    pygame.mixer.music.play(0)  
## JOKE if dylan tries the game    
    if name == 'DYLAN':             ###--JOKE CODE--TAKE OUT B4 SUBMITTING 
        name = 'Dill Pickle'        ###--JOKE CODE--TAKE OUT B4 SUBMITTING    
## Proper capitalization for user name 
    name = name.capitalize()
## Welcome message
    time.sleep(5)
    print("\nWelcome, %s\n\n"% name)
    welcome = pygame.mixer.Sound('1welcome.ogg')
    welcome.play()
    time.sleep(1.33)
    to = pygame.mixer.Sound('2to.ogg')
    to.play()
    print("     to\n\n")
    time.sleep(1.33)
    print("Super Fun Adventure Game!!! \n")
    superFun = pygame.mixer.Sound('3super.ogg')
    superFun.play()
    time.sleep(11)
## Loop to print multiple blank lines to blank console window before game starts
    for x in range (20):
        print("\n")
## Ambience starts (infinite loop)    
    pygame.mixer.music.set_volume(0.6)
    pygame.mixer.music.load('ambience.mp3')
    pygame.mixer.music.play(-1)
    time.sleep(dTimeL)
## Game begins
    print("You awaken on the floor of a stone room...\n")
    you = pygame.mixer.Sound('4you.ogg')
    you.play()
    time.sleep(dTimeS)
    print("You have no idea how you got here...\n")
    youHave = pygame.mixer.Sound('5have.ogg')
    youHave.play()
    time.sleep(dTimeS)
## Prompt user for a choice 
    whatDo = pygame.mixer.Sound('6what.ogg')
    whatDo.play()
    choice1 = input("What do you do?\n1 - Look around\n2 - Close your eyes and hope this is only a dream\n")
    
## Determine if user chose option '2'
    if choice1 == '2':
        print("\nYou close your eyes and count to three....\n")
        youClose = pygame.mixer.Sound('7you.ogg')
        youClose.play()
        time.sleep(3)
## For loop for text to count to 3        
        for x in range(3):
            print(x+1)
            time.sleep(0.5)
            print("\n...\n")
            time.sleep(0.5)
        
        print("You open your eyes...\n")
        youOpen = pygame.mixer.Sound('8you.ogg')
        youOpen.play()
        time.sleep(dTimeS)
        print("This is definitely NOT a dream.\n")
        this = pygame.mixer.Sound('9this.ogg')
        this.play()
        time.sleep(dTimeS+1)
## Storyline continues   
    print("\nYou look around...\n")
    youLook = pygame.mixer.Sound('10you.ogg')
    youLook.play()
    time.sleep(dTimeS)
    print("There are no doors or windows in the room.\n")
    there = pygame.mixer.Sound('11there.ogg')
    there.play()
    time.sleep(dTimeS)
    print('"How did I get here??!!"\n')
    how = pygame.mixer.Sound('12how.ogg')
    how.play()
    time.sleep(dTimeS)
    print("The north wall has a button labelled 'X'.\n")
    buttonX = pygame.mixer.Sound('13x.ogg')
    buttonX.play()
    time.sleep(dTimeS)
    print("The south wall has a button labelled 'O'.\n")
    buttonO = pygame.mixer.Sound('14o.ogg')
    buttonO.play()
    time.sleep(dTimeS)
    
## Prompt user for a choice
    which = pygame.mixer.Sound('15which.ogg')
    which.play()
    choice2 = input("Which button do you choose?\n1 - X\n2 - O\n")
    
## Determine if user chose option '1'
    if choice2 == '1':
## Stop ambience audio file 
        pygame.mixer.music.stop()
## Print actions and play related sound effects        
        print("The wall opens...\n")
        opens = pygame.mixer.Sound('16wall.ogg')
        opens.play()
        wall.play()
        time.sleep(4)
        
        print("Inside the wall is a glowing portal...\n")
        inside = pygame.mixer.Sound('17inside.ogg')
        inside.play()
        time.sleep(2)
        hum.play()
        time.sleep(8)
        
        
        print("You step into the portal...\n")
        youStep = pygame.mixer.Sound('18you.ogg')
        youStep.play()
        time.sleep(2)
        hum.stop()
        whoosh.play()
        time.sleep(3)
        morning.play()
        time.sleep(4)
        
        print("You wake up in your bed...\n")
        youWake = pygame.mixer.Sound('19you.ogg')
        youWake.play()
        
        time.sleep(4)
        #morning.stop()
## For loop to generate some dotted lines to add dramatic effect   
        for x in range(3):
            print("...\n")
            time.sleep(1)
            
        print("Was it really just a dream after all???\n")
        wasIt = pygame.mixer.Sound('20was.ogg')
        wasIt.play()
## Determine if user chose anything other than option '1'
    if choice2 != '1':
## Stop ambience audio file 
        pygame.mixer.music.stop()
## Print actions and play related sound effects  
        print("\nThe floor opens...\n")
        floorOpen = pygame.mixer.Sound('21floor.ogg')
        floorOpen.play()
        floor.play()
        time.sleep(4)
        
#         print("You fall...\n")
#         youFall = pygame.mixer.Sound('22you.ogg')
#         youFall.play()
        fall.play()
        time.sleep(1)
        
        splat.play()
        time.sleep(2)
        splat.stop()  
        time.sleep(1)
## Play game over sound
        print("You died!!")
        youDied = pygame.mixer.Sound('23you.ogg')
        youDied.play()
        time.sleep(1)
        death.play() 
        
    time.sleep(4)
## Load music for end of game(1 loop total)
    pygame.mixer.music.set_volume(0.4)
    pygame.mixer.music.load('muzic3a.mp3')
    pygame.mixer.music.play(0)
## Print Credits & Thank you/Replay message  
    time.sleep(2.5)
    print("\nThank you for playing\n")
    thank = pygame.mixer.Sound('24thank.ogg')
    thank.play()
    time.sleep(2)
    print("\nCreated by: Corey\n")
    time.sleep(4.5)
    print("\nSound Design by: Corey\n")
    time.sleep(4.5)
    print("\nMusic by: Corey\n")
    time.sleep(4.5)
    print("Press F5 to play again")

if __name__=='__main__':
    game()
    
    
    
    