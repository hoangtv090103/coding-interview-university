public class Interfaces {
    public static void main(String[] args) {
        Bird bird = new Bird();
        bird.eat();
        bird.fly();
    }
}

interface IFlyable {
    void fly();
}

interface IEatable {
    void eat();
}

class Bird implements IFlyable, IEatable {
    @Override
    public void fly() {
        System.out.println("Bird flying");
    }

    @Override
    public void eat() {
        System.out.println("Bird eats");
    }
}