class Animal:
    num_cells = "multicellular"
    eu_pro = "eukaryotic"

    def to_grow(self):
        pass

class Bird(Animal):
    feathers = "yes"
    beak = "yes"

    def lay_eggs(self):
        pass

class Penguin(Bird):
    can_fly = "no"

    def to_swim(self):
        print(f"Penguins are {self.num_cells} and they are birds but can't fly although they sre great swimers")

penguin = Penguin()
penguin.to_swim()












