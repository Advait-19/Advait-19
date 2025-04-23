import pygame
import random
import math
from pygame import mixer

#Initialize pygame
pygame.init()
#Create screen and icon
screen = pygame.display.set_mode((800,600))
pygame.display.set_caption("Space Invader")
icon=pygame.image.load('spaceship.png')
pygame.display.set_icon(icon)

#Background image
bgrnd_imag=pygame.image.load('background.png')
#Background music
mixer.music.load('background.wav')
mixer.music.play(-1)

#Player
player_img=pygame.image.load('player.png')
playerX=370
playerY=480
player_change=0
#Enemy
enemy_img=[]
enemyX=[]
enemyY=[]
enemy_change=[]
num_of_enemies=6
for i in range(num_of_enemies):
    enemy_img.append(pygame.image.load('alien.png'))
    enemyX.append(random.randint(0,735))
    enemyY.append(random.randint(0,10))
    enemy_change.append(0.5)

#Bullet
bullet_img=pygame.image.load('bullet.png')
bulletX=0
bulletY=480
bullet_change=5
bullet_state='ready'

#Score
score_value=0
font=pygame.font.Font('freesansbold.ttf',32)
textX=10
textY=10

#Game Over
over_font=pygame.font.Font('freesansbold.ttf',64)

def show_score(x,y):
    score=font.render('Score:'+str(score_value),True,(255,255,255))
    screen.blit(score,(x,y))

def game_over_text():
    over=over_font.render('GAME OVER!',True,(255,255,255))
    screen.blit(over,(200,250))

def player(x,y):
    screen.blit(player_img,(x,y))

def enemy(x,y,i):
    screen.blit(enemy_img[i],(x,y))

def fire_bullet(x,y):
    global bullet_state
    bullet_state='fire'
    screen.blit(bullet_img,(x+16,y+10))

def isCollision(eX,eY,bX,bY):
    distance=math.sqrt(math.pow((eX-bX),2) + (math.pow((eY-bY),2)))
    if distance<27:
        return True

#Game Loop
running=True
while running:
    #RGB- Red,Green,Blue 
    screen.fill((0,0,25))
    screen.blit(bgrnd_imag,(0,0))

    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            running= False

        #if keystroke is pressed check whether it's right or left
        if event.type==pygame.KEYDOWN:
            #print('Keystroke is pressed')
            if event.key==pygame.K_LEFT:
                player_change= -2
            if event.key==pygame.K_RIGHT:
                player_change= 2
            if event.key==pygame.K_SPACE:
                if bullet_state == 'ready':
                    bullet_sound= mixer.Sound('laser.wav')
                    bullet_sound.play()
                    bulletX=playerX
                    fire_bullet(bulletX,bulletY)   
        if event.type==pygame.KEYUP:
            if event.key==pygame.K_LEFT or event.key==pygame.K_RIGHT:
                player_change= 0

    for i in range(num_of_enemies):
        enemyY[i]+=enemy_change[i]
        if enemyY[i]<= 0:
            enemyY[i]+=enemy_change[i]
        elif enemyY[i]>= 440:
            for j in range(num_of_enemies):
                enemyY[j]=1000
            game_over_text()
            break
        
        collision=isCollision(enemyX[i],enemyY[i],bulletX,bulletY)
        if collision:
            collsion_sound=mixer.Sound('explosion.wav')
            collsion_sound.play()
            bulletY=480
            bullet_state='ready'
            enemyX[i]= random.randint(0,735)
            enemyY[i]= random.randint(0,10)
            score_value+=1

        enemy(enemyX[i],enemyY[i],i)

    #Check boundaries of spaceship
    playerX+=player_change
    if playerX<= 0:
        playerX=0
    elif playerX>= 736:
        playerX=736

    if bulletY<=0:
        bulletY=480
        bullet_state='ready'

    if bullet_state == 'fire':
        fire_bullet(bulletX,bulletY)
        bulletY-=bullet_change

    player(playerX,playerY)
    show_score(textX,textY)
    pygame.display.update()
 
pygame.quit() 