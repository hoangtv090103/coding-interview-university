public interface IAnimal {
    // Tất cả các phương thức trong interface phải là phương thức abstract (trừu tượng) hoặc phương thức default (mặc định).
    // Tất cả các biến trong interface đều được trình biên dịch hiểu là các hằng số.
    // Từ khóa abstract có thể không cần khi khai báo phương thức trừu tượng, tương tự từ khóa static final không cần khi khai báo hằng số.
    default void move() {
        System.out.println("Moving");
    }
    void sound();
    int numberOfAnimal = 0;
}