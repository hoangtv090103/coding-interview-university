package inherits;

class Animal {
    public void sound() {
        System.out.println("some sound");
    }
}

//Lớp Dog kế thừa Animal
class Dog extends Animal {
    public void sound() {
        System.out.println("bow bow");
    }
}

//Lớp Cat kế thừa Animal
class Cat extends Animal {
    public void sound() {
        System.out.println("meow meow");
    }
}

//Lớp Duck kế thừa Animal
class Duck extends Animal {
    public void sound() {
        System.out.println("quack quack");
    }
}