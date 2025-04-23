import pygame
import pygame.image
import threading
from pygame import mixer
from mosquito import create_mosquitoes
from racket import Racket
from hand_trackingmp import track_hand_position

racket = Racket()
#hand_tracker = HandTracker()
GAME_TIME = 60  # Game duration in seconds
TIMER_EVENT = pygame.USEREVENT + 1
score_value=0

#Initialize pygame
pygame.init()
#Create screen and icon
screen1 = pygame.display.set_mode((1080, 600))
pygame.display.set_caption("Mosquito Killer")
#Background
bgrndimag=pygame.image.load('backgroundf.png')
font = pygame.font.Font('freesansbold.ttf',32)

def show_score():
    score=font.render('Score:'+str(score_value),True,(255,255,255))
    screen1.blit(score,(10, 10))

over_font=pygame.font.Font('freesansbold.ttf',64)
def game_over_text():
    over=over_font.render('GAME OVER!',True,(255,255,255))
    screen1.blit(over,(350,300))
'''
def track_hand_position():
    while hand_data['running']:
        hand_position, is_fist = get_hand_position()
        
        if hand_position is not None:  # Only update if a valid hand position is found
            hand_data['position'] = hand_position
            hand_data['is_fist'] = is_fist
        
        time.sleep(0.03) '''  

#Hand Tracking thread
hand_data = {'position': None, 'is_fist': False, 'running': True, 'positions': []}
hand_thread = threading.Thread(target=track_hand_position, args=(hand_data,))
hand_thread.start()

mosquitoes=create_mosquitoes(6,1080,600)
clock= pygame.time.Clock()

pygame.time.set_timer(TIMER_EVENT,1000)
timeleft = GAME_TIME

running = True
while running:
    #RGB- Red,Green,Blue 
    screen1.fill((0,0,0))
    screen1.blit(bgrndimag,(0,0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False             
        if event.type == TIMER_EVENT:
            timeleft-=1
            if timeleft <= 0:
                running=False

    if hand_data['position']:
        racket.move(hand_data['position'])

    #Kill mosquitos when hand is closed
    for mosquito in mosquitoes:
        if hand_data['is_fist'] and mosquito.is_hit_by_racket(racket.rect):
            hit_sound=mixer.Sound("zap.wav")
            hit_sound.play()
            mosquito.spawn() # Kill mosquito
            score_value+=1

    for mosquito in mosquitoes:
        mosquito.move()
        mosquito.draw(screen1)

    racket.draw(screen1)
    timer_text= font.render(f"Time Left: {timeleft}s", True, (255, 255, 255))
    screen1.blit(timer_text, (500, 10))

    show_score()
    pygame.display.update()
    clock.tick(80)

#Stop hand tracking thread
hand_data['running'] = False
hand_thread.join()

game_over_text()
pygame.display.update()
pygame.time.delay(1000)
pygame.quit()












#FOR FULLSCREEN(NOT NECESSARY)
#screen_info = pygame.display.Info()  # Get screen resolution
#screen_width, screen_height = screen_info.current_w, screen_info.current_h

#screen1 = pygame.display.set_mode((screen_width, screen_height), pygame.FULLSCREEN)
#bgrndimag = pygame.transform.scale(pygame.image.load('backgroundf.png'), (screen_width, screen_height))