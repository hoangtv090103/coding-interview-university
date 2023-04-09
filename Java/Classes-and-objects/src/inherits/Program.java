package inherits;

import inherits.Dog;
import inherits.Duck;
import inherits.Animal;

public class Program {

    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.sound();
        animal = new Dog();
        animal.sound();
        animal = new Cat();
        animal.sound();
        animal = new Duck();
        animal.sound();
    }
}