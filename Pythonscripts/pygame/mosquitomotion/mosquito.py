import pygame
import random

class Mosquito:
    def __init__(self, screen_width, screen_height):
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.spawn()
    
    def spawn(self):
        self.image = pygame.image.load('mosquito.png')
        self.size = random.randint(20, 45)  # Random mosquito size
        self.image = pygame.transform.scale(self.image, (self.size, self.size))
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(0, self.screen_width - self.rect.width)
        self.rect.y = random.randint(0, self.screen_height - self.rect.height)
        self.speed_x = random.uniform(1.5, 3)  # Random speed
        self.speed_y = random.uniform(1.5, 3)
        self.alive = True  # Status of mosquito

    def move(self):
        if self.alive:
            self.rect.move_ip(self.speed_x, self.speed_y)
            if self.rect.left < 0 or self.rect.right > self.screen_width:
                self.speed_x *= -1  # Reverse direction on boundary
            if self.rect.top < 0 or self.rect.bottom > self.screen_height:
                self.speed_y *= -1

    def draw(self, screen):
        if self.alive:
            screen.blit(self.image, (self.rect.x, self.rect.y))
            #pygame.draw.rect(screen, (255,0,0), self.rect, 2)

    def is_hit_by_racket(self, racket_rect):
        #if clicked:
            #print(f"Mosquito at ({self.x}, {self.y}) clicked!")  # Debugging
        return self.rect.colliderect(racket_rect)
        
# Function to create multiple mosquitoes
def create_mosquitoes(num, screen_width, screen_height):
    return [Mosquito(screen_width, screen_height) for _ in range(num)]