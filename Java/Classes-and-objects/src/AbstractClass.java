public class AbstractClass {
    public static void main (String[] args)
    {
        // Khi đó đối tượng Cat có thể được tạo và gọi hàm makeSound()
        Animal a = new Cat();
        a.makeSound();
    }
}

abstract class Animal {
    public abstract void makeSound();
}

class Cat extends Animal {
    @Override
    public void makeSound()
    {
        System.out.println("Meow meow");
    }
}
