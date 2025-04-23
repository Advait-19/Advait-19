class Car(object):
    colour='white'

    def __init__(self,mileage,maxspeed):
        self.mileage=mileage
        self.maxspeed=maxspeed
        self.seat_no=None

    def seating(self,seat_no):
        self.seat_no=seat_no

    def displayall(self):
        print('Properties of the vehicle:')
        print("Mileage of car:",self.mileage)
        print('Max speed of car:',self.maxspeed)
        print("Colour of the car:",self.colour)
        print('Seating capacity:',self.seat_no)

Audi=Car(200,50000)
Buggati=Car(180,75000)
Audi.seating(5)
Buggati.seating(4)
Audi.displayall()
Buggati.displayall()
    
