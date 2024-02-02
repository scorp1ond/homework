import random

class Cat:
    def __init__(self):
        self.name = name
        self.alive = True
        self.sleep = 50
        self.food = 50
        self.happiness = 50
    def to_sleep(self):
        self.sleep += 5
        self.happiness += 0.5
        self.food -= 3

    def to_eat(self):
        self.food += 3
        self.sleep -= 0.5
        self.happiness += 1

    def to_walk(self):
        self.food -= 1
        self.happiness += 5
        self.sleep -= 2

    def is_alive(self):
        if self.food <= 0:
            print("I'm starving")
            self.alive = False
        elif self.sleep <= 0:
            print("you don't give me enough sleep")
            self.alive = False
        elif self.happiness <= 0:
            print("let me do something")
            self.alive = False
    def end_of_the_day(self):
        print(f"sleep = {self.sleep}")
        print(f"food = {self.food}")
        print(f"happiness = {self.happiness}")
    def live(self,day):
        d = "Day" + str(day) + "of" + self.name + "life"
        print(f"{day:=^50}")
        live_cube = random.randint(1, 3)
        if live_cube == 1:
            self.to_walk()
        elif live_cube == 2:
            self.to_sleep()
        elif live_cube == 3:
            self.to_eat()

        self.end_of_the_day()
        self.is_alive()

name = input("input name")

for i in range(1, 366):
    if name.alive == False:
        break
    name.live(i)






