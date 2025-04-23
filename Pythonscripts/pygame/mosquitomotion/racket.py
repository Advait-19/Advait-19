import pygame

class Racket:
    def __init__(self):
        self.image = pygame.image.load('racket.png')
        self.size = (70, 70)
        self.image = pygame.transform.scale(self.image, self.size)
        self.rect = self.image.get_rect()  # Initial position
        self.positions=[]
        self.screen_width = 1080
        self.screen_height = 600

    def move(self, hand_position):
        x, y = hand_position
        
        # Ensure racket stays within screen boundaries
        x = max(0, min(x, self.screen_width - self.rect.width))
        y = max(0, min(y, self.screen_height - self.rect.height))
        
        self.rect.topleft = (x, y)

    def draw(self, screen):
        screen.blit(self.image, self.rect)
        #pygame.draw.rect(screen, (0,255,0), self.rect, 2)

    