import random


class Student:

    def __init__(self, name):
        self.name = name
        self.gladness = 50
        self.progress = 0
        self.money = 5
        self.alive = True

    def to_study(self):
        print("time to study")
        self.progress += 0.15
        self.gladness -= 3

    def to_sleep(self):
        print("i will sleep")
        self.gladness += 3

    def to_chill(self):
        print("rest time")
        self.gladness += 5
        self.progress -= 0.1
        self.money -= 3

    def to_work(self):
        print("time to work")
        self.gladness -= 1.5
        self.money += 5
    def is_alive(self):
        if self.progress < -0.5:
            print("Cast out...")
            self.alive = False
        elif self.gladness <= 0:
            print("depression...")
            self.alive = False
        elif self.progress > 5:
            print("passed externally...")
            self.alive = False
        elif self.money <= 0:
            print("you're homeless now sorry")
            self.alive = False

    def end_of_day(self):
        print(f"Gladness = {self.gladness}")
        print(f"Progress = {self.progress}")
        print(f"money = {self.money}")

    def live(self, day):
        d = "Day" + str(day) + "of" + self.name + "life"
        print(f"{day:=^50}")
        live_cube = random.randint(1, 4)
        if live_cube == 1:
            self.to_study()
        elif live_cube == 2:
            self.to_sleep()
        elif live_cube == 3:
            self.to_chill()
        elif live_cube == 4:
            self.to_work()

        self.end_of_day()
        self.is_alive()


name = input("input name")
nick = Student(name=name)
for i in range(1, 366):
    if nick.alive == False:
        break
    nick.live(i)